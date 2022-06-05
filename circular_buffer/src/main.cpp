#include <iostream>
#include "../include/circular_buffer.h"
#include "../include/algorithms.h"
#include "gtest/gtest.h"
#include <memory_resource>

const std::size_t capacity = 10;

template<typename T, typename Alloc>
void print(alexchamp::circular_buffer<T, Alloc> &c) {
    for (auto i = 0; i < c.size(); ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << '\n';
}

template<typename T, typename Alloc>
void printIt(alexchamp::circular_buffer<T> &c) {
    for (auto i: c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void std_allocator_test() {
    alexchamp::circular_buffer<int> circularBuffer(capacity);
    std::cout << "Push_back " << capacity * 2 << " elements in buffer with capacity = " << capacity << '\n';
    for (std::size_t i = 0; i < 2 * capacity; ++i) {
        circularBuffer.push_back(i);
        print(circularBuffer);
    }

    std::cout << "Push_front " << capacity * 2 << " elements in buffer with capacity = " << capacity << '\n';
    for (std::size_t i = 0; i < 2 * capacity; ++i) {
        circularBuffer.push_front(i);
        print(circularBuffer);
    }

    std::cout << "Pop_front if i % 2 == 0, else pop_back() \n";
    for (std::size_t i = 0; i < capacity; ++i) {
        if (i % 2 == 0)
            circularBuffer.pop_front();

        else
            circularBuffer.pop_back();
        print(circularBuffer);
    }

    int newCapacity = 10 + rand() % 40;
    circularBuffer.change_capacity(newCapacity);
    std::cout << "New capacity: " << newCapacity << "\n";
    for (int i = 0; i < newCapacity; ++i) {
        circularBuffer.push_back(rand() % 10);
    }
    print(circularBuffer);
    std::sort(circularBuffer.begin(), circularBuffer.end());
    print(circularBuffer);
    std::reverse(circularBuffer.begin(), circularBuffer.end());
    print(circularBuffer);
}

void stack_allocator_test() {
    int buffer[capacity];
    std::cout << "Addres of buffer\n";
    for (std::size_t sz = 0; sz < capacity + 1; ++sz) {
        std::cout << &buffer[sz] << " ";
    }
    std::cout << "\n";

    alexchamp::circular_buffer<int> circularBuffer(capacity);
//    for (std::size_t i = 0; i < capacity; ++i) {
//        std::cout << &circularBuffer[i] << ' ';
//    }
    std::cout << std::endl;
    for (std::size_t i = 0; i < capacity; ++i) {
        circularBuffer.push_back(i);
    }
    for (std::size_t i = 0; i < capacity; ++i) {
        std::cout << &circularBuffer[i] << ' ';
    }
    std::cout << std::endl;



}

void algo_comparison_test() {
    int test_capacity = 15;
    alexchamp::circular_buffer<int> algo_test(test_capacity);
    for (int i = 0; i < test_capacity; ++i) {
        algo_test.push_back(rand() % 20);
    }
    std::cout << "Algorithms test \n";
    print(algo_test);
    std::cout << "\nMy  all of < 10 ? "
              << alexchamp::all_of(algo_test.begin(), algo_test.end(), [](int a) { return a < 10; })
              << "\nStd all of < 10 ? " << std::all_of(algo_test.begin(), algo_test.end(), [](int a) { return a < 10; })
              << '\n';
    std::cout << "\nMy  any of == 2 ? "
              << alexchamp::any_of(algo_test.begin(), algo_test.end(), [](int a) { return a == 2; })
              << "\nStd any of == 2 ? " << std::any_of(algo_test.begin(), algo_test.end(), [](int a) { return a == 2; })
              << '\n';
    std::cout << "\nMy  none of == 5 ? "
              << alexchamp::none_of(algo_test.begin(), algo_test.end(), [](int a) { return a == 5; })
              << "\nStd none of == 5 ? "
              << std::none_of(algo_test.begin(), algo_test.end(), [](int a) { return a == 5; })
              << "\n";


    std::cout << "\nMy  one of > 15 ? "
              << alexchamp::one_of(algo_test.begin(), algo_test.end(), [](int a) { return a > 15; })
              << "\nStd one of > 15 ? "
              << (std::count_if(algo_test.begin(), algo_test.end(), [](int a) { return a > 15; }) == 1)
              << "\n";

    std::cout << "\nMy  is sorted ? "
              << alexchamp::is_sorted(algo_test.begin(), algo_test.end(), [](int a, int b) {return a < b;})
              << "\nStd is sorted ? " << std::is_sorted(algo_test.begin(), algo_test.end());

}




int main() {
    srand(time(nullptr));
    stack_allocator_test();



}
