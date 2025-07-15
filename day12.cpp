#include <iostream>
#include <string>
using namespace std;

 class bank{
    private:
    int account;
    string name;
    float balance;

    public:
     bank(int a,string n,float b){
        account=a;
        name=n;
        balance=b;

    }
    void deposit(int money){
        if(money>=0){
            balance+=money;
        }
        else 
        cout<<"the deposut amount should be positive\n";

    }
    void withdrawal(int amount){
         if(balance>amount){
            balance-=amount;
            cout<<"You have withdrawed "<<amount<<endl;
         }
         else 
         cout<<"balance is not sufficient for withdraw\n";

    }
    void display(){
        cout<<"The account number is : "<<account<<endl;
       cout<<"The name of account holder is : "<<name<<endl;
       cout<<"The balance is : "<<balance<<endl;
    }
    


 };
 int main(){
     bank account1(1001, "Alice", 5000.0);
    bank account2(1002, "Bob", 3000.0);

    
    account1.display();
    account1.deposit(1500);
    account1.withdrawal(2000);
    account1.display();

    
    account2.display();
    account2.deposit(1000);
    account2.withdrawal(5000); 
    account2.display();
    
 }