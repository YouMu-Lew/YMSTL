//#include <algorithm>
//#include <array>
#include <iostream>
//#include <string>
//#include <vector>
//#include "./MySTL/Array.h"
#include "./MySTL/Vector.h"
//#include "./SortAlgorithm/Sort.h"
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
		// Setting to `nullptr` ensures the destructor won't release the original memory
		other._data = nullptr;
		other._size = 0;
	}

	String& operator=(String&& other) noexcept {
		printf("String is Moved by `operator=`\n");
		delete[] _data;	// If not done, it might lead to memory leaks.
		_size = other._size;
		_data = other._data;
		other._data = nullptr;
		other._size = 0;

		return *this;
	}

	~String() {
		printf("String is Destroyed\n");
		delete[] _data;
	}

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
	Entity(const String& name) :_name(name) {}

	Entity(String&& name) :_name(std::move(name)) {}

	void printName() {
		_name.print();
	}

private:
	String _name;
};

int main() {
	Vector<int> v1;
	v1.print();
	v1.push_back(1);
	v1.print();
	v1.push_back(2);
	v1.print();
	v1.push_back(3);
	v1.print();

	//std::cin.get();
}
