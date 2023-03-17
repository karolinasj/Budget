#ifndef OPERATIONMENEDZER_H
#define OPERATIONMENEDZER_H
#include <iostream>
#include <vector>
#include <fstream>

#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class OperationMeneger {

    IncomesFile fileWithIncomes;
    ExpensesFile fileWithExpenses;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Income> incomes;
    vector <Expense> expenses;

    Income getNewIncomeData();
    Expense getNewExpenseData();

    void showIncomes(vector <Income> toShow);
    void showExpenses(vector <Expense> toShow);

public:
OperationMeneger(string fileWithIncomesName, string fileWithExpensesName, int loggedUserId)
    : fileWithIncomes(fileWithIncomesName), fileWithExpenses(fileWithExpensesName), ID_ZALOGOWANEGO_UZYTKOWNIKA(loggedUserId){

    //incomes = fileWithIncomes.loadUresrsIncomes(loggedUserId);
    incomes = fileWithIncomes.loadDataFromFile(loggedUserId);
    expenses = fileWithExpenses.loadUresrsExpenses(loggedUserId);
};
struct sortByDate
{
    inline bool operator() (Income& firstDate, Income& secondDate)
    {
        return (firstDate.getDate() > secondDate.getDate());
    }
};
    void loadUsersIncomesFromFile();
    vector <Income> findIncomesFromPeriod();
    string returnDateWithoutDashes(string dateWithDashes);

    bool compareIncome(Income i1, Income i2);
    vector <Income> sortIncomes();


    void registerNewIncome();
    void registerNewExpense();

    void showAllIncomes();
    void showAllExpenses();


};
#endif
