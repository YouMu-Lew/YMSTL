#pragma once

#include <iostream>
#include <chrono>
#include <string>

namespace ymstl {
	class timer {
	public:
		timer(const std::string& name = "Timer"):name_(name),start_point_(std::chrono::high_resolution_clock::now()){
			std::cout << "Timer<" << name_ << "> start\n";
		}

		~timer() {
			split();
			std::cout << "Timer<" << name_ << "> end\n";
		}

		void split() const{
			const auto end_point = std::chrono::high_resolution_clock::now();
			const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_point - start_point_);
			std::cout << "Timer<" << name_ << "> taken: " << duration << '\n';
		}
	private:
		std::string name_;
		std::chrono::time_point<std::chrono::high_resolution_clock> start_point_;
	};
}
