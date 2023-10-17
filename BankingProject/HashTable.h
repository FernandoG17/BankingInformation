#include <iostream>
#include <functional>
#include "UserInfo.h"
using namespace std; 

class HashTable{
private: 
    userData **hashTable;
    int hashTableSize; 
    int numberOfKeys;
    double loadFactorThreshold; 

public:
    HashTable(){
        hashTableSize = 10;
        hashTable = new userData*[hashTableSize];
        for(int i =0; i< hashTableSize; i++){
            hashTable[i] = nullptr;
        }
        numberOfKeys = 0; 
        loadFactorThreshold = 0.75;
    }

    ~HashTable(){
        for(int i = 0; i< hashTableSize;i++){
            delete hashTable[i];
        }
        delete hashTable;
    }

    bool Search(int userN){
        if(hashTable[userN] != nullptr){
            return true;
        }
    return false;
    }

    void InsertNewUser(int index, string name, int accN, int cheB, int savB, int avaiC){
        double loadFactor = static_cast<double>(numberOfKeys) / hashTableSize;
        if (loadFactor > loadFactorThreshold) {
            reHash();
        }
        hashTable[index] = new userData;
        hashTable[index]->Insert(name, accN, cheB, savB, avaiC);
        numberOfKeys++;
    }

    void DisplayInfo(int index){
        if(hashTable[index] == nullptr){
            cout << "User with that account number does not exist" << endl;
            return;
        }
        hashTable[index]->Display();
    }

    void reHash(){
        int newSize = hashTableSize*2;
        userData** copyTable = new userData*[newSize];
        for(int i =0; i< hashTableSize; i++){
            if(hashTable[i]!= nullptr){
                copyTable[i] = new userData;
                copyTable[i]->name = hashTable[i]->name; 
                copyTable[i]->accountNumber = hashTable[i]->accountNumber;
                copyTable[i]->chequingBalance = hashTable[i]->chequingBalance;
                copyTable[i]->savingsBalance = hashTable[i]->savingsBalance;
                copyTable[i]->avaiCredit = hashTable[i]->avaiCredit;
            }
        }
        delete[] hashTable;
        hashTable = copyTable;
        hashTableSize = newSize;
    }

    void withdrawCheq(int withdraw, int accountNumber){
        if(withdraw > hashTable[accountNumber]->chequingBalance){
            cout << "Cannot withdraw more than current balance." << endl;
            return;
        }
        hashTable[accountNumber]->chequingBalance = hashTable[accountNumber]->chequingBalance - withdraw;
    }

    void withdrawSav(int withdraw, int accountNumber){
        if(withdraw > hashTable[accountNumber]->savingsBalance){
            cout << "Cannot withdraw more than current balance." << endl;
            return;
        }
        hashTable[accountNumber]->savingsBalance = hashTable[accountNumber]->savingsBalance - withdraw;
    }

    void depositCheq(int deposit, int accountNumber){
        hashTable[accountNumber]->chequingBalance = hashTable[accountNumber]->chequingBalance + deposit; 
    }

    void depositSav(int deposit, int accountNumber){
        hashTable[accountNumber]->savingsBalance = hashTable[accountNumber]->savingsBalance + deposit;
    }

    void changeCLimit(int newLimit, int accountNumber){
        hashTable[accountNumber]->avaiCredit = newLimit;
    }

    void displayC(int accN){
        cout << hashTable[accN]->chequingBalance << endl;
    }

    void displayS(int accN){
        cout << hashTable[accN]->savingsBalance << endl;
    }

    void displayCL(int accN){
        cout << hashTable[accN]->avaiCredit << endl;
    }

    void deleteUser(int accN){
        if(hashTable[accN] == nullptr){
            cout << "User cannot be deleated since it does not exist." << endl;
        }
        hashTable[accN] = nullptr;
    }

    void displayHashTable(){
        for(int i = 0; i< hashTableSize;i++){
            if(hashTable[i]!=nullptr){
                cout << "Name: " << hashTable[i]->name << ". Account Number: " << hashTable[i]->accountNumber << endl;
            }
        }
    }

};