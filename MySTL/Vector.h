#pragma once
namespace ymstl {
	template <typename T>
	class Vector {
	public:
		Vector() { _reAllocate(2); }

		~Vector() {
			clear();
			::operator delete(_data, _capacity * sizeof(T));
		}

		T* begin() { return _data; }
		T* end() { return _data + _size; }

		constexpr size_t size() const { return _size; }

		const T& operator[](size_t index) const {
			// TODO it maybe a assert here
			if (!(index < _size)) {
				throw std::out_of_range("index out of range");
				return *_data;
			}
			return _data[index];
		}

		T& operator[](size_t index) {
			if (!(index < _size)) {
				throw std::out_of_range("index out of range");
				return *_data;
			}
			return _data[index];
		}

		void push_back(T&& element) {
			if (_size >= _capacity) {
				_reAllocate(_capacity + _capacity / 2);
			}
			printf("push_back a new element by move\n");
			new(&_data[_size++]) T(std::move(element));
		}

		void push_back(const T& a) {
			if (_size >= _capacity) {
				_reAllocate(_capacity + _capacity / 2);
			}
			printf("push_back a new element~\n");
			_data[_size++] = a;
		}

		template <class... Args>
		T& emplace_back(Args&&... args) {
			if (_size >= _capacity) {
				_reAllocate(_capacity + _capacity / 2);
			}
			printf("emplace_back a new element\n");
			/*
			// 在已分配的内存上使用指定参数构造对象，此处的 new 关键字不负责分内存分配，而是 placement new 语法
			// The `new` keyword in this context is not responsible for memory allocation; instead, it employs the `placement new` syntax to construct an object with specified parameters at already allocated memory. This operation takes place at the _size index of the _data array, where a T type object is instantiated using the arguments forwarded through `std::forward<Args>(args)...`.
			*/
			new(&_data[_size]) T(std::forward<Args>(args)...);
			return _data[_size++];
		}

		void pop_back() {
			if (_size > 0) {
				printf("pop_back a element\n");
				_data[--_size].~T();
			}
		}

		void clear() {
			if (_size == 0)
				return;
			for (size_t i = 0; i < _size; i++) {
				_data[i].~T();
			}
			_size = 0;
		}

		void print() {
			printf("------------------------\n");
			for (size_t i = 0; i < _size; i++) {
				std::cout << _data[i] << " ";
			}
			printf("\n------------------------\n");
		}

	private:
		void _reAllocate(size_t newCapacity) {
			printf("------------Start ReAllocating----------\n");
			// 1. allocate a new block of memory
			// 2. copy/move old elements into new block
			// 3. delete
			if (newCapacity < _size)
				_size = newCapacity;

			// allocate
			T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

			// copy/move
			for (size_t i = 0; i < _size; i++) {
				// 这里不能再用 = 赋值，使用 ::operator new 申请分配内存并没有调用 T 的构造函数，newBlock[i] 并不是一个 T 类型的值，需要调用 T 的构造函数
				// Cannot use assignment here, as using ::operator new for memory allocation does not invoke the constructor of T; thus, newBlock[i] is not a value of type T, requiring the constructor of T to be called.
				new(&newBlock[i]) T(std::move(_data[i]));
				_data[i].~T();
			}

			::operator delete(_data, _capacity * sizeof(T));

			_data = newBlock;
			newBlock = nullptr;
			_capacity = newCapacity;
			printf("--------------ReAllocated------------\n");
		}

	private:
		T* _data = nullptr;
		size_t _size = 0, _capacity = 0;
	};
}  // namespace ymstl