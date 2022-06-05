#include "polynom.cpp"

int main() {
    
    
    std::map<int, int> q = {{2, 3}, {1, -5}, {9, 4}, {4, 4}};
    Polynomial a({{2, 3}, {1, -5}, {9, 4}, {4, 4}});
    Polynomial b;
    std::cin >> b;
    
    std::cout << a + (b * 2);
    
}