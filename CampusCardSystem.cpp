#include "card_operations.h"

#include <exception>
#include <iostream>
#include <new>

int main() {
    card::Card* accounts = nullptr;

    try {
        int count = 0;
        card::title("Campus Card System");
        std::cout << "Enter student count: ";
        if (!(std::cin >> count) || count <= 0) {
            throw std::invalid_argument("Error: student count must be a positive integer.");
        }

        accounts = card::createCards(count);
        card::inputCards(accounts, count);

        card::deposit(accounts[0], 100.0);
        card::spend(accounts[0], 8.5, "Lunch");
        card::showBalance(accounts[0]);
        card::viewStudentID(&accounts[0]);
        std::cout << "Balance in cents: " << card::toCent(accounts[0].balance) << '\n';
        card::printReport(accounts, count);
    } catch (const std::bad_alloc&) {
        std::cerr << "Error: memory allocation failed." << std::endl;
    } catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
    }

    card::destroyCards(accounts);
    return 0;
}
