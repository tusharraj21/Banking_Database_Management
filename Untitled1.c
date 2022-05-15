#include<iostream>
#include<conio.h>
//#include<brightuse.h>
#include<string.h>
#include<fstream>
#include<process.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
void clrscr()
{
    system("cls") ;
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock() ;
    while (goal > clock()) ;
}

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
void textattr(int att)
{
    SetConsoleTextAttribute(h,att);
}

using namespace std;
void gets2(char str[])
{
    int i=0;
    char ch;
    do
    {
        ch=getch();
        switch(ch)
        {
            case 13:break;
            case 8:--i;
                   cout<<"\b \b";
                   break;
            default: str[i]=ch;
                     cout<<ch;
                     ++i;
        }

    }while(ch!=13);
    str[i]='\0';
    cout<<"\n";;
}

class Address
{
    int hno;
    char str[50], city[25],state[25],pin[7];
public:
    void getaddr();
    void dispaddr();
};
void Address::getaddr()
{
    cout<<"Enter house no.:";                cin>>hno;
    cout<<"Enter street:";                   gets2(str);
    cout<<"Enter city name:";                gets2(city);
    cout<<"Enter state:";                    gets2(state);
    cout<<"Enter pin:";                      cin>>pin;
}
void Address::dispaddr()
{
    cout<<"\nHouse no.:";                 cout<<hno;
    cout<<"\nStreet:";                     cout<<str;
    cout<<"\nCity name:";                 cout<<city;
    cout<<"\nState:";                     cout<<state;
    cout<<"\nPin:";                       cout<<pin;
}

class Banker
{
    char name[26];
    int age,accno;
    static int count;
    char gender;
    char panno[11],aadhar[13];
    float balance;
    Address a;
public:
    void getdata();
    void dispdata();
    int giveaccno();
    void deposit();
    void withdraw();
    float givebal();
    void changeaddr();
};
int Banker::count=1;
void Banker::getdata()
{
    cout<<"Enter Name:";             gets2(name);
    cout<<"Enter age:";              cin>>age;
    cout<<"Enter gender:(m/f)";      cin>>gender;
    cout<<"Enter PAN no.:";          cin>>panno;
    cout<<"Enter Aadhar no.:";       cin>>aadhar;
    cout<<"Enter address:\n";        a.getaddr();
    accno=count++;
    cout<<"Your Account Number is:"; cout<<accno;
    deposit();
}
void Banker::dispdata()
{
    cout<<"\nName:";             cout<<name;
    cout<<"\nAge:";              cout<<age;
    cout<<"\nGender:";           cout<<gender;
    cout<<"\nPAN no.:";          cout<<panno;
    cout<<"\nAadhar no.:";       cout<<aadhar;
    cout<<"\nAddress:\n";        a.dispaddr();
    cout<<"\nAccount no.:";      cout<<accno;
    cout<<"\nAccount Balance:";  cout<<balance;
}
int Banker::giveaccno()
{
    return accno;
}
void Banker::deposit()
{
    float amt;
    cout<<"\nEnter amount to be deposited:"; cin>>amt;
    balance+=amt;
    cout<<"New balance:"<<balance;
}
void Banker::withdraw()
{
    float amt;
    cout<<"Enter amount you want to withdraw:"; cin>>amt;
    if(amt<=balance)
        balance-=amt;
    else
        cout<<"Entered amount is more than balance!!! Process not possible!!";
    cout<<"New balance:"<<balance;
}
float Banker::givebal()
{
    return balance;
}

int main()
{
    textattr(30);
    clrscr();
    //cout<<"------------------Prototype-----------------------\n";
    cout<<"\tThis is the Investigatory Project done by:\n\t   1)P.Aswin Kumar\n\t   2)S.Shankar\n\t   3)Tushar Raj \n\t   4)Dharanishri";
    delay(3000);
    Banker b[100];
    int num=0,acno,i,flag=0;
    char ans='y',ch;
    while(1)
    {
    clrscr();
    cout<<"\tWelcome to ASTD bank!!\t\n";
    cout<<"\tMain Menu:";
    cout<<"\n\t 1.Create a new account.";
    cout<<"\n\t 2.Deposit amount.";
    cout<<"\n\t 3.Withdraw amount.";
    cout<<"\n\t 4.Get details.";
    cout<<"\n\t 5.Exit.";
    cout<<"\n\n\t Enter your selection:";
    cin>>ch;
    switch(ch)
    {
        case '1':while((ans=='y'||ans=='Y')&&num<100)
                 { b[num].getdata();
                   num++;
                   cout<<"\nWant to create more?";
                   cin>>ans;
                 }
                 break;
        case '2':cout<<"Enter account number:";
                 cin>>acno;
                 for(i=0;i<100;++i)
                 {
                     int acccno=b[i].giveaccno();
                     if(acccno==acno&&flag==0)
                     {
                         b[i].deposit();
                         flag=1;
                     }
                 }
                 if(flag!=1)
                    cout<<"Invalid account no.";
                    flag=0;
                    getch();
                 break;
        case '3':cout<<"Enter account number:";
                 cin>>acno;
                 for(i=0;i<100;++i)
                 {
                     int acccno=b[i].giveaccno();
                     if(acccno==acno&&flag==0)
                     {
                         b[i].withdraw();
                         flag=1;
                     }
                 }
                 if(flag!=1)
                    cout<<"Invalid account no.";
                    flag=0;
                    getch();
                    break;
        case '4':cout<<"Enter account number:";
                 cin>>acno;
                 for(i=0;i<100;++i)
                 {
                     int acccno=b[i].giveaccno();
                     if(acccno==acno&&flag==0)
                     {
                         b[i].dispdata();
                         flag=1;
                     }
                 }
                 if(flag!=1)
                    cout<<"Invalid account no.";
                      flag=0;
                    getch();
                 break;
        case '5':cout<<"Thank you!!";
                 getch();
                 exit(0);
                 break;
    }
    }
    cout<<"Success!!!!!!!";
    getch();
    return 0;
}
