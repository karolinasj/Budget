#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include "Expense.h"
#include "MetodyPomocnicze.h"
#include "PlikXML.h"

using namespace std;

class ExpensesFile : public PlikXML{

    Expense getExpenseData(string dane);
    int lastExpenseID;
    //int loadExpensesFromFile();

public:
    ExpensesFile(string expensesFileName) : PlikXML(expensesFileName) {
    //lastExpenseID = loadExpensesFromFile();
    };

    void addExpenseToFile(Expense expense);
    vector <Expense> loadUresrsExpenses(int userId);
    int getLastExpenseID();
    vector <Expense> loadExpensesFromFile(int usersId);

};
#endif
