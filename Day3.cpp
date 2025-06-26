#include <iostream>
using namespace std;

int main(){

    string name;
    int age;
    float gpa;
    cout<<"Enter your name:\n";
    cin>>name;
    cout<<"Enter your age:\n";
    cin>>age;
    cout<<"Enter your cgpa:\n";
    cin>>gpa;

    if(age>=18)
    {
        if(gpa<=2.5)
        cout<<"You are not elgible to apply as your cgpa is less than 2.5\n";
        else
        cout<<"You are sligble to apply\n";

    }
    
    else 
    {
        cout<<"you are not elgible to apply as your age is less than 18\n";
    }

    return 0;
}