#include "Bank.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

Bank::Bank()
{
    //ctor
}

int Bank::foundAccount(int id)
{
    for ( int i=0; i<bankaccounts.size(); i++)
    {
        if (bankaccounts[i].getAccount_number()== id)
        {
            return i;
        }
    }
    return -1;
}
bool Bank::vaildPassword(int indx,string password)
{
    return bankaccounts[indx].get_password()==password;
}

void Bank::create_account(int account_id, string account_name,int amount,string password)
{
    BankAccount new_account(account_id, account_name, amount,password);
    bankaccounts.push_back(new_account);
}
void Bank::get_account(int indx)
{

    bankaccounts[indx].display_account_info();
}
void Bank::deposit(int indx,int  amount)
{

    cout<<"\n\n\n\t\tRecored Updated..";
    cin.get();
    bankaccounts[indx].deposit(amount);


}
void Bank::withdraw(int account_id,int  amount)
{
    int id=foundAccount(account_id);
    if(id==-1)
        cout << "Account not found.\n";
    else
    {

        bankaccounts[id].withdraw(amount);
    }
}
void Bank::closeaccount(int indx)
{

    swap(bankaccounts[indx],bankaccounts[bankaccounts.size()-1]);
    bankaccounts.pop_back();


    cout<<"\n\n\t\tDone...\n";
    cin.get();
}
void Bank::transformation(int idFrom,int idTo,int amount)
{



    if (bankaccounts[idFrom].get_balance() < amount)
    {
        cout << "\n\n\t\tYour balance is not enough.\n";
        cin.get();
        return;
    }

    bankaccounts[idFrom].withdraw(amount);
    bankaccounts[idTo].deposit(amount);

    cout << "\n\n\t\tDone...\n";
    cin.get();
}

void Bank::allAccounts()
{
    cout << "\t+------------------+----------------------+------------------+\n";
    cout << "\t|      ID          |         Name         |      Amount      |\n";
    cout << "\t+------------------+----------------------+------------------+\n";

    for (int i = 0; i < bankaccounts.size(); i++)
    {
        cout << "\t|" << setw(18) << bankaccounts[i].getAccount_number() << "|"
             << setw(22) << bankaccounts[i].getAccount_holder() << "|"
             << setw(18) << bankaccounts[i].get_balance() << "|\n";
    }

    cout << "\t+------------------+----------------------+------------------+\n";
    cin.get();

}

void Bank::modifyAccount(int index)
{


    cout << "\n\t\tCurrent Details:\n";
    cout << "\t\tID        : " << bankaccounts[index].getAccount_number() << endl;
    cout << "\t\tName      : " << bankaccounts[index].getAccount_holder() << endl;
    cout << "\t\tPassword   : " << bankaccounts[index].get_password() << endl;
    cout << "\t\tAmount    : " << bankaccounts[index].get_balance() << endl;


    cout << "\n\t\tEnter new details:\n";
    cout << "\t\tNew Name      : ";
    string newname;
    cin >> newname;
    cout << "\t\tNew Pasword   : ";
    string pass;
    cin >> pass;
    bankaccounts[index].set_account_holder(newname);
    bankaccounts[index].set_password(pass);


    cout << "\n\t\tAccount details modified.\n";
    cin.get();
}




