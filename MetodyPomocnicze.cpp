#include "MetodyPomocnicze.h"

string MetodyPomocnicze::wczytajLinie() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}


char MetodyPomocnicze::wczytajZnak() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
int MetodyPomocnicze::wczytajLiczbeCalkowita(){
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

string MetodyPomocnicze::doubleToString(double number)
{
	ostringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}

double MetodyPomocnicze::pobierzDouble() {
    double wyjscie = 0;
    string wejscie = "";

    wejscie = wczytajLinie();
    replace(wejscie.begin(), wejscie.end(), ',', '.');
    wyjscie = stod(wejscie);

    return wyjscie;
}

// Create custom split() function.
vector <string> MetodyPomocnicze::splitStringByDash(string str) {
    vector < string > strings;
    int startIndex = 0, endIndex = 0;
    char separator = '-';
    for (size_t i = 0; i <= str.size(); i++) {

        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
}
/*string MetodyPomocnicze::getDate() {
    string dataString = wczytajLinie();
    if(checkDate(dataString)) {
        return dataString;
    } //else {
       // dataString = "";
       // return dataString;
    //}
}*/

bool MetodyPomocnicze::checkDate(string dateWithDashes) {

    vector <string> strings;
    strings = splitStringByDash(dateWithDashes);

    int year = 0;
    int month = 0;
    int day = 0;
    //int dateInt = 0;
    year = konwersjaStringNaInt(strings[0]);
    month = konwersjaStringNaInt(strings[1]);
    day = konwersjaStringNaInt(strings[2]);
    int maxDays = 0;

    if (year >= 2000) {
        if((month==2) && ((year%400==0) || ((year%100!=0)&&(year%4==0)))) {
            maxDays = 29;
        } else if(month==2) {
            maxDays = 28;
        } else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
            maxDays = 31;
        } else if(month==4 || month==6 || month==9 || month==11) {
            maxDays = 30;
        } //else cout<<"Invalid month";
        if(day <= maxDays && day>0 ) {
            return true;
        } else {
            return false;
        }

    } else {
        //cout << "Prosze podac date po roku 2000 w formacie rrrr-mm-dd: ";
        return false;
    }

}

string MetodyPomocnicze::getCurrentDate()
{
    auto timeNow = std::time(nullptr);
    auto tm = *std::localtime(&timeNow);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();
    //cout << str;
    return str;
}
