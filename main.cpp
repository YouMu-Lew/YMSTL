#include "./SortAlgorithm/Sort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
void print(std::vector<T>& v, std::string pre = "") {
	std::cout << pre << std::endl;
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	return;
}

int main() {

	std::cout << "----------BubbleSort Test-----------" << std::endl;
	std::vector<int> v1 = { 1, 4, 6, 568, 678, 67, 45, 34, 5, -1 };
	print(v1, "v1:");
	ymstl::bubbleSort(v1.begin(), v1.end(), std::greater<int>());
	print(v1, "sorted by ymstl v1 £º");
	sort(v1.begin(), v1.end(), std::less<int>());
	print(v1, "sorted by sort v1 £º");
	std::cout << "-------------------------------------" << std::endl;

	std::vector<double> v2 = { 123.123,123.41,.4,34,.1234,.1,.41,24.,1.4,.123,4.13,4 };
	print(v2, "v2: ");
	ymstl::bubbleSort(v2.begin(), v2.end() - 1);
	print(v2, "sorted by ymstl v2: ");
	sort(v2.begin(), v2.end() - 1);
	print(v2, "sorted by sort v2: ");
	std::cout << "----------BubbleSort Test-----------" << std::endl;
	std::cout << std::endl;

	std::vector<int> v3 = { 1, 4, 6, 568, 678, 67, 45, 34, 5, -1 };
	print(v3, "v3: ");
	ymstl::selectionSort(v3.begin(), v3.end());
	print(v3, "sorted by selectionSort v3: ");

	std::vector<int> v4 = { 1, -4, 6, 568, 68, 67, 45, 34, 5, -1,0 };
	print(v4, "v4: ");
	ymstl::insertionSort(v4.begin(), v4.end());
	print(v4, "sorted by insertionSort v4: ");

}
