#include "PlikXML.h"

bool PlikXML::checkIfFileIsEmpty(fstream &plikXML) {
    plikXML.seekg(0, ios::end);
    if (plikXML.tellg() == 0)
        return true;
    else
        return false;
}

string PlikXML::getFileName() {
    return FILE_NAME;
}
