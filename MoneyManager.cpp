/* compile this program using
g++ .\MoneyManager.cpp .\utils.cpp .\utils.h .\classT.cpp .\classT.h .\classMoneyManager.cpp .\classMoneyManager.h -o run.exe*/
/* run this command to execute th eprogram :
.\run.exe */
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <vector>
#include <fstream>

#include "utils.h"
#include "classT.h"
#include "classMoneyManager.h"

using namespace std;

int main()
{
    MoneyManager mm;
    mm.runApplication();
}