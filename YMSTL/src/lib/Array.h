#pragma once
namespace ymstl {
	template<typename T, size_t S>
	class Array {
	public:
		constexpr size_t size() { return S; }

		T& operator[](size_t index) { return _data[index]; }
		const T& operator[](size_t index) const { return _data[index]; } // 确保被常量引用调用时，能正常访问

		T* data() { return _data; }
		const T* data() const { return _data; }
	private:
		T _data[S];
	};
};