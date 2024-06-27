#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "./MySTL/Array.h"
#include "./MySTL/Vector.h"
#include "./SortAlgorithm/Sort.h"

using namespace ymstl;

class Test {
   public:
    int a;
    int b;

    Test() {
        this->a = 0;
        this->b = 0;
    }

    Test(int a) {
        this->a = a;
        this->b = 0;
    }

    Test(int a, int b) {
        this->a = a;
        this->b = b;
    }

    Test(Test& t) : a(t.a), b(t.b) { std::cout << "copy" << std::endl; }

    Test(Test&& t) {
        this->a = t.a;
        this->b = t.b;
        std::cout << "move" << std::endl;
    }

    ~Test() { std::cout << "destory" << std::endl; }

    Test& operator=(Test& t) {
        this->a = t.a;
        this->b = t.b;
        std::cout << "assign" << std::endl;
        return *this;
    }
};

void printVector(const Vector<Test>& v, std::string pre = "") {
    std::cout << pre;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i].a << " " << v[i].b << " ";
    std::cout << std::endl << "------------------------" << std::endl;
    return;
}

int main() {
    Vector<Test> a;
    a.push_back(Test(1, 2));
    printVector(a);
    a.push_back(Test(3));
    printVector(a);
    a.push_back(Test());
    printVector(a);
    a.push_back(Test(2, 3));
    printVector(a);
    a.pop_back();
    a.push_back(Test(2, 3));

    printVector(a);

    std::vector<int> b(3, 4);

    // std::cin.get();
}
