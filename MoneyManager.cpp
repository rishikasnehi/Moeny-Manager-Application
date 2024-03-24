#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
using namespace std;

class MoneyManager
{
public:
    void addExpense();
    void addIncome();
    void showTransaction();
    void showBalance();
    void runApplication();

private:
    void addIncomeCategory();
    void addExpenseCategory();
};

void MoneyManager::addExpense()
{
}

void MoneyManager::addIncome()
{
}

void MoneyManager::showTransaction()
{
}

void MoneyManager::showBalance()
{
}

void MoneyManager::addExpenseCategory()
{
}

void MoneyManager::addIncomeCategory()
{
}

void MoneyManager::runApplication()
{
    cout << "Starting money manager application" << endl;
}

int main()
{
    MoneyManager mm;
    mm.runApplication();
}