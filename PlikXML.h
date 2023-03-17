#ifndef PLIKXML_H
#define PLIKXML_H

#include <fstream>
#include "Markup.h"

using namespace std;

class PlikXML {
protected:
    const string FILE_NAME;

public:
    PlikXML(string fileName) : FILE_NAME(fileName){};
    bool checkIfFileIsEmpty(fstream &plikXML);
    string getFileName();
};
#endif
