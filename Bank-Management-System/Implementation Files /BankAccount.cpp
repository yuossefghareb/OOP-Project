#include "BankAccount.h"
#include <vector>
#include <iomanip>
#include <string>
using namespace std;


BankAccount::BankAccount(int accid, string accname, int accbala,string pass)
{
    account_number = accid;
    account_holder = accname;
    balance = accbala;
    password=pass;
}


void BankAccount:: deposit(int amount)
{
    balance += amount;

}
void BankAccount:: withdraw(int amount)
{
    if (balance - amount < 0)
    {
        cout << "\n\n\t\tYour balance is not enough.\n";
    }
    else
    {
        balance -= amount;
        cout<<"\n\n\t\tSucessed...\n";
    }
    cin.get();
}
int BankAccount:: get_balance()
{
    return balance;
}
void BankAccount:: display_account_info()
{
    cout << "Account No          : " << account_number << endl;
    cout << "Account Holder Name : " << account_holder << endl;
    cout << "password            : " << password << endl;
    cout << "Balance             : " << balance << endl;
}

int BankAccount::getAccount_number()
{
    return account_number;
}
string BankAccount::getAccount_holder()
{
    return account_holder;
}
void BankAccount::set_account_holder(string newname)
{
    account_holder=newname;
}
string BankAccount::get_password()
{
    return password;
}
void BankAccount::set_password(string pass)
{
    password=pass;
}


