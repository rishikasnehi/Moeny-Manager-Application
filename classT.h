#ifndef CLASST_H
#define CLASST_H

#include <iostream>
#include <string>
using namespace std;

class Transaction
{
public:
    string date, note;
    float amount;
    Transaction(string tx_date, float tx_amt, string tx_note);
};

#endif