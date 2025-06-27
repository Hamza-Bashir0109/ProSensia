#include <iostream>
using namespace std;

int main(){

    int number;
    bool a=true;
    cout<<"Ester the number and i will tell you if it is prime or not\n";
    cin>>number;

    for(int i=2;i<number/2;i++){
        if(number%i==0){
        cout<<"The number is not prime\n";
        a=false;
        break;
        }

    }

    if (a==true)
    {
        cout<<" The number is prime\n";
    }
}