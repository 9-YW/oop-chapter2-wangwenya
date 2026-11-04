#include "card_operations.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace card {

void printLine(char c, int len) {
    std::cout << std::string(static_cast<std::size_t>(len), c) << '\n';
}

void title(const std::string& text) {
    std::cout << "==== " << text << " ====\n";
}

Card* createCards(int count) {
    if (count <= 0) {
        throw std::invalid_argument("account count must be positive");
    }
    return new Card[static_cast<std::size_t>(count)];
}

void destroyCards(Card* cards) {
    delete[] cards;
}

void inputCards(Card* cards, int count) {
    if (cards == nullptr || count <= 0) {
        throw std::invalid_argument("invalid account array");
    }

    for (int i = 0; i < count; ++i) {
        while (true) {
            try {
                std::cout << "Enter account " << (i + 1) << " (id name balance): ";
                if (!(std::cin >> cards[i].id >> cards[i].name >> cards[i].balance)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Error: invalid account data, please re-enter.");
                }
                if (cards[i].balance < 0.0) {
                    throw std::runtime_error("Error: balance cannot be negative, please re-enter.");
                }
                cards[i].transactions = 0;
                break;
            } catch (const std::exception& error) {
                std::cout << error.what() << '\n';
            }
        }
    }
}

void deposit(Card& account, double amount, double fee) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Error: deposit amount must be positive.");
    }
    if (fee < 0.0 || fee >= 1.0) {
        throw std::invalid_argument("Error: invalid fee rate.");
    }
    account.balance += amount * (1.0 - fee);
    ++account.transactions;
}

bool spend(Card& account, double cost) {
    if (cost <= 0.0) {
        throw std::invalid_argument("Error: consumption amount must be positive.");
    }
    if (cost > account.balance) {
        throw std::runtime_error("Error: insufficient balance.");
    }
    account.balance -= cost;
    ++account.transactions;
    return true;
}

bool spend(Card& account, double cost, const std::string& item) {
    std::cout << "Consumption item: " << item << '\n';
    return spend(account, cost);
}

void showBalance(const Card& account) {
    std::cout << account.name << " current balance: " << std::fixed << std::setprecision(2)
              << account.balance << '\n';
    if (account.balance < WARNING_BALANCE) {
        std::cout << "Warning: balance is below " << std::fixed << std::setprecision(2)
                  << WARNING_BALANCE << " yuan.\n";
    }
}

void viewStudentID(const Card* account) {
    if (account == nullptr) {
        throw std::invalid_argument("Error: account pointer is null.");
    }
    std::cout << "Account ID: " << account->id << '\n';
}

int toCent(double amount) {
    return static_cast<int>(amount * 100.0 + 0.5);
}

void printReport(const Card* cards, int count) {
    if (cards == nullptr || count <= 0) {
        throw std::invalid_argument("Error: invalid report data.");
    }

    printLine('=');
    std::cout << std::left << std::setw(14) << "ID"
              << std::setw(16) << "Name"
              << std::right << std::setw(10) << "Balance"
              << std::setw(15) << "Transactions" << '\n';
    printLine();

    for (int i = 0; i < count; ++i) {
        std::cout << std::left << std::setw(14) << cards[i].id
                  << std::setw(16) << cards[i].name
                  << std::right << std::setw(10) << std::fixed << std::setprecision(2)
                  << cards[i].balance
                  << std::setw(15) << cards[i].transactions << '\n';
    }
    printLine('=');
}

} // namespace card
