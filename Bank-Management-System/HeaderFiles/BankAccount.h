#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <vector>
#include <iomanip>
#include<string>

using namespace std;


class BankAccount
{
private:
    int account_number;
    string account_holder;
    int balance;
    string password;
public:

    BankAccount(int accid, string accname, int accbala,string pass);
    void deposit(int amount);
    void withdraw(int amount);
    int get_balance();
    void display_account_info();
    int getAccount_number();
    string getAccount_holder();
    void set_account_holder(string newname);
    string get_password();
    void set_password(string pass);




};

#endif // BANKACCOUNT_H
