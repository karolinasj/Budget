#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income) {
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if(!fileExists) {
        xml.AddElem( "INCOMES" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "INCOME" );
    xml.IntoElem();

    xml.AddElem( "INCOME_ID", income.getOperationId() );
    lastIncomeID = income.getOperationId();
    xml.AddElem( "USER_ID", income.getuUserId() );
    xml.AddElem( "DATE", income.getDate() );
    xml.AddElem( "ITEM", income.getItem() );
    xml.AddElem( "AMOUNT", MetodyPomocnicze::doubleToString(income.getAmount() ));

    xml.Save(FILE_NAME);
}
/*int IncomesFile::loadIncomesFromFile() {
    CMarkup xml;
    vector <Income> incomes;
    Income tempIncome;

    bool fileExists = xml.Load( FILE_NAME);

    if(!fileExists) {
        lastIncomeID = 0;
        return lastIncomeID;
    }
    xml.FindElem(); //INCOMES
    xml.IntoElem();

    while(xml.FindElem("INCOME")) {

        xml.IntoElem();

        xml.FindElem("INCOME_ID");
        string strID = "";
        int id = 0;
        strID = xml.GetData();
        id = MetodyPomocnicze::konwersjaStringNaInt(strID);
        tempIncome.setOperationId(id);
        lastIncomeID = id;

        xml.FindElem("USER_ID");
        string strUID = "";
        int uid = 0;
        strUID = xml.GetData();
        uid = MetodyPomocnicze::konwersjaStringNaInt(strUID);
        tempIncome.setUserId(uid);

        xml.FindElem("DATE");
        string date = "";
        date = xml.GetData();
        tempIncome.setDate(date);

        xml.FindElem("ITEM");
        string item = "";
        item = xml.GetData();
        tempIncome.setItem(item);

        xml.FindElem("AMOUNT");
        string strAmount = "";
        strAmount = xml.GetData();
        double amount;
        amount = stod(strAmount);
        tempIncome.setAmount(amount);

        incomes.push_back(tempIncome);
        xml.OutOfElem();
    }
    return lastIncomeID;
}*/
vector <Income> IncomesFile::loadDataFromFile(int usersId) {
    CMarkup xml;
    vector <Income> incomes;
    Income tempIncome;

    bool fileExists = xml.Load( FILE_NAME);

    if(!fileExists) {
        lastIncomeID = 0;
    }
    xml.FindElem(); //INCOMES
    xml.IntoElem();

    while(xml.FindElem("INCOME")) {

        xml.IntoElem();

        xml.FindElem("INCOME_ID");
        string strID = "";
        int id = 0;
        strID = xml.GetData();
        id = MetodyPomocnicze::konwersjaStringNaInt(strID);
        tempIncome.setOperationId(id);
        lastIncomeID = id;

        xml.FindElem("USER_ID");
        string strUID = "";
        int uid = 0;
        strUID = xml.GetData();
        uid = MetodyPomocnicze::konwersjaStringNaInt(strUID);
        tempIncome.setUserId(uid);

        xml.FindElem("DATE");
        string date = "";
        date = xml.GetData();
        tempIncome.setDate(date);

        xml.FindElem("ITEM");
        string item = "";
        item = xml.GetData();
        tempIncome.setItem(item);

        xml.FindElem("AMOUNT");
        string strAmount = "";
        strAmount = xml.GetData();
        double amount;
        amount = stod(strAmount);
        tempIncome.setAmount(amount);

        if (uid == usersId){
            incomes.push_back(tempIncome);
        }

        xml.OutOfElem();
    }
    return incomes;
}
vector <Income> IncomesFile::loadUresrsIncomes(int usersId) {

    CMarkup xml;
    vector <Income> usersIncomes;
    Income tempIncome;

    /*bool fileExists = xml.Load( FILE_NAME);

    if(!fileExists) {
        cout << "Nie ma operacji. Dodaj przychod";
    }*/

    xml.FindElem(); //INCOMES
    xml.IntoElem();
    while(xml.FindElem()){//"INCOME")) {

        xml.SavePos();
        xml.IntoElem();

        xml.FindElem("INCOME_ID");
        string strID = "";
        int id = 0;
        strID = xml.GetData();

        id = MetodyPomocnicze::konwersjaStringNaInt(strID);

        xml.FindElem("USER_ID");
        string strUID = "";
        int uid = 0;
        strUID = xml.GetData();
        uid = MetodyPomocnicze::konwersjaStringNaInt(strUID);
        cout << uid <<endl << usersId;
        system("pause");
        if (uid == usersId) {

            tempIncome.setOperationId(id);
            tempIncome.setUserId(uid);

            xml.FindElem("DATE");
            string date = "";
            date = xml.GetData();
            tempIncome.setDate(date);

            xml.FindElem("ITEM");
            string item = "";
            item = xml.GetData();
            tempIncome.setItem(item);

            xml.FindElem("AMOUNT");
            string strAmount = "";
            strAmount = xml.GetData();
            //amount = xml.GetData();
            double amount;
            amount = stod(strAmount);
            tempIncome.setAmount(amount);

            usersIncomes.push_back(tempIncome);

            xml.OutOfElem();
        } else {
            xml.RestorePos();
        }
    }

    return usersIncomes;
}
int IncomesFile::getLastIncomeID() {
    return lastIncomeID;
}
