#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <fstream>
#include <iostream>
#include <vector>
#include<sstream>
#include <algorithm>
#include "User.h"

using namespace std;

class MetodyPomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();

    static char wczytajZnak();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int konwersjaStringNaInt(string liczba);
    static int wczytajLiczbeCalkowita();

};
#endif
