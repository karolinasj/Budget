#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    CMarkup xml;
    //usersFileName = "PlikZUserami.xml";
    bool fileExists = xml.Load( FILE_NAME );

    if(!fileExists) {
        xml.AddElem( "USERSLIST" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.AddElem( "USER_ID", user.getUserId() );
    xml.AddElem( "LOGIN", user.getLogin() );
    xml.AddElem( "PASSWORD", user.getPassword() );
    xml.AddElem( "NAME", user.getName() );
    xml.AddElem( "SURNAME", user.getSurname() );

    xml.Save(FILE_NAME);
}

vector <User> UsersFile::loadUsersFromFile() {
    CMarkup xml;
    vector <User> users;
    User tempUser;

    //usersFileName = "PlikZUserami.xml"; //TUTAJ TRZEBA POBRAC NAZWE PPLIKu Z GORY
    bool fileExists = xml.Load( FILE_NAME);

    if(!fileExists) {
        cout << "Nie ma uzytkownikow. Zarejestruj sie";
    }
    xml.FindElem(); //USERSLIST
    xml.IntoElem();
    while(xml.FindElem("USER"))
    {
        xml.IntoElem();

        xml.FindElem("USER_ID");
        string strID = "";
        int id = 0;
        strID = xml.GetData();
        id = MetodyPomocnicze::konwersjaStringNaInt(strID);
        tempUser.setUserId(id);

        xml.FindElem("LOGIN");
        string login = "";
        login = xml.GetData();
        tempUser.setLogin(login);

        xml.FindElem("PASSWORD");
        string password = "";
        password = xml.GetData();
        tempUser.setPassword(password);

        xml.FindElem("NAME");
        string name = "";
        name = xml.GetData();
        tempUser.setName(name);

        xml.FindElem("SURNAME");
        string surname = "";
        surname = xml.GetData();
        tempUser.setSurname(surname);

        users.push_back(tempUser);
        xml.OutOfElem();

    }
    return users;
}
/*User UsersFile::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
    User uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejUzytkownika) {
            case 1:
                uzytkownik.setUserId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.setLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.setPassword(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}*/

void UsersFile::changePasswordInFile(int loggedUserId, string newPassword) {
    CMarkup xml;
    //usersFileName = "PlikZUserami.xml";

    bool fileExists = xml.Load( FILE_NAME);

    if(fileExists) {
        xml.FindElem(); //USERSLIST
        xml.IntoElem();
        while(xml.FindElem()) {

            xml.IntoElem();

            xml.FindElem("USER_ID");
            string strID = "";
            int id = 0;
            strID = xml.GetData();
            id = MetodyPomocnicze::konwersjaStringNaInt(strID);
            if(id == loggedUserId) {
                //xml.IntoElem();
                xml.FindElem("PASSWORD");
                xml.RemoveElem();
                xml.AddElem("PASSWORD", newPassword);
                xml.Save( FILE_NAME) ;
            }
            else xml.OutOfElem();

        }
    }
xml.Save( FILE_NAME ) ; // sprawdzic czy ten save jest potrzebny

}
