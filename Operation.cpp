#include "Operation.h"

int Operation::getuUserId() {
    return userId;
}
double Operation::getAmount() {
    return amount;
}
string Operation::getDate() {
    return date;
}
string Operation::getItem() {
    return item;
}

void Operation::setOperationId(int newOperationId) {
    operationId = newOperationId;
}
void Operation::setUserId(int newUserId) {
    userId = newUserId;
}
void Operation::setDate(string newDate) {
    date = newDate;
}
void Operation::setItem(string newItem) {
    item = newItem;
}
void Operation::setAmount(double newAmount) {
    amount = newAmount;
}
