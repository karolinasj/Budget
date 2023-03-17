#ifndef USERMENEDZER_H
#define USERMENEDZER_H
#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserMenedzer {
    UsersFile plikZUzytkownikami;
    vector <User> users;
    int loggedUserId;
    User getNewUserData();
    int getNewUserId();
    bool checkIfLoginExists(string login);

public:
    UserMenedzer(string usersFileName) : plikZUzytkownikami(usersFileName) {
        loggedUserId = 0; //TU 0!!!
        users = plikZUzytkownikami.loadUsersFromFile();
    };
    void registerNewUser();
    void wypiszWszystkichUzytkownikow();
    int loginUser();
    void changeLoggedUserPassword();
    int getLoggedUserId();
    bool checkIfUserIsLogged();
    void logOutUser();
};
#endif
