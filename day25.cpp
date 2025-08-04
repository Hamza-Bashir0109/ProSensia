#include<iostream>
#include<fstream>
using namespace std;

class DivisionByZero:public exception{
public:
    const char* what()const throw(){
        return "Error: Division by zero!";
    }
};
class InvalidInput:public exception{
public:
    const char* what()const throw(){
        return "Error: Invalid input!";
    }
};
class Calculator{
    double num1,num2;
    char op;
public:
    void input(){
        cout<<"Enter expression (e.g., 5 + 2): ";
        cin>>num1>>op>>num2;

        if(cin.fail()){
            throw InvalidInput();
        }
    }
    double calculate(){
        switch(op){
            case '+':return num1+num2;
            case '-':return num1-num2;
            case '*':return num1*num2;
            case '/':
                if(num2==0)throw DivisionByZero();
                return num1/num2;
            default:throw InvalidInput();
        }
    }
};
void logError(const string& msg){
    ofstream fout("error_log.txt",ios::app);
    if(fout.is_open()){
        fout<<msg<<endl;
        fout.close();
    }
}

int main(){
    Calculator calc;
    char choice;
    do{
        try{
            calc.input();
            double result=calc.calculate();
            cout<<"Result: "<<result<<endl;
        }
        catch(const DivisionByZero& e){
            cerr<<e.what()<<endl;
            logError(e.what());
        }
        catch(const InvalidInput& e){
            cerr<<e.what()<<endl;
            logError(e.what());
        }
        catch(const exception& e){
            cerr<<"Unknown error: "<<e.what()<<endl;
            logError(e.what());
        }

    cout<<"Do you want to perform another operation? (y/n): ";
    cin>>choice;
    } while(choice=='y'||choice=='Y');
return 0;
}
