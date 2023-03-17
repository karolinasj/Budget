#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include "Income.h"
#include "MetodyPomocnicze.h"
#include "PlikXML.h"

using namespace std;

class IncomesFile : public PlikXML{

    Income getIncomeData(string dane);
    int lastIncomeID;
    int loadIncomesFromFile();

public:
    IncomesFile(string incomesFileName) : PlikXML(incomesFileName) {
    //lastIncomeID = loadIncomesFromFile();
    };

    void addIncomeToFile(Income income);
    vector <Income> loadUresrsIncomes(int userId);
    vector <Income> loadDataFromFile(int usersId);
    int getLastIncomeID();

};
#endif
