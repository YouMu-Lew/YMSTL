#include <chrono>
#include <iostream>

#include "ThreadPool.h"
#include "Timer.h"

using namespace std::chrono_literals;

int times(const int a, const int b) {
	//std::this_thread::sleep_for(0.5s);
	return a * b;
}

int main() {
	ymstl::thread_pool thread_pool{ 1 };
	{
		ymstl::timer timer("thread_pool");
		for (int i = 0; i < 10000; ++i) {
			auto res = thread_pool.enqueue(times, i, i);
			//std::cout << "result = " << res.get() << std::endl;
		}
	}
	{
		ymstl::timer timer("normal");
		for (int i = 0; i < 10000; ++i) {
			auto res = times(i,i);
			//std::cout << "result = " << res << std::endl;
		}
	}
	//std::cin.get();
}