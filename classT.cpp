#include <iostream>
#include <string>
#include "classT.h"

using namespace std;

Transaction ::Transaction(string tx_date, float tx_amt, string tx_note)
{
    date = tx_date;
    amount = tx_amt;
    note = tx_note;
}