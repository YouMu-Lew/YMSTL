#pragma once
namespace ymstl {
	template<typename T>
	class Vector {
	public:
		Vector() {
			_left = new T[1];
			_maxSize = 1;
			_right = _left;
		}

		T* begin() { return _left; }
		T* end() { return _right; }

		constexpr size_t size() { return _size; }

		const T& operator[](size_t index) const {
			if (!(index < _size)) {
				throw std::out_of_range("index out of range");
				return *_left;
			}
			return *(_left + index);
		}

		T& operator[](size_t index) {
			if (!(index < _size)) {
				throw std::out_of_range("index out of range");
				return _data[0];
			}
			return _data[index];
		}

		void push_back(T a) {
			if (_size < _maxSize) {
				*(_right - 1) = a;
				_right++;
				_size++;
			}
			else {
				std::cout << "bigger!";
				_maxSize *= 2;
				T* newData = new T[_maxSize];
				for (size_t i = 0; i < _size; i++) {
					newData[i] = *(_left + i);
				}
				newData[_size] = a;
				_size++;
				_left = newData;
				_right = _left + _size;
			}
		}

	private:
		size_t _size = 0;
		size_t _maxSize = 1;
		T* _left, * _right;
	};
}