#ifndef OPERATION_H
#define OPERATION_H

#include "Markup.h"
#include <vector>

using namespace std;

class Operation {
protected:
    int operationId, userId;
    string date, item;
    double amount;
public:
    int getOperationId();
    int getuUserId();
    double getAmount();
    string getDate();
    string getItem();

    void setOperationId(int newOperationId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

};
#endif
