#include "UserMenedzer.h"

void UserMenedzer::registerNewUser() {
    User user = getNewUserData();

    users.push_back(user);

    plikZUzytkownikami.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UserMenedzer::getNewUserData() {
    User user;

    user.setUserId(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setLogin(MetodyPomocnicze::wczytajLinie());
    } while (checkIfLoginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(MetodyPomocnicze::wczytajLinie());

    /*cout << "Podaj imie: ";
    user.setName(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj nazwisko: ";
    user.setSurname(MetodyPomocnicze::wczytajLinie());*/

    return user;
}
int UserMenedzer::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

int UserMenedzer::getLoggedUserId() {
    return loggedUserId;
}

bool UserMenedzer::checkIfLoginExists(string login) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}


void UserMenedzer::wypiszWszystkichUzytkownikow() {
    for (size_t i = 0; i < users.size(); i++) {
        cout << "Login: " << users[i].getLogin()<<endl;
        cout << "Haslo: " << users[i].getPassword()<<endl;
    }
}

int UserMenedzer::loginUser() {
    User user;
    string login = "", password = "", name = "", surname = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                password = MetodyPomocnicze::wczytajLinie();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = (itr -> getUserId());
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            loggedUserId = 0;
            return loggedUserId;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    loggedUserId = 0;
    return loggedUserId;
}

void UserMenedzer::changeLoggedUserPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = MetodyPomocnicze::wczytajLinie();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.changePasswordInFile(loggedUserId, newPassword);
}

bool UserMenedzer::checkIfUserIsLogged() {
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserMenedzer::logOutUser() {
    loggedUserId = 0;
}
