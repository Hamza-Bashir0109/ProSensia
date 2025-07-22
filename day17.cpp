#include <iostream>
using namespace std;

class vehicle {
private:
    string company;
    string model;
    int year;

public:
vehicle(){
        company="not known";
        model="not unknown";
        year=0;
        cout<<"default constructor\n";
    }
    vehicle(string c, string m, int y){
        company=c;
        model=m;
        year=y;
        cout<<"parameterized constructor\n";
    }
 void displayInfo(){
        cout<<"Company: "<<company<<endl;
        cout<<"model: "<<model<<endl;
        cout<<"year: "<<year<<endl;
    }
    ~vehicle(){
        cout<<"Destructor called for"<<model<<"\n";
    }
};
int main(){
    cout<<"using default constructor\n";
    vehicle vehicle1;
    vehicle1.displayInfo();
    cout<<"\nusing parameterized constructor\n";
    vehicle vehicle2("Toyota", "Corolla", 2020);
    vehicle2.displayInfo();
    cout<<"\nEnd of main function.\n";
    return 0;
}
