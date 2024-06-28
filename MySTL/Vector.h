#pragma once
namespace ymstl {
	template<typename T>
	class Vector {
	public:
		Vector() {
			_reAllocate(2);
		}

		T* begin() { return _data; }
		T* end() { return _data + _size; }

		constexpr size_t size() const { return _size; }

		const T& operator[](size_t index) const {
			if (!(index < _size)) {
				throw std::out_of_range("index out of range");
				return *_data;
			}
			return *(_data + index);
		}

		T& operator[](size_t index) {
			if (!(index < _size)) {
				throw std::out_of_range("index out of range");
				return *_data;
			}
			return *(_data + index);
		}

		void push_back(T&& a) {
			if (_size >= _capacity) {
				_reAllocate(_capacity + _capacity / 2);
				printf("push_back a new element~\n");
			}
			_data[_size++] = std::move(a);
		}

		T pop_back() {
			if (_size > 0) {
				_size--;
				return *(_data + _size);
			}
		}

		void print() {
			printf("------------------------\n");
			for (size_t i = 0; i < _size; i++) {
				std::cout << *(_data + i) << " ";
			}
			printf("\n------------------------\n");
		}

	private:
		void _reAllocate(size_t newCapacity) {
			printf("ReAllocated\n");
			// 1. allocate a new block of memory
			// 2. copy/move old elements into new block
			// 3. delete
			if (newCapacity < _size)
				_size = newCapacity;

			T* newBlock = new T[newCapacity];

			// cpoy
			for (size_t i = 0; i < _size; i++) {
				newBlock[i] = _data[i];
			}

			// del
			delete[] _data;
			_data = newBlock;
			/*newPointer = nullptr;*/
			_capacity = newCapacity;
		}

	private:
		T* _data = nullptr;
		size_t _size = 0, _capacity = 0;
	};
}