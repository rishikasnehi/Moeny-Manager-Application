#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <vector>

#include "utils.h"

using namespace std;

class Transaction
{
public:
    string date, note;
    float amount;

    Transaction(string tx_date, float tx_amt, string tx_note)
    {
        date = tx_date;
        amount = tx_amt;
        note = tx_note;
    }
};

class MoneyManager
{
public:
    int balance = 0;
    vector<Transaction *> incomeTransactions;
    vector<Transaction *> expenseTransactions;

    void addExpense();
    void addIncome();
    void showTransaction();
    void showBalance();
    void runApplication();
    int getType();

private:
    int addIncomeCategory();
    void addExpenseCategory();
};

void MoneyManager::addExpense()
{
    string tx_date = getDate();
    float tx_amount = getAmount();
    string tx_note = getNote();
    Transaction *transaction = new Transaction(tx_date, tx_amount, tx_note);
    expenseTransactions.push_back(transaction);
    balance -= tx_amount;
}

void MoneyManager::addIncome()
{
    string tx_date = getDate();
    float tx_amount = getAmount();
    string tx_note = getNote();
    Transaction *transaction = new Transaction(tx_date, tx_amount, tx_note);
    incomeTransactions.push_back(transaction);
    balance += tx_amount;
}

void MoneyManager::showTransaction()
{
    cout << "Type"
         << "\tDate"
         << "\tAmount"
         << "\tNote" << endl;
    for (auto transaction : incomeTransactions)
    {
        cout << "Credit"
             << "\t" << transaction->date << "\t" << transaction->amount << "\t" << transaction->note << endl;
    }
    for (auto transaction : expenseTransactions)
    {
        cout << "Debit"
             << "\t" << transaction->date << "\t" << transaction->amount << "\t" << transaction->note << endl;
    }
}

void MoneyManager::showBalance()
{
    cout << "Your current balance : " << balance << endl;
}

int MoneyManager::getType()
{
    int typeChoice;
    cout << "Select entry type : " << endl
         << "\t1. Income" << endl
         << "\t2. Expense" << endl
         << "\t3. Show recorded transaction" << endl
         << "\t4. Show balance" << endl
         << "\t5. To exit" << endl;

    cin >> typeChoice;
    return typeChoice;
}

void MoneyManager::addExpenseCategory()
{
}

int MoneyManager::addIncomeCategory()
{
}

void MoneyManager::runApplication()
{
    cout << "Starting money manager application" << endl;
    for (int i = 1; i < 10; i++)
    {
        int choice = getType();
        switch (choice)
        {
        case 1:
            addIncome();
            break;
        case 2:
            addExpense();
            break;
        case 3:
            showTransaction();
            break;
        case 4:
            showBalance();
            break;
        case 5:
            return;
        }
    }
    cout << "Stopping the application" << endl;
}

int main()
{
    MoneyManager mm;
    mm.runApplication();
}