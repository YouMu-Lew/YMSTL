#pragma once
namespace ymstl {
	template<typename T>
	class Vector {
	public:
		Vector() {
			_maxSize = 2;
			_left = new T[_maxSize];
			_right = _left;
		}

		T* begin() { return _left; }
		T* end() { return _right; }

		constexpr size_t size() const { return _size; }

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
				return *_left;
			}
			return *(_left + index);
		}

		void push_back(T a) {
			if (_size < _maxSize) {
				*_right = a;
				_right++;
				_size++;
			}
			else {
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

		T pop_back() {
			if (_size > 0) {
				_right--;
				_size--;
				return *_right;
			}
		}
	private:
		T* _left, * _right;
		size_t _size = 0,_maxSize = 1;
	};
}