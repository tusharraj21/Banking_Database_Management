#include <iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Address
{
    int hno,strno;
    char city[25],state[25],pin[7];
public:
    void getaddr();
    void dispaddr();
};
void Address::getaddr()
{
    cout<<"Enter house no.:";  cin>>hno;
    cout<<"Enter street no:";  cin>>strno;
    cout<<"Enter city name:";  cin>>city;
    cout<<"Enter state:";      cin>>state;
    cout<<"Enter pin code:";   cin>>pin;
}
void Address::dispaddr()
{
    cout<<"House no.:";  cout<<hno; cout<<endl;
    cout<<"Street no:";  cout<<strno; cout<<endl;
    cout<<"City name:";  cout<<city;cout<<endl;
    cout<<"State:";      cout<<state;cout<<endl;
    cout<<"Pin:";        cout<<pin;cout<<endl;
}

class Banker
{
    char name[26],panno[11],aadhar[13];
    int age,accno;
    static int count;
    char gender;
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
    cout<<"Enter Name:";          cin.getline(name,26);
    cout<<"Enter age:";           cin>>age;
    cout<<"Enter gender:(m/f)";   cin>>gender;
    cout<<"Enter PAN no.:";       cin>>panno;
    cout<<"Enter Aadhar no.:";    cin>>aadhar;
    cout<<"Enter address:\n";     a.getaddr();
    deposit();
    accno=count++;
}
void Banker::dispdata()
{
    system("cls");
    cout<<"Name:";             cout<<name;cout<<endl;
    cout<<"Age:";              cout<<age;cout<<endl;
    cout<<"Gender:";           cout<<gender;cout<<endl;
    cout<<"PAN no.:";          cout<<panno;cout<<endl;
    cout<<"Aadhar no.:";       cout<<aadhar;cout<<endl;
    cout<<"Address:\n";        a.dispaddr();cout<<endl;
    cout<<"Account no.:";      cout<<accno;cout<<endl;
    cout<<"Account Balance:";  cout<<balance;cout<<endl;
}
int Banker::giveaccno()
{
    return accno;
}
void Banker::deposit()
{
    float amt;
    cout<<"Enter amount to be deposited:"; cin>>amt;
    balance+=amt;
    cout<<"New balance:"<<balance<<endl;
}
void Banker::withdraw()
{
    float amt;
    cout<<"Enter amount you want to withdraw:"; cin>>amt;
    if(amt<=balance)
        balance-=amt;
    else
        cout<<"Entered amount is less than balance!!! Process not possible!!";
    cout<<"New balance:"<<balance;
}
float Banker::givebal()
{
    return balance;
}

int main()
{
    system("cls");
    Banker b;
    cout<<" \n\n\n\n\n\n\n\n\t\t\t\t\tWELCOME TO THE BANK OF THEIVES\n";
    b.getdata();
    b.dispdata();
    cout<<"Success!!!!!!!";
    return 0;
}

