#pragma once

#include <random>
#include <iostream>

namespace ymstl {
	template <typename T>
	static void swap(T& a, T& b) noexcept {
		T temp = a;
		a = b;
		b = temp;
	}

	const static auto less = [](auto a, auto b)->bool {return a < b; };

	// return a random integer between [left,right]
	inline int random_int(const int left = 0, const int right = 10) {
		std::random_device rd;// Use a random device to generate a seed
		std::mt19937 mt_r(rd());// Use the Mersenne Twister algorithm to generate random numbers
		std::uniform_int_distribution<> distrib(left, right); // Create a uniform integer distribution within the range [left, right]
		return distrib(mt_r);
	}

	template<class Ty>
	void print_vector(const Ty& v, const std::string& pre = "") {
		std::cout << pre << '\n';
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << '\n';
	}
}
