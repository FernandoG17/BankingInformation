#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

HashTable User;
int accountNumber;
int choice;
int userCount = 0;
string name; 
int choice2;
int amount;

class DM{
public:
    void Menu(){
            while (true){
            cout << "| SCOTIABANK |" << endl;
            cout << "--------------" << endl;
            cout << "1. To insert new user. " << endl;
            cout << "2. To delete user.  " << endl;
            cout << "3. To make changes in an account." << endl;
            cout << "4. To display information of a user. " << endl;
            cout << "5. To display table of users. " << endl;
            cout << "0 to exit." << endl;
            cin >> choice;

            if(choice == 0){
                break;
            }

            switch (choice){
                case 1: cout << "Please enter the name: "; 
                        cin.ignore();
                        getline(cin, name);
                        User.InsertNewUser(userCount,name, userCount, 0,0,1000);
                        cout << "User created. Account number: " << userCount << endl;
                        userCount++;
                        break;
                case 2: cout << "Enter user account number: ";
                        cin >> accountNumber;
                        User.deleteUser(accountNumber);
                        cout << "User deleted" << endl;
                        break;
                case 3: cout << "Enter user account number: "; 
                        cin >> accountNumber;
                        cout << "1. Withdraw from checking account." << endl;
                        cout << "2. To make a deposit to checking account " << endl;
                        cout << "3. Withdraw from savings account." << endl;
                        cout << "4. To make a deposit to savings account." << endl;
                        cout << "5. Change credit limit" << endl;  
                        cin >> choice2;
                        switch (choice2){
                            case 1: cout << "Enter the amount you want to withdraw: ";
                                    cin >> amount;
                                    User.withdrawCheq(amount, accountNumber);
                                    cout << "New balance: ";
                                    User.displayC(accountNumber);
                                    cout << endl;
                                    break;
                            case 2: cout << "Enter the amount you want to deposit: ";
                                    cin >> amount;
                                    User.depositCheq(amount, accountNumber);
                                    cout << "New balance: ";
                                    User.displayC(accountNumber);
                                    cout << endl;
                                    break;
                            case 3: cout << "Enter the amount you want to withdraw: ";
                                    cin >> amount;
                                    User.withdrawSav(amount, accountNumber);
                                    cout << "New balance: ";
                                    User.displayS(accountNumber);
                                    cout << endl;
                                    break;
                            case 4: cout << "Enter the amount you want to deposit: ";
                                    cin >> amount;
                                    User.depositSav(amount, accountNumber);
                                    cout << "New balance: ";
                                    User.displayS(accountNumber);
                                    cout << endl;
                                    break;
                            case 5: cout << "Please enter the new credit card limit: ";
                                    cin >> amount; 
                                    User.changeCLimit(amount,accountNumber);
                                    cout << "New balance: ";
                                    User.displayCL(accountNumber);
                                    cout << endl;
                                    break;
                            default: cout << "Not an option." << endl;
                                    break;
                        }
                        break;

                case 4: cout << "Please enter the account number: ";
                        cin >> accountNumber; 
                        User.DisplayInfo(accountNumber);
                        cout << endl;
                        break;
                case 5: User.displayHashTable();
                        break;
                default: cout << "Option does not exist." << endl;
                        break;
            }
            
        }
    }

};

        