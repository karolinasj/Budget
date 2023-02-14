#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserMenedzer.h"
#include "OperationMeneger.h"


using namespace std;

class PersonalBudget {

    UserMenedzer userMenedzer;
//OperationMeneger operationMeneger;
public:
    PersonalBudget(string usersFileName) : userMenedzer(usersFileName){};
    char chooseMainMenuOption();
    char chooseUserMenuOption();
    bool checkIfUserIsLogged();
    void logOutUser();
    void registerUser();
    void loginUser();
    void changePassword();
};

#endif

/*
- userMenedzer : UserMenedzer
- incomeMenedzer : IncomeMenedzer
- expensesMenedzer : ExpensesMenedzer
--
+ PersonalBudget()

+ addIncome() : void
+ addExpense() : void
+ showBalance() : void*/
