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

    vector <Income> findIncomesFromPeriod(int dateStart, int dateEnd);
    vector <Expense> findExpensesFromPeriod(int dateStart, int dateEnd);

    string returnDateWithoutDashes(string dateWithDashes);

    struct sortByDate {
        inline bool operator() (Operation& firstDate, Operation& secondDate) {
            return (firstDate.getDate() < secondDate.getDate());
        }
    };

public:
    OperationMeneger(string fileWithIncomesName, string fileWithExpensesName, int loggedUserId)
        : fileWithIncomes(fileWithIncomesName), fileWithExpenses(fileWithExpensesName), ID_ZALOGOWANEGO_UZYTKOWNIKA(loggedUserId) {

        incomes = fileWithIncomes.loadIncomesFromFile(loggedUserId);
        expenses = fileWithExpenses.loadExpensesFromFile(loggedUserId);
    };



    vector <Income> sortIncomes(vector <Income> incomeToSort);
    vector <Expense> sortExpenses(vector <Expense> expensesToSort);


    void registerNewIncome();
    void registerNewExpense();

    void showAllIncomes();
    void showAllExpenses();

    void showBilansPeriod();
    void showBilansCurrentMonth();
    void showBilansLastMonth();


};
#endif
