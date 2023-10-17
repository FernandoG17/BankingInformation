#include <iostream>
using namespace std;

class userData{
public:
    string name;
    int accountNumber;
    int chequingBalance;
    int savingsBalance; 
    int avaiCredit;

    userData(){
        name = "";
        accountNumber = 0;
        chequingBalance = 0;
        savingsBalance = 0; 
        avaiCredit = 0;
    }

    void Insert(string name, int accN, int cheB, int savB, int avaiC){
        this->name = name;
        accountNumber = accN;
        chequingBalance = cheB;
        savingsBalance = savB;
        avaiCredit = avaiC;
    }

    void Display(){
        cout << "User Information: " << endl;
        cout << "------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Account number:    " << accountNumber << endl;
        cout << "Chequings Balance: " << chequingBalance << endl;
        cout << "Savings Balance:   " << savingsBalance << endl;
        cout << "Available CreditL  " << avaiCredit << endl;
    }

};
