#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H


#include <string>


namespace card {


static const double FEE_RATE = 0.02;
static const double WARNING_BALANCE = 10.0;


struct Card {
    long long id;
    std::string name;
    double balance;
    int transactions;
};


void printLine(char c = '-', int len = 60);
void title(const std::string& text);


Card* createCards(int count);
void destroyCards(Card* cards);
void inputCards(Card* cards, int count);


void deposit(Card& account, double amount, double fee = FEE_RATE);
bool spend(Card& account, double cost);
bool spend(Card& account, double cost, const std::string& item);
void showBalance(const Card& account);
void viewStudentID(const Card* account);


int toCent(double amount);
void printReport(const Card* cards, int count);


} // namespace card


#endif

