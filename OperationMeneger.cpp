#include "OperationMeneger.h"

void OperationMeneger::registerNewIncome() {
    Income income = getNewIncomeData();

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Przychod dodany pomyslnie" << endl << endl;
    system("pause");
}

Income OperationMeneger::getNewIncomeData() {
    Income income;

    income.setOperationId(fileWithIncomes.getLastIncomeID()+1);
    income.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Czy przychod jest z dzisiaj? T/N : ";
    char answer;
    answer = MetodyPomocnicze::wczytajZnak();
    if(answer == 'T' || answer == 't') {
        income.setDate(MetodyPomocnicze::getCurrentDate());
    } else if(answer == 'N' || answer == 'n') {
        cout << "Podaj date: ";
        string date="";
        do {
            date = MetodyPomocnicze::wczytajLinie();
            if(MetodyPomocnicze::checkDate(date)) {
                income.setDate(date);
            } else {
                cout << "Prosze podac date po roku 2000 w formacie rrrr-mm-dd: ";//cout << "Nieprawidlowa data, prosze podac poprawna";
                date = "";
            };
        } while(date =="");
    }

    cout << "Podaj kowte: ";
    income.setAmount(MetodyPomocnicze::pobierzDouble());
    cout << "Podaj opis: ";
    income.setItem(MetodyPomocnicze::wczytajLinie());

    return income;
}

void OperationMeneger::showAllIncomes() {
cout << "INCOMES: "<<endl;
/*    for(size_t i=0; i <incomes.size(); i++) {

        cout << "ID operacji " << incomes[i].getOperationId()<<endl;
        // cout << incomes[i].getUserId()<<endl;
        cout << "Kwota " << incomes[i].getAmount()<<endl;
        cout << "Data " << incomes[i].getDate()<<endl;
        cout << "Opis " << incomes[i].getItem()<<endl<<endl;
    }
*/
showIncomes(incomes);
}

void OperationMeneger::showAllExpenses() {
cout << "EXPENSES: "<<endl;
    for(size_t i=0; i <expenses.size(); i++) {

        cout << "ID operacji " << expenses[i].getOperationId()<<endl;
        // cout << expenses[i].getUserId()<<endl;
        cout << "Kwota " << expenses[i].getAmount()<<endl;
        cout << "Data " << expenses[i].getDate()<<endl;
        cout << "Opis " << expenses[i].getItem()<<endl<<endl;
    }
}
void OperationMeneger::registerNewExpense() {
    Expense expense = getNewExpenseData();

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);

    cout << endl << "Wydatek dodany pomyslnie" << endl << endl;
    system("pause");
}

Expense OperationMeneger::getNewExpenseData() {
    Expense expense;

    expense.setOperationId(fileWithExpenses.getLastExpenseID()+1);
    expense.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Czy wydatek jest z dzisiaj? T/N : ";
    char answer;
    answer = MetodyPomocnicze::wczytajZnak();
    if(answer == 'T' || answer == 't') {
        expense.setDate(MetodyPomocnicze::getCurrentDate());
    } else if(answer == 'N' || answer == 'n') {
        cout << "Podaj date: ";
        string date="";
        do {
            date = MetodyPomocnicze::wczytajLinie(); //GGGGGGGGG
            if(MetodyPomocnicze::checkDate(date)) {
                expense.setDate(date);
            } else {
                cout << "Prosze podac date po roku 2000 w formacie rrrr-mm-dd: ";//cout << "Nieprawidlowa data, prosze podac poprawna";
                date = "";
            };
        } while(date =="");
    }

    cout << "Podaj kowte: ";
    expense.setAmount(MetodyPomocnicze::pobierzDouble());
    cout << "Podaj opis: ";
    expense.setItem(MetodyPomocnicze::wczytajLinie());

    return expense;
}
string OperationMeneger::returnDateWithoutDashes(string dateWithDashes) {
    string dataWithoutDashes;
    dataWithoutDashes = dateWithDashes.erase(4, 1);
    dataWithoutDashes = dateWithDashes.erase(6, 1);
    return dateWithDashes;
}
vector <Income> OperationMeneger::findIncomesFromPeriod() {

    string dateStart, dateEnd;
    int dateAsIntStart, dateAsIntEnd;
    vector <Income> doBilansu;

    cout << "Podaj date poczatkowa: ";
    cin >> dateStart;
    cout << "Podaj date koncowa: ";
    cin >> dateEnd;

    dateAsIntStart = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(dateStart));
    dateAsIntEnd = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(dateEnd));

    int vectorSize = incomes.size();
    for(int i=0; i<vectorSize ; i++) {
        int checkingDate;
        string checkingDateStr;
        checkingDateStr = incomes[i].getDate();
        checkingDate = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(checkingDateStr));

        if(checkingDate >= dateAsIntStart && checkingDate <= dateAsIntEnd) {
            doBilansu.push_back(incomes[i]);
        }
    }
    return doBilansu;
}

bool OperationMeneger::compareIncome(Income i1, Income i2) {
    int dateAsInt1, dateAsInt2;
    dateAsInt1 = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(i1.getDate()));
    //cout << i1.date << ", " << dateAsInt1;
    dateAsInt2 = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(i2.getDate()));
    //cout <<endl <<i2.date<< ", " << dateAsInt2;
    //system("pause");
    if (dateAsInt1<dateAsInt2) {
        return (0);
    } else {
        return (1);
    }
}

vector <Income> OperationMeneger::sortIncomes(){
    sort(incomes.begin(), incomes.end(), sortByDate());
    vector <Income> incomeToSort;
    incomeToSort = findIncomesFromPeriod();
    //sort(incomeToSort.begin(), incomeToSort.end(), sortByDate());
    showIncomes(incomeToSort);
    return incomeToSort;

}
void OperationMeneger::showIncomes(vector <Income> toShow) {
//cout << "INCOMES: "<<endl;
    for(size_t i=0; i <toShow.size(); i++) {

        cout << "ID operacji " << toShow[i].getOperationId()<<endl;
        // cout << incomes[i].getUserId()<<endl;
        cout << "Kwota " << toShow[i].getAmount()<<endl;
        cout << "Data " << toShow[i].getDate()<<endl;
        cout << "Opis " << toShow[i].getItem()<<endl<<endl;
    }
}
void OperationMeneger::showExpenses(vector <Expense> toShow) {
//cout << "INCOMES: "<<endl;
    for(size_t i=0; i <toShow.size(); i++) {

        cout << "ID operacji " << toShow[i].getOperationId()<<endl;
        // cout << incomes[i].getUserId()<<endl;
        cout << "Kwota " << toShow[i].getAmount()<<endl;
        cout << "Data " << toShow[i].getDate()<<endl;
        cout << "Opis " << toShow[i].getItem()<<endl<<endl;
    }
}



