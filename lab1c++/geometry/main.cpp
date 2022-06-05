#include "figure.cpp"


int main() {

    Point A = {0, 0};
    Point B = A;

    Polyline C = {A, {1, 2}, {-5, -9}};
    Polyline D = C;
    std::cout << "lenth D: " << D.size() << " " << "C: " << C.size() << '\n';

    Triangle E = {{3, 0},  {0, 4}, A};
    std::cout << "isRight? " << E.isRight()  << " " << E.square() << '\n';
    Trapeze T = {{0, 0}, {0, 1}, {1, 1}, {10, 0}};
}