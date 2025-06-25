#include <iostream>
using namespace std;

int main() {
    int mark1, mark2, mark3;
    int total_marks;
    float average;
    char grade;

    cout<<"Enter marks for Subject 1: ";
    cin>>mark1;
    cout<<"Enter marks for Subject 2: ";
    cin>>mark2;
    cout<<"Enter marks for Subject 3: ";
    cin>>mark3;

    total_marks=mark1+mark2+mark3;
    average=total_marks/3.0;

    if(average>=80){
        grade='A';
    } else if(average>=60){
        grade='B';
    } else if(average>=40){
        grade='C';
    } else{
        grade='F'; 
    }

    cout<<"Total Marks= "<<total_marks<<endl;
    cout<<"Average= "<<average<<endl;
    cout<<"Grade= " <<grade<<endl;
    return 0;
}

