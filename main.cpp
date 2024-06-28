//#include <algorithm>
//#include <array>
#include <iostream>
//#include <string>
//#include <vector>
//#include "./MySTL/Array.h"
//#include "./MySTL/Vector.h"
//#include "./SortAlgorithm/Sort.h"
//
//using namespace ymstl;

class String {
public:
	String() = default;
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

	~String() {
		printf("String is Destroyed\n");
		delete _data;
	}

	void print() {
		for (size_t i = 0; i < _size; i++)
			printf("%c", _data[i]);
		printf("\n");
	}

private:
	size_t _size;
	char* _data;
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
	Entity entity("YouMu");
	entity.printName();

	std::cin.get();
}
