#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#include "BankAccount.h"

using namespace std;

class Bank
{
    vector<BankAccount> bankaccounts;

public:
    Bank() ;
    int foundAccount(int id);

    bool vaildPassword(int indx,string pass);

    void create_account(int account_id, string account_name,int amount,string password);

    void get_account(int account_id);


    void deposit(int account_id,int  amount);


    void withdraw(int account_id,int  amount);

    void closeaccount(int account_id);

    void transformation(int idFrom,int idTo,int amount);

    void allAccounts();

    void modifyAccount(int id);


};

#endif // BANK_H
