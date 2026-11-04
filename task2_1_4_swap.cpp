#include <iostream>

void swap(int& x, int& y) {
    const int temp = x;
    x = y;
    y = temp;
}

void swap(double& x, double& y) {
    const double temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 0;
    int y = 0;
    std::cout << "Enter two integers: ";
    if (!(std::cin >> x >> y)) {
        std::cerr << "Error: invalid input." << std::endl;
        return 1;
    }

    std::cout << "Before swap: x=" << x << ", y=" << y << '\n';
    swap(x, y);
    std::cout << "After  swap: x=" << x << ", y=" << y << '\n';
    return 0;
}
