#include<iostream>
using namespace std;

class person{
public:
    virtual void display()=0;
    virtual double calculate_salary()=0;
    virtual ~person(){}
};
class employee:public person{
    protected:
    string name;
    double base_salary;
    double bonus;
public:
    employee(string n,double base,double b):name(n),base_salary(base),bonus(b){}
    
    void display(){
        cout<<"employee: "<<name<<endl;
        cout<<"salary: "<<calculate_salary()<<endl;
    }

    double calculate_salary(){
        return base_salary+bonus;
    }
};
class intern:public person{
    private:
    string name;
    double stipend;
public:
    intern(string n,double s):name(n),stipend(s){}

    void display(){
        cout<<"intern: "<<name<<endl;
        cout<<"salary: "<<calculate_salary()<<endl;
    }

    double calculate_salary(){
        return stipend;
    }
};
int main(){
    person* p1=new employee("hamza",50000,5000);
    person* p2=new intern("ali",10000);

    p1->display();
    p2->display();
    delete p1;
    delete p2;

    return 0;
}
