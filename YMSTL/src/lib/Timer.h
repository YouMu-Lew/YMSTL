#pragma once

#include <iostream>
#include <chrono>
#include <string>

namespace ymstl {
	template<typename Period = std::chrono::microseconds>
		requires std::_Is_specialization_v<Period, std::chrono::duration>;
	class timer {
	public:
		explicit timer(const std::string& name = "Timer") :name_(name), start_point_(std::chrono::steady_clock::now()) {
			std::cout << "Timer<" << name_ << "> start\n";
		}

		~timer() {
			split();
			std::cout << "Timer<" << name_ << "> end\n";
		}

		timer(const timer&) = delete;
		timer(timer&&) = delete;

		timer& operator=(const timer&) = delete;
		timer& operator=(timer&&) = delete;

		void split() const{
			const auto end_point = std::chrono::high_resolution_clock::now();
			const auto duration = std::chrono::duration_cast<Period>(end_point - start_point_);
			std::cout << "Timer<" << name_ << "> taken: " << duration << '\n';
		}
	private:
		const std::string name_;
		std::chrono::time_point<std::chrono::steady_clock> start_point_;
	};
}
