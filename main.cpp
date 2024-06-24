#include "./SortAlgorithm/Sort.h"
#include <iostream>
#include <vector>

void printV(std::vector<int>& v) {
    for (int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    return;
}

int main() {
    std::vector<int> v = {1, 4, 6, 568, 678, 67, 45, 34, 5, -1};
    printV(v);
    ymstl::bubbleSort(v.begin(), v.end());
    printV(v);
}
