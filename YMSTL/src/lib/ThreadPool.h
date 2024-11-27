#pragma once

#include <functional>
#include <mutex>
#include <queue>
#include <future>
#include <type_traits>

#ifdef _DEBUG
#include <iostream>
#endif

namespace ymstl {
	class thread_pool {
	public:
		thread_pool(const unsigned int n = 5):n_(n) {
#ifdef _DEBUG
			std::cout << "构造 thread_pool(" << n_ << ")\n";
#endif
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
#ifdef _DEBUG
			std::cout << "析构 thread_pool(" << n_ << ")\n";
#endif

			stop_ = true;
			cv_.notify_all();
		}

		thread_pool(const thread_pool&) = delete;
		thread_pool(thread_pool&&) = delete;

		thread_pool& operator=(const thread_pool&) = delete;
		thread_pool& operator=(thread_pool&&) = delete;

		template<typename Func, typename... Args, typename ReturnType = std::invoke_result_t<Func&&, Args&&...>>
			requires std::invocable<Func, Args...>
		std::future<ReturnType> enqueue(Func&& func,Args&&... args){

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
		const unsigned int n_;
		std::mutex task_mutex_;
		std::queue<std::function<void()>> tasks_;
		std::vector<std::jthread> workers_;
		std::condition_variable cv_;
		bool stop_ = false;
	};
}