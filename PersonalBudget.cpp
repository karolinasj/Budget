#include "PersonalBudget.h"

char PersonalBudget::chooseMainMenuOption() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

bool PersonalBudget::checkIfUserIsLogged(){
    if (userMenedzer.getLoggedUserId() > 0 )
        return true;
    else
        return false;
}

void PersonalBudget::logOutUser(){
    userMenedzer.logOutUser();
    delete operationMeneger;
    operationMeneger = NULL;
}

void PersonalBudget::registerUser(){
    userMenedzer.registerNewUser();
}
void PersonalBudget::loginUser(){
    userMenedzer.loginUser();
    if (userMenedzer.checkIfUserIsLogged()){
        operationMeneger = new OperationMeneger(NAZWA_PLIKU_Z_INCOMAMI, NAZWA_PLIKU_Z_EXPENSAMI, userMenedzer.getLoggedUserId());
    }
}

void PersonalBudget::changePassword(){
    userMenedzer.changeLoggedUserPassword();
}

char PersonalBudget::chooseUserMenuOption() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void PersonalBudget::addIncome(){
    operationMeneger->registerNewIncome();
}
void PersonalBudget::addExpense(){
    operationMeneger->registerNewExpense();
}
void PersonalBudget::showAll(){

    operationMeneger-> showAllIncomes();
    operationMeneger->showAllExpenses();
}
void PersonalBudget::sortAndShowInc(){
    operationMeneger->sortIncomes();
    //operationMeneger-> showAllIncomes();
}



