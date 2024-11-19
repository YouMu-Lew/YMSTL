#pragma once
namespace ymstl {
	template<typename T, size_t S>
	class Array {
	public:
		constexpr size_t size() { return S; }

		T& operator[](size_t index) { return _data[index]; }
		const T& operator[](size_t index) const { return _data[index]; } // ȷ�����������õ���ʱ������������

		T* data() { return _data; }
		const T* data() const { return _data; }
	private:
		T _data[S];
	};
};