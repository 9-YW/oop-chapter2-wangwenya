#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double chinese;
    double math;
    double english;
};

int main() {
    int count = 0;
    std::cout << "Enter student count: ";
    if (!(std::cin >> count) || count <= 0) {
        std::cerr << "Error: student count must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<Student> students;
    students.reserve(static_cast<std::size_t>(count));

    for (int i = 0; i < count; ++i) {
        Student student;
        if (!(std::cin >> student.name >> student.chinese >> student.math >> student.english)) {
            std::cerr << "Error: invalid student record." << std::endl;
            return 1;
        }
        students.push_back(student);
    }

    std::cout << std::fixed << std::setprecision(2);
    for (const Student& student : students) {
        const double average = (student.chinese + student.math + student.english) / 3.0;
        std::cout << std::left << std::setw(12) << student.name
                  << std::right << std::setw(8) << student.chinese
                  << std::setw(8) << student.math
                  << std::setw(8) << student.english
                  << std::setw(8) << average;
        if (average >= 90.0) {
            std::cout << " Excellent";
        }
        std::cout << '\n';
    }

    return 0;
}
