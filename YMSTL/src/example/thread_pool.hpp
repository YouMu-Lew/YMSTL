#pragma once

#include <vector>

#include "ThreadPool.h"
#include "Timer.h"
#include "Utils.h"

inline int fibonacci(const int n) {
	if (n <= 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

inline void test_thread_pool(const int task_num = 30, const int thread_num = 5) {
	std::cout << "任务数：" << task_num << ", 线程池数：" << thread_num << '\n';
	std::vector<int> results{};
	results.reserve(task_num);
	{
	// 单线程基准
		ymstl::timer t1("单线程");
		for (int i = 0; i < task_num; ++i) {
			results.emplace_back(fibonacci(i));
		}
	}
	ymstl::print_vector(results);
	results.clear();

	{
		// 线程池
		ymstl::timer t2("线程池");
		ymstl::thread_pool thread_pool(thread_num);
		std::vector<std::future<int>> futures{};
		futures.reserve(task_num);
		for (int i = 0; i < task_num; ++i) {
			futures.emplace_back(thread_pool.enqueue(fibonacci,i));
		}
		for(auto& fut:futures) {
			results.emplace_back(fut.get());
		}
	}
	ymstl::print_vector(results);
	results.clear();
}