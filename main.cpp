#include "./SortAlgorithm/Sort.h"
#include "./MySTL/Array.h"
#include "./MySTL/Vector.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace ymstl;

int main() {
	Vector<int> a;
	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	printVector(a);

	std::vector<int> b(3,4);

	//std::cin.get();
}
