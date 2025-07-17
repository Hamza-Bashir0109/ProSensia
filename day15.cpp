#include <iostream>
using namespace std;
class employee{
    protected:
    string name;
    int id;
    float salary;
    public:
    employee(string n, int i, float s) {
        name=n;
        id=i;
        salary=s;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: $"<<salary<<endl;
    }
};
class manager: public employee
{
private:
    float bonus;
public:
    manager(string n, int i, float s, float b) : employee(n, i, s) {
        bonus = b;
    }
    void Manager() {
        display();
        cout<<"Bonus: $"<<bonus<<endl;
    }
};
class developer:public employee{
private:
    string programming_lang;
  
public:
    developer(string n, int i, float s, string p) : employee(n, i, s) {
        programming_lang=p;
    }
    void Display() {
        display();
        cout<<"Programming languauge : "<<programming_lang<<endl;
    }
    
};

int main() {
    
    manager m("Ali",101,75000,5000.0);
    cout<<"Manager Info"<<endl;
    m.Manager();
    cout<<endl;
    developer d("Bilal",102,60000,"C++");
    cout<<"Developer Info"<<endl;
    d.Display();
    return 0;
}