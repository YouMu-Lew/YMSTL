
// #include "./MySTL/Array.h"
// #include "./SortAlgorithm/Sort.h"
#include "./lib/Vector.h"
//#include <iostream>
#include <vector>
//#include <functional>
//#include <concepts>

//using namespace ymstl;

void print(int* p) {
    std::cout << *p << std::endl;
}

int main() {
    ymstl::Vector<int> vec = { 1,4,9 };
    std::vector<int> a(3,1);
    a.data();
    a.erase(a.begin());

}
