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
    PersonalBudget personalBudget("users_v01.xml", "incomes_v01.xml", "expenses_v01.xml");
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
                //ksiazkaAdresowa.dodajAdresata();
                //Dodaj przychod
                break;
            case '2':
                personalBudget.addExpense();
                //Dodaj wydatek
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                //Bilans z biezacego miesiaca
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                //Bilans z poprzedniego miesiaca
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                //Bilans z wybranego okresu
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();

                break;
            case 'a':
                personalBudget.showAll();
                system("pause");
                break;
            case 's':
                personalBudget.sortAndShowInc();
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
