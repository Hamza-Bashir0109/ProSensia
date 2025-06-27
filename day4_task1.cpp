#include <iostream>
using namespace std;

int main(){
    int number,reversed;
    cout<<"Enter a number\n";
    cin>>number;

    while(number!=0){
        reversed=number%10;
        cout<<reversed;
        number=number/10;
    }

}