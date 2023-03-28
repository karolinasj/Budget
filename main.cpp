#include <iostream>
#include "PlikXML.h"
#include "UsersFile.h"
#include "UserMenedzer.h"
#include "User.h"
#include "PersonalBudget.h"
#include "OperationMeneger.h"

using namespace std;

int main() {
    char wybor;
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    while (true) {
        if (personalBudget.checkIfUserIsLogged() == false) {
            wybor = personalBudget.chooseMainMenuOption();

            switch (wybor) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            wybor = personalBudget.chooseUserMenuOption();

            switch (wybor) {
            case '1':
                personalBudget.addIncome();
                //Dodaj przychod
                break;
            case '2':
                personalBudget.addExpense();
                //Dodaj wydatek
                break;
            case '3':
                personalBudget.monthlyBilans();
                //Bilans z biezacego miesiaca
                break;
            case '4':
                personalBudget.previousMonthBilans();
                //Bilans z poprzedniego miesiaca
                break;
            case '5':
                personalBudget.choosenBilans();
                //Bilans z wybranego okresu
                break;
            case 'a':
                personalBudget.showAll();
                system("pause");
                break;
            case '8':
                personalBudget.changePassword();
                break;
            case '9':
                personalBudget.logOutUser();
                break;
            }
        }
    }

    cout << "Hello world!" << endl;
    return 0;
}

/*int main()
{

return 0;
}*/
