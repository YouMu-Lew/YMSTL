#pragma once

#include <iostream>
#include <chrono>
#include <string>

namespace ymstl {
	/**
	 * @brief Timer 类模板，用于测量代码块的执行时间。
	 *
	 * @tparam Period 时间单位，默认为 std::chrono::microseconds（微秒）。
	 *
	 * @requires Period 必须是 std::chrono::duration 的特化类型。
	 */
	template <typename Period = std::chrono::microseconds>
		requires std::chrono::_Is_duration_v<Period>
	class timer {
	public:
		//static_assert(std::chrono::_Is_duration_v<Period>, "Period should be duration.");

		explicit timer(const std::string& name = "Timer")
			: name_(name), start_point_(std::chrono::steady_clock::now()) {
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

		void split() const {
			// 计时一次
			const auto end_point = std::chrono::steady_clock::now();
			const auto duration = std::chrono::duration_cast<Period>(end_point - start_point_);
			std::cout << "Timer<" << name_ << "> taken: " << duration << '\n';
		}
	private:
		const std::string name_;
		std::chrono::time_point<std::chrono::steady_clock> start_point_;
	};
}
