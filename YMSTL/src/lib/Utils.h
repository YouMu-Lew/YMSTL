#ifndef _YMSTL_UTILS_H
#define _YMSTL_UTILS_H

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
		std::random_device rd;// Use a random device to generate a seed
		std::mt19937 mt_r(rd());// Use the Mersenne Twister algorithm to generate random numbers
		std::uniform_int_distribution<> distrib(left, right); // Create a uniform integer distribution within the range [left, right]
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

	template<class Ty>
	void printVector(const Ty& v, std::string pre = "") {
		std::cout << pre << std::endl;
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		return;
	}
}
#endif // !_YMSTL_UTILS_H
