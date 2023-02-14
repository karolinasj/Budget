#include <iostream>
#include "PlikXML.h"
#include "UsersFile.h"
#include "UserMenedzer.h"
#include "User.h"
#include "PersonalBudget.h"

using namespace std;

int main()
{
    char wybor;
    PersonalBudget personalBudget("users_v01.xml");
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
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();

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
    UsersFile plik("PlikZUserami.xml");
    plik.changePasswordInFile(2, "noweH1111aslo");




return 0;
}*/
