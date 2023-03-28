#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME );

    if(!fileExists) {
        xml.AddElem( "EXPENSES" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "EXPENSE" );
    xml.IntoElem();

    xml.AddElem( "EXPENSE_ID", expense.getOperationId() );
    lastExpenseID = expense.getOperationId();
    xml.AddElem( "USER_ID", expense.getuUserId() );
    xml.AddElem( "DATE", expense.getDate() );
    xml.AddElem( "ITEM", expense.getItem() );
    xml.AddElem( "AMOUNT", MetodyPomocnicze::doubleToString(expense.getAmount() ));

    xml.Save(FILE_NAME);
}

vector <Expense> ExpensesFile::loadExpensesFromFile(int usersId) {
    CMarkup xml;

    vector <Expense> expenses;
    Expense tempExpense;

    bool fileExists = xml.Load( FILE_NAME);

    if(!fileExists) {
        lastExpenseID = 0;
    }
    xml.FindElem(); //EXPENSES
    xml.IntoElem();

    while(xml.FindElem("EXPENSE")) {

        xml.IntoElem();

        xml.FindElem("EXPENSE_ID");
        string strID = "";

        int id = 0;
        strID = xml.GetData();
        id = MetodyPomocnicze::konwersjaStringNaInt(strID);

        tempExpense.setOperationId(id);
        lastExpenseID = id;

        xml.FindElem("USER_ID");
        string strUID = "";
        int uid = 0;
        strUID = xml.GetData();
        uid = MetodyPomocnicze::konwersjaStringNaInt(strUID);
        tempExpense.setUserId(uid);

        xml.FindElem("DATE");
        string date = "";
        date = xml.GetData();
        tempExpense.setDate(date);

        xml.FindElem("ITEM");
        string item = "";
        item = xml.GetData();
        tempExpense.setItem(item);

        xml.FindElem("AMOUNT");
        string strAmount = "";
        strAmount = xml.GetData();
        double amount;
        amount = stod(strAmount);
        tempExpense.setAmount(amount);

        if (uid == usersId) {
            expenses.push_back(tempExpense);
        }

        xml.OutOfElem();
    }
    return expenses;
}
vector <Expense> ExpensesFile::loadUresrsExpenses(int usersId) {
    CMarkup xml;
    vector <Expense> usersExpenses;
    Expense tempExpense;

    /*bool fileExists = xml.Load( FILE_NAME);

    if(!fileExists) {
        cout << "Nie ma uzytkownikow. Zarejestruj sie";
    }*/
    xml.FindElem(); //EXPENSES
    xml.IntoElem();
    while(xml.FindElem("EXPENSE")) {
        xml.SavePos();
        xml.IntoElem();

        xml.FindElem("EXPENSE_ID");
        string strID = "";
        int id = 0;
        strID = xml.GetData();

        id = MetodyPomocnicze::konwersjaStringNaInt(strID);

        xml.FindElem("USER_ID");
        string strUID = "";
        int uid = 0;
        strUID = xml.GetData();
        uid = MetodyPomocnicze::konwersjaStringNaInt(strUID);

        if (uid == usersId) {

            tempExpense.setOperationId(id);
            tempExpense.setUserId(uid);

            xml.FindElem("DATE");
            string date = "";
            date = xml.GetData();
            tempExpense.setDate(date);

            xml.FindElem("ITEM");
            string item = "";
            item = xml.GetData();
            tempExpense.setItem(item);

            xml.FindElem("AMOUNT");
            string strAmount = "";
            strAmount = xml.GetData();
            //amount = xml.GetData();
            double amount;
            amount = stod(strAmount);
            tempExpense.setAmount(amount);

            usersExpenses.push_back(tempExpense);
            xml.OutOfElem();
        } else {
            xml.RestorePos();
        }
    }

    return usersExpenses;
}
int ExpensesFile::getLastExpenseID() {
    return lastExpenseID;
}
