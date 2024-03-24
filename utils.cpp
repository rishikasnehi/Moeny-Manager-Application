#include "utils.h"

string getNote()
{
    string note;
    cout << "Add note : ";
    getline(cin >> ws, note);
    return note;
}

string getDate()
{
    string date;
    cout << "Enter date in DD/MM/YYYY format: ";
    cin >> date;
    return date;
}

float getAmount()
{
    float amount;
    cout << "Enter amount : ";
    cin >> amount;
    return amount;
}