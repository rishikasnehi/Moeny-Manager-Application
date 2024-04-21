// fle for class Money Manager
#include <iostream>
#include <string>
#include "classT.h"
#include "classMoneyManager.h"
#include <fstream>
#include "utils.h"

using namespace std;

void MoneyManager::loadData()
{
    // read transactions from the file
    // and load them up in incomeTransactions and expenseTransactions;
    ifstream fin;
    fin.open("data.txt");
    string line;
    string data;
    while (getline(fin, line))
    {
        data += line + "\n";
    }
    cout << data;
    fin.close();
}

void MoneyManager::storeData()
{
    // write transactions present in incomeTransactions and expenseTransactions to file
    ofstream out;
    out.open("data.txt");
    out << "Type"
        << "\tDate"
        << "\tAmount"
        << "\tNote" << endl;
    string date_file, note_file;
    float amount_file;
    for (auto transaction : incomeTransactions)
    {
        date_file = transaction->date;
        amount_file = transaction->amount;
        note_file = transaction->note;
        out << "Credit"
            << "\t" << date_file << "\t" << amount_file << "\t" << note_file << endl;
    }
    for (auto transaction : expenseTransactions)
    {
        date_file = transaction->date;
        amount_file = transaction->amount;
        note_file = transaction->note;
        out << "Debit"
            << "\t" << date_file << "\t" << amount_file << "\t" << note_file << endl;
    }
    out.close();
}

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

int MoneyManager::runApplication()
{
    cout << "Starting money manager application" << endl;
    cout << "Previous transactions : " << endl;
    loadData();
    while (1)
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
            storeData();
            return 1;
        }
    }
    cout << "Stopping the application" << endl;
}