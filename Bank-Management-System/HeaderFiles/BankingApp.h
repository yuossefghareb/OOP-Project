#ifndef BANKINGAPP_H
#define BANKINGAPP_H
#include <vector>
#include <iomanip>
#include <string>
#include "Bank.h"
using namespace std;


class BankingApp
{
    Bank bank;
    int helper_found_id();
    int helper_vaildpass(int it);
public:
    BankingApp();

    void intro();

    void menu();

    void new_account();

    void modify();

    void depoist_account();

    void withdarw_account();

    void Exit();

    void closeAccount();


    void transformation();

};
#endif // BANKINGAPP_H
