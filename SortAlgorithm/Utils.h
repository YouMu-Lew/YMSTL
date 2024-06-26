#pragma once
#include <random>
#include <chrono>
#include <iostream>

namespace ymstl {
	template <typename T>
	static void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	const static auto less = [](auto _a, auto _b)->bool {return _a < _b; };

	// return a random integer between [left,right]
	int randomInt(int left = 0, int right = 10) {
		std::random_device rd;// 非确定性随机数生成器
		std::mt19937 mt_r(rd());// 使用Mersenne twister算法随机数生成器
		std::uniform_int_distribution<> distrib(left, right); // 随机均匀分布[left,right]区间
		return distrib(mt_r);
	}

	class Timer {
	private:
		std::string name;
		std::chrono::steady_clock::time_point _startTimePoint;

		void Stop() {
			auto endTimePoint = std::chrono::steady_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimePoint).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

			auto duration = end - start;
			double ms = duration * 0.001;
			if (name != "")
				std::cout << "Timer " << name << ": ";
			std::cout << duration << "us(" << ms << "ms)" << std::endl;
		}
	public:
		Timer() :name("") {
			_startTimePoint = std::chrono::steady_clock::now();
		}

		Timer(std::string name) :name(name) {
			_startTimePoint = std::chrono::steady_clock::now();
		}

		~Timer() {
			Stop();
		}
	};
}