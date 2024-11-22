#pragma once

#include <functional>
#include <mutex>
#include <queue>
#include <future>
#include <type_traits>

namespace ymstl {
	class thread_pool {
	public:
		thread_pool(const size_t n) {
			// 构造大小为 n 的线程池
			workers_.reserve(n);
			for(size_t i = 0; i < n; ++i) {
				workers_.emplace_back([this] {
					while (true) {
						// 死循环
						// 根据任务队列是否为空或者线程池是否处于停止状态
						// 选择执行的操作
						std::unique_lock lock{ task_mutex_ };
						// 任务队列不为空或者线程池停止时继续执行
						cv_.wait(lock, [this] {return !this->tasks_.empty() || this->stop_; });
						if (this->stop_) {
							// 线程池停止时，退出死循环
							return;
						}
						auto task = std::move(tasks_.front());
						tasks_.pop();
						task();
					}
					});
			}
		}

		~thread_pool() {
			for(auto& worker:workers_) {
				if(worker.joinable())
					worker.join();
			}
			stop_ = true;
			std::lock_guard lk{ task_mutex_ };
			while (!tasks_.empty()) { tasks_.pop(); }
		}

		template<typename Func, typename... Args, typename ReturnType = std::invoke_result_t<Func(Args...)>>
		ReturnType enqueue(Func&& func,Args&&... args){

			auto task = std::make_shared<std::packaged_task<ReturnType()>>(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
			auto res = task->get_future();
			{
				std::lock_guard lock{ task_mutex_ };
				tasks_.emplace([task] {(*task)(); });	// 调用 std::packaged_task 中 operator() 方法，等同于 task->operator()()
			}
			cv_.notify_one();
			return res;
		}

	private:
		std::mutex task_mutex_;
		std::queue<std::function<void()>> tasks_;
		std::vector<std::thread> workers_;
		std::condition_variable cv_;
		bool stop_ = false;
	};
}