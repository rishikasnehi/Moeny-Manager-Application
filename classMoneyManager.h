// fle for class Money Manager
#ifndef CLASSMONEYMANAGER_H
#define CLASSMONEYMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "classT.h"
#include <fstream>
#include "utils.h"

using namespace std;

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
    int runApplication();
    int getType();

    MoneyManager()
    {
        loadData();
    }

private:
    int addIncomeCategory();
    void addExpenseCategory();
    void loadData();
    void storeData();
};

#endif