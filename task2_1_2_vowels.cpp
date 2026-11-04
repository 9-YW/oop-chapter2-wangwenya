#include <cctype>
#include <iostream>
#include <string>

int countVowels(const char* p) {
    int count = 0;
    while (p != nullptr && *p != '\0') {
        const char ch = static_cast<char>(std::tolower(static_cast<unsigned char>(*p)));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++count;
        }
        ++p;
    }
    return count;
}

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, text);
    std::cout << "Number of vowels: " << countVowels(text.c_str()) << std::endl;
    return 0;
}
