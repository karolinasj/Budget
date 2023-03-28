#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserMenedzer.h"
#include "OperationMeneger.h"


using namespace std;

class PersonalBudget {

    UserMenedzer userMenedzer;
    OperationMeneger *operationMeneger;
    const string NAZWA_PLIKU_Z_INCOMAMI;
    const string NAZWA_PLIKU_Z_EXPENSAMI;
public:
    PersonalBudget(string usersFileName, string nazwaPlikuZIncomami, string nazwaPlikuZExpensami) : userMenedzer(usersFileName), NAZWA_PLIKU_Z_INCOMAMI(nazwaPlikuZIncomami) , NAZWA_PLIKU_Z_EXPENSAMI(nazwaPlikuZExpensami) {
        operationMeneger = NULL;
    };
    ~PersonalBudget() {
        delete operationMeneger;
        operationMeneger = NULL;
    };
    char chooseMainMenuOption();
    char chooseUserMenuOption();
    bool checkIfUserIsLogged();
    void logOutUser();
    void registerUser();
    void loginUser();
    void changePassword();

    void addIncome();
    void addExpense();
    void showAll();

    void monthlyBilans();
    void previousMonthBilans();
    void choosenBilans();
};

#endif
