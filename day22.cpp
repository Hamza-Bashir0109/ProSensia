#include<iostream>
using namespace std;

template<typename T>
T add(T a,T b) { 
    return a+b;
 }
template<typename T>
T subtract(T a,T b){ 
    return a-b;
 }

template<typename T>
T multiply(T a,T b) 
{ 
    return a*b; 
}
template<typename T>
T divide(T a,T b){
    if(b==0){
        cout<<"Error: Division by zero!"<<endl;
        return 0;
    }
    return a/b;
}
template<typename T>
class Calculator {
public:
    T a,b;

Calculator(T x,T y){
        a=x;
        b=y;
    }
void showResults(){
    cout<<"Addition:"<<add(a,b)<<endl;
    cout<<"Subtraction:"<< subtract(a, b)<<endl;
    cout<<"Multiplication:"<< multiply(a,b)<<endl;
    cout<<"Division: "<<divide(a, b)<<endl;
}
};
int main() {
    int choice;
    cout<<"1.int\n2.float\n3.Double\n";
    cin>>choice;
    double x,y;
    cout<<"Enter two values:";
    cin>>x>>y;

    if(choice==1){
        Calculator<int>calc((int)x,(int)y);
        calc.showResults();
    }
    else if(choice==2){
        Calculator<float>calc((float)x,(float)y);
        calc.showResults();
    }
    else if(choice==3){
        Calculator<double> calc(x,y);
        calc.showResults();
    }
    else {
        cout<<"Invalid choice!"<<endl;
    }
    return 0;
}
