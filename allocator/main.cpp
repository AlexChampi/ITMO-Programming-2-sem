#include <iostream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>
#include <list>
#include "Allocator.cpp"

void vector_test() {
    auto s = static_cast<int>(clock());
    Allocator mem = {{4,    2},
                     {8,    2},
                     {16,   2},
                     {32,   2},
                     {64,   2},
                     {128,  2},
                     {256,  2},
                     {512,  2},
                     {1024, 2},
                     {2048, 2}};
    Allocator::allocator<int> av(mem);
    std::vector<int, Allocator::allocator<int>> vec1(1, av);
    for (int j = 0; j < 100'000; ++j) {
        for (int i = 0; i < 500; ++i) {
            vec1.push_back(1);
        }
        for (int i = 0; i < 500; ++i) {
            vec1.pop_back();
        }
    }

    std::cout << "custom " << clock() - s << '\n';

    s = static_cast<int>(clock());
    std::vector<int> vec2(1);
    for (int j = 0; j < 100'000; ++j) {
        for (int i = 0; i < 500; ++i) {
            vec2.push_back(1);
        }
        for (int i = 0; i < 500; ++i) {
            vec2.pop_back();
        }
    }

    std::cout << "std   " << clock() - s << '\n';

}

void list_test() {

    Allocator mem = {{24, 1000}};
    Allocator::allocator<int> av(mem);
    auto s = static_cast<int>(clock());
    std::list<int, Allocator::allocator<int>> list1(av);
    for (int j = 0; j < 1000; ++j) {
        for (int i = 0; i < 100; ++i) {
            list1.push_back(1);
        }
        for (int i = 0; i < 100; ++i) {
            list1.pop_back();
        }
    }
    std::cout << "custom " << clock() - s << '\n';

    s = static_cast<int>(clock());
    std::list<int> list2;
    for (int j = 0; j < 1000; ++j) {
        for (int i = 0; i < 100; ++i) {
            list2.push_back(1);
        }
        for (int i = 0; i < 100; ++i) {
            list2.pop_back();
        }
    }
    std::cout << "std    " << clock() - s << '\n';



}


void copy_test() {
    Allocator allocator = {{4, 4},
                           {8, 4},
                           {16, 5}};

    {
        std::vector<int, Allocator::allocator<int>> m(1, Allocator::allocator<int>(allocator));
        std::vector<int, Allocator::allocator<int>> q = m;
        m[0] = 1;
        q[0] = 3;
        q.push_back(12);
        m.push_back(5);
        q.pop_back();
        m.push_back(123);

//        for (int i : m) {
//            std::cout << i << ' ';
//        }
//        std::cout << '\n';
//        for (int i : q) {
//            std::cout << i << " ";
//        }
//        std::cout << '\n';
    }
}

int main() {
    vector_test();
    list_test();
    return 0;
}
