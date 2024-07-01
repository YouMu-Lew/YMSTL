// #include <algorithm>
// #include <array>
#include <cstring>
#include <iostream>
// #include <string>
// #include <vector>
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
	String* a = nullptr;
	delete[] a;
	Vector<String> v1;
	printf("\n***************************\n");
	v1.emplace_back("youmu");
	printf("\n***************************\n");
	//v1.push_back("lew");
	v1.pop_back();
	printf("\n***************************\n");
	v1.push_back("cherno3");
	printf("\n***************************\n");
	v1.push_back("cherno4");
	printf("\n***************************\n");
	v1.push_back("cherno5");
	printf("\n***************************\n");
	v1.push_back("cherno6");
	printf("\n***************************\n");
	v1.push_back("cherno7");
	printf("\n***************************\n");
	v1.emplace_back("youmu");
	printf("\n***************************\n");
	v1.clear();
	printf("\n***************************\n");
	v1.emplace_back("youmu");
	printf("\n***************************\n");
	//v1.emplace_back("youmu");
	//v1.emplace_back("youmu");
	//v1.pop_back();
	//v1.emplace_back("error");

	// std::cin.get();
}
