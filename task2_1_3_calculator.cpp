#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

inline double square(double x) {
    return x * x;
}

double power(double base, int exponent = 2) {
    return std::pow(base, exponent);
}

double calc(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0.0) {
            throw std::runtime_error("Error: divide by zero");
        }
        return a / b;
    default:
        throw std::invalid_argument("Error: unsupported operator");
    }
}

double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

bool isInteger(double value) {
    return std::floor(value) == value;
}

int main() {
    double a = 0.0;
    double b = 0.0;
    char op = '\0';
    std::cout << "Enter two operands and an operator: ";
    if (!(std::cin >> a >> b >> op)) {
        std::cerr << "Error: invalid input." << std::endl;
        return 1;
    }

    const auto formatInput = [](double value) {
        std::ostringstream output;
        if (isInteger(value)) {
            output << static_cast<int>(value);
        } else {
            output << std::fixed << std::setprecision(2) << value;
        }
        return output.str();
    };

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "square(" << formatInput(a) << ") = " << square(a) << '\n';
    std::cout << "power(" << formatInput(a) << ",3) = " << power(a, 3) << '\n';

    try {
        const double result = isInteger(a) && isInteger(b)
            ? calc(static_cast<int>(a), static_cast<int>(b), op)
            : calc(a, b, op);
        std::cout << formatInput(a) << " " << op << " " << formatInput(b)
                  << " = " << result << '\n';
    } catch (const std::exception& error) {
        std::cout << error.what() << '\n';
    }

    return 0;
}
