#include "BankingApp.h"

#include <vector>
#include <iomanip>
#include <string>
using namespace std;

BankingApp::BankingApp()
{
    intro();
}

void BankingApp:: intro()
{
    cout << "\n\n\n\t  BANK";
    cout << "\n\n\tMANAGEMENT";
    cout << "\n\n\t  SYSTEM";
    cout << "\n\n\n\nMADE BY :Youssef Gharieb Abbas";
    cin.get();
    system("cls");
    menu();
}
void BankingApp:: menu()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. NEW ACCOUNT";
        cout << "\n\n\t02. DEPOSIT AMOUNT";
        cout << "\n\n\t03. WITHDRAW AMOUNT";
        cout << "\n\n\t04. TRANSFERMATION To ANOTHER ACCOUNT";
        cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t06. CLOSE AN ACCOUNT";
        cout << "\n\n\t07. MODIFY AN ACCOUNT";
        cout << "\n\n\t08. EXIT";
        cout << "\n\n\tSelect Your Option (1-8) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 1:
            new_account();
            break;
        case 2:
            depoist_account();
            break;
        case 3:
            withdarw_account();
            break;
        case 4:
            transformation();
            break;
        case 5:
            bank.allAccounts();
            break;
        case 6:
            closeAccount();
            break;
        case 7:
            modify();
            break;
        case 8:
            Exit();
            break;


        }
        cin.ignore();
        cin.get();
    }
    while (ch != 8);

}
void BankingApp:: new_account()
{
    int id;
    string name,pass;
    int amount;
    cout<<"Enter The account No. (8 digits): ";
    cin>>id;
    cout<<"\n\n";
    cout<<"Enter The Name of the account Holder : ";
    cin>>name;
    cout<<"\n\n";

    cout<<"Enter  New Password for Your account : ";
    cin>>pass;
    cout<<"\n\n";

    cout<<"Enter The Initial amount for account : ";
    cin>>amount;
    cout<<"\n\n\n\n";

    bank.create_account(id,name,amount,pass);

    system("cls");
    menu();
}

void BankingApp:: modify()
{
    int it=helper_found_id();
    if(it==-1)return;
    cout<<"\n\n";
    int v=helper_vaildpass(it);
    if(v==-1)
        return;

    bank.modifyAccount(it);
    cin.get();
    system("cls");
    menu();
}

int BankingApp::helper_found_id()
{
    int id;
    cout<<"\t\tEnter The account No. : ";
    cin>>id;
    cout<<"\n\n";

    int it=bank.foundAccount(id);
    while(it==-1)
    {
        string s;


        cout << "\t\tAccount not found...\n";
        cout<<"\n\t\tTo Compelet enter (Y/y) or (N/n) to Exit";
        cin>>s;
        if(s=="N"||s=="n")
            return -1;
        cout<<"\n\t\tEnter again account No. : ";
        cin>>id;

        it=bank.foundAccount(id);
    }
    return it;
}
int BankingApp::helper_vaildpass(int it)
{
    string password;
    cout<<"\t\tEnter Password No. : ";
    cin>>password;
    int p=bank.vaildPassword( it,password);
    while(!p)
    {
        string s;
        cout << "\n\n\t\Invilad Password.. \n\n";
        cout<<"\n\t\tTo Compelet enter (Y/y) or (N/n) to Exit";
        cin>>s;
        if(s=="N"||s=="n")
            return -1;
        cout<<"\n\t\tEnter again Password No. : ";
        cin>>password;
        p=bank.vaildPassword( it,password);

    }
    return 1;
}
void  BankingApp:: depoist_account()
{

    int it=helper_found_id();
    if(it==-1)return;
    cout<<"\n\n";
    int v=helper_vaildpass(it);
    if(v==-1)
        return;

    cout<<"\n\n";
    bank.get_account(it);
    cout<<"\n\n\t\tTo DEPOSITE AMOUNT \n\n";
    int amount;
    cout<<"Enter The Amount to be deposited : ";
    cin>>amount;
    bank.deposit(it,amount);

    cin.get();
    system("cls");
    menu();

}

void BankingApp:: withdarw_account()
{
    int it=helper_found_id();
    if(it==-1)return;
    cout<<"\n\n";
    int v=helper_vaildpass(it);
    if(v==-1)
        return;

    cout<<"\n\n";

    bank.get_account(it);
    cout<<"\n\n\t\tTo WITHDRAW AMOUNT \n\n";
    int amount;
    cout<<"Enter The Amount to be withdraw : ";
    cin>>amount;
    bank.withdraw(it,amount);
    cin.get();
    system("cls");
    menu();

}

void  BankingApp:: Exit()
{
    cout << "\n\n\tThanks for using bank managemnt system\n\n\n";
    exit(0);
}

void BankingApp:: closeAccount()
{
    int it1=helper_found_id();
    if(it1==-1)return;
    cout<<"\n\n";
    int v=helper_vaildpass(it1);
    if(v==-1)
        return;

    bank.closeaccount(it1);
    cin.get();
    system("cls");
    menu();

}

void BankingApp:: transformation()
{

    int it1=helper_found_id();
    if(it1==-1)return;
    cout<<"\n\n";
    int v=helper_vaildpass(it1);
    if(v==-1)
        return;

    cout<<"\n\nSecond Account \n\n";

    int it2=helper_found_id();
    if(it2==-1)return;


    cout<<"\n\n";

    int amount;
    cout<<"\t\tEnter The Amount That You Want Tarnsofrm. : ";
    cin>>amount;
    bank.transformation(it1,it2,amount);

    cin.get();
    system("cls");
    menu();

}
