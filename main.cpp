#include "./SortAlgorithm/Sort.h"
#include "./MySTL/Array.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

template<typename T>
void print(std::vector<T>& v, std::string pre = "") {
	std::cout << pre << std::endl;
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	return;
}

int main() {
	/*
	std::cout << "----------BubbleSort Test-----------" << std::endl;
	std::vector<int> v1 = { 1, 4, 6, 568, 678, 67, 45, 34, 5, -1 };
	print(v1, "v1:");
	ymstl::bubbleSort(v1.begin(), v1.end(), std::greater<>{});
	print(v1, "sorted by ymstl v1 £º");
	sort(v1.begin(), v1.end(), std::less<>());
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

	std::vector<int> v5 = { 1, -4, 6, 568, 68, 67, 45, 34, 5, -1,0 };
	print(v5, "v5: ");
	//ymstl::sort(v5);
	//ymstl::sort(v5.begin(), v5.end());
	ymstl::sort(v5.begin(), v5.end(), std::greater<int>());
	print(v5, "sorted by mySort v5: ");
	

	{
		ymstl::Timer timer("v6");
		std::vector<double> v6 = { 123.234,23.,4.23,4.2,3.5,.2,5.34,6.34 };
		print(v6, "v6: ");
		ymstl::quickSort(v6.begin(), v6.end());
		print(v6, "quickSorted v6: ");
	}
	*/

	int n = 5;
	int array[5] = { 1,3,4,1};
	ymstl::Array<int, 5> myArray{};
	myArray[1] = 2;
	ymstl::Array<int, myArray.size()> a1;
	for (int i = 0; i < myArray.size(); i++) {
		std::cout << myArray[i] << std::endl;
	}
	std::cout << array;
	std::cout << myArray.data();
	//std::cin.get();
}
