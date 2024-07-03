// #include <algorithm>
// #include <array>
#include <cstring>
#include <iostream>
// #include <string>
#include <vector>
// #include "./MySTL/Array.h"
#include "./MySTL/Vector.h"
// #include "./SortAlgorithm/Sort.h"
//
using namespace ymstl;

class String {
public:
	String() { printf("String is Created default\n"); }

	String(const char* str) {
		printf("String is Created\n");
		_size = strlen(str);
		_data = new char[_size];
		memcpy(_data, str, _size);
	}

	String(const String& other) {
		printf("String is Copied\n");
		_size = other._size;
		_data = new char[_size];
		memcpy(_data, other._data, _size);
	}

	String(String&& other) noexcept {
		printf("String is Moved\n");
		_size = other._size;
		_data = other._data;

		// It's very important!
		// Setting to `nullptr` ensures the destructor won't release the
		// original memory
		other._data = nullptr;
		other._size = 0;
	}

	String& operator=(String&& other) noexcept {
		printf("String is Moved by `operator=`\n");
		delete[] _data;  // If not done, it might lead to memory leaks.
		_size = other._size;
		_data = other._data;
		other._data = nullptr;
		other._size = 0;

		return *this;
	}

	String& operator=(const String& other) noexcept {
		printf("String is Copied by `operator=`\n");
		delete[] _data;
		_size = other._size;
		_data = new char[_size];
		for (size_t i = 0; i < _size; i++) {
			_data[i] = other._data[i];
		}

		return *this;
	}

	~String() {
		printf("String is Destroyed\n");
		delete[] _data;
		_data = nullptr;
	}

	size_t size() const { return _size; }

	void print() {
		for (size_t i = 0; i < _size; i++)
			printf("%c", _data[i]);
		printf("\n");
	}

private:
	size_t _size = 0;
	char* _data = nullptr;
};

class Entity {
public:
	Entity() = default;
	Entity(const String& name) : _name(name) {}

	Entity(String&& name) : _name(std::move(name)) {}

	void printName() { _name.print(); }

private:
	String _name;
};

int main() {
<<<<<<< HEAD
	// for test
=======
	std::vector<int> v1;
>>>>>>> 91e314d (test(main.cpp): Add test cases to verify `Vector::iterator`)

	Vector<int> v2;
	v2.emplace_back(1);
	v2.emplace_back(2);
	v2.emplace_back(2);
	v2.emplace_back(3);
	v2.emplace_back(3);
	v2.emplace_back(3);
	v2.emplace_back(3);

	std::cout << "\nprint by for loop using int i\n";
	for (int i = 0; i < v2.size(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << "\nprint by for loop using int i\n";

	std::cout << "\nprint by for loop using iterator\n";
	for (Vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nprint by for loop using iterator\n";

	std::cout << "\nprint by for loop using auto\n";

	for (auto i : v2){
		std::cout << i << " ";
	}
	std::cout << "\nprint by for loop using auto\n";

	//std::cin.get();
}
