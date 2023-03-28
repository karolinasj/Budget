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
                cout << "Poprawna data: ";
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
    showIncomes(incomes);
}

void OperationMeneger::showAllExpenses() {
    showExpenses(expenses);
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
                cout << "Poprawna data: ";
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
vector <Income> OperationMeneger::findIncomesFromPeriod(int dateStart, int dateEnd) {

    vector <Income> doBilansu;
    int vectorSize = incomes.size();
    for(int i=0; i<vectorSize ; i++) {
        int checkingDate;
        string checkingDateStr;
        checkingDateStr = incomes[i].getDate();
        checkingDate = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(checkingDateStr));

        if(checkingDate >= dateStart && checkingDate <= dateEnd) {
            doBilansu.push_back(incomes[i]);
        }
    }
    return doBilansu;
}
vector <Expense> OperationMeneger::findExpensesFromPeriod(int dateStart, int dateEnd) {

    vector <Expense> doBilansu;
    int vectorSize = expenses.size();
    for(int i=0; i<vectorSize ; i++) {
        int checkingDate;
        string checkingDateStr;
        checkingDateStr = expenses[i].getDate();
        checkingDate = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(checkingDateStr));

        if(checkingDate >= dateStart && checkingDate <= dateEnd) {
            doBilansu.push_back(expenses[i]);
        }
    }
    return doBilansu;
}

vector <Income> OperationMeneger::sortIncomes(vector <Income> incomeToSort) {
    sort(incomeToSort.begin(), incomeToSort.end(), sortByDate());
    return incomeToSort;
}
vector <Expense> OperationMeneger::sortExpenses(vector <Expense> expensesToSort) {
    sort(expensesToSort.begin(), expensesToSort.end(), sortByDate());

    return expensesToSort;
}
void OperationMeneger::showIncomes(vector <Income> toShow) {
    cout << "INCOMES: "<<endl;
    for(size_t i=0; i <toShow.size(); i++) {
        cout << "ID operacji: " << toShow[i].getOperationId()<<" || Data: " << toShow[i].getDate()<<" || Kwota: " << toShow[i].getAmount()<<" || Opis: " << toShow[i].getItem()<<endl;
    }
}
void OperationMeneger::showExpenses(vector <Expense> toShow) {
    cout << "EXPENSES: "<<endl;
    for(size_t i=0; i <toShow.size(); i++) {

        cout << "ID operacji: " << toShow[i].getOperationId()<<" || Data: " << toShow[i].getDate()<<" || Kwota: " << toShow[i].getAmount()<<" || Opis: " << toShow[i].getItem()<<endl;
        // cout << incomes[i].getUserId()<<endl;
    }
}

void OperationMeneger::showBilansPeriod() {

    string dateStart, dateEnd;
    int dateAsIntStart, dateAsIntEnd;

    do {
        cout << "Podaj date poczatkowa: ";
        dateStart = MetodyPomocnicze::wczytajLinie();
    } while(!MetodyPomocnicze::checkDate(dateStart));
    do {
        cout << "Podaj date koncowa: ";
        dateEnd = MetodyPomocnicze::wczytajLinie();
    } while(!MetodyPomocnicze::checkDate(dateEnd));

    dateAsIntStart = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(dateStart));
    dateAsIntEnd = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(dateEnd));

    vector <Income> incomesForBilans = findIncomesFromPeriod(dateAsIntStart, dateAsIntEnd);
    vector <Expense> expensesForBilans = findExpensesFromPeriod(dateAsIntStart, dateAsIntEnd);
    incomesForBilans = sortIncomes(incomesForBilans);
    expensesForBilans = sortExpenses(expensesForBilans);
    double incomesSum = 0.0, expensesSum = 0.0;
    double bilans = 0.0;
    for(size_t i = 0; i<incomesForBilans.size() ; i++) {
        incomesSum+=incomesForBilans[i].getAmount();
    }

    for(size_t i = 0; i<expensesForBilans.size() ; i++) {
        expensesSum+=expensesForBilans[i].getAmount();
    }
    bilans = incomesSum - expensesSum;

    showIncomes(incomesForBilans);
    showExpenses(expensesForBilans);

    cout <<  "__________________________________"<<endl;
    cout<< "Suma wydatkow: " << expensesSum << " Suma przychodow: " << incomesSum << " Bilans: "<<bilans<<endl;
    system("pause");
}

void OperationMeneger::showBilansCurrentMonth() {
    string currentDate = MetodyPomocnicze::getCurrentDate();
    vector <string> currentDateSeparated = MetodyPomocnicze::splitStringByDash(currentDate);
    string firstDay = currentDateSeparated[0]+"-"+currentDateSeparated[1]+"-"+"01";
    int dateAsIntStart = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(firstDay));
    int dateAsIntEnd = MetodyPomocnicze::konwersjaStringNaInt(returnDateWithoutDashes(currentDate));

    vector <Income> incomesForBilans = findIncomesFromPeriod(dateAsIntStart, dateAsIntEnd);
    vector <Expense> expensesForBilans = findExpensesFromPeriod(dateAsIntStart, dateAsIntEnd);
    incomesForBilans = sortIncomes(incomesForBilans);
    expensesForBilans = sortExpenses(expensesForBilans);
    double incomesSum = 0.0, expensesSum = 0.0;
    double bilans = 0.0;
    for(size_t i = 0; i<incomesForBilans.size() ; i++) {
        incomesSum+=incomesForBilans[i].getAmount();
    }

    for(size_t i = 0; i<expensesForBilans.size() ; i++) {
        expensesSum+=expensesForBilans[i].getAmount();
    }
    bilans = incomesSum - expensesSum;

    showIncomes(incomesForBilans);
    showExpenses(expensesForBilans);

    cout <<  "__________________________________"<<endl;
    cout<< "Suma wydatkow: " << expensesSum << " Suma przychodow: " << incomesSum << " Bilans: " <<  bilans<<endl;
    system("pause");

}

void OperationMeneger::showBilansLastMonth() {
    string currentDate = MetodyPomocnicze::getCurrentDate();
    vector <int> previousMonth = MetodyPomocnicze::findPreviousMonth(currentDate); //vector <string> findPreviousMonth(string dateWithDashes)

    vector <Income> incomesForBilans = findIncomesFromPeriod(previousMonth[0], previousMonth[1]);
    vector <Expense> expensesForBilans = findExpensesFromPeriod(previousMonth[0], previousMonth[1]);
    incomesForBilans = sortIncomes(incomesForBilans);
    expensesForBilans = sortExpenses(expensesForBilans);
    double incomesSum = 0.0, expensesSum = 0.0;
    double bilans = 0.0;
    for(size_t i = 0; i<incomesForBilans.size() ; i++) {
        incomesSum+=incomesForBilans[i].getAmount();
    }

    for(size_t i = 0; i<expensesForBilans.size() ; i++) {
        expensesSum+=expensesForBilans[i].getAmount();
    }
    bilans = incomesSum - expensesSum;

    showIncomes(incomesForBilans);
    showExpenses(expensesForBilans);

    cout <<  "__________________________________"<<endl;
    cout<< "Suma wydatkow: " << expensesSum << " Suma przychodow: " << incomesSum << " Bilans: " << bilans<<endl;
    system("pause");

}
