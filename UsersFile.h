#ifndef USERSFILE_H
#define USERSFILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "User.h"
#include "MetodyPomocnicze.h"
#include "PlikXML.h"

using namespace std;

class UsersFile : public PlikXML{

    User pobierzDaneUzytkownika(string dane);

public:
    UsersFile(string usersFileName) : PlikXML(usersFileName) {};
    //string usersFileName;
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePasswordInFile(int loggedUserId, string newPassword);

};
#endif
