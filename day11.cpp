#include<iostream>
#include<fstream>
using namespace std;

struct Employee{
    int id;
    string name;
    string department;
    float salary;
};
Employee emp[100];
int empCount=0;
void addEmployee(){
     
    cout<<"Enter Id: ";
     cin>>emp[empCount].id;
     cout<<"Enter name: ";

     cin>>emp[empCount].name;

     cout<<"Enter department: ";
     cin>>emp[empCount].department;
     cout<<"Enter salary: ";
     
     cin>>emp[empCount].salary;
     empCount++;
     cout<<"employee added\n";
}
void viewEmployees(){
     if(empCount==0){
        cout<<"No records\n";
        return;
    }
   for(int i=0;i<empCount;i++){
        cout<<"Id: "<<emp[i].id<<", name: "<<emp[i].name<<", dept: "<<emp[i].department<<", Salary: "<<emp[i].salary<<"\n";
    }
}
void searchByID(){
     int id;
   cout  <<"Enter id to search: ";
    cin>>id;
for(int i=0;i<empCount;i++){
    if(emp[i].id==id){
        cout<<"Found: "<<emp[i].name<<", "<<emp[i].department<<", "<<emp[i].salary<<"\n";
        return;
    }
}
    cout<<"Not found\n";
}
void updateSalary(){
    int id;
    float newsalary;
    cout<<"Enter Id to update salary: ";
    cin>>id;
    for(int i=0;i<empCount;i++){
        if(emp[i].id==id){
            cout<<"Enter the new salary:";
            cin>>newsalary;
            emp[i].salary=newsalary;
            cout<<"updated\n";
            return;
        }
    }
    cout<<"not found\n";
}
void salaryStats(){
    if(empCount==0){
        cout<<"no record\n";
        return;
    }
    float total=0;

    for(int i=0;i<empCount;i++){
        total+=emp[i].salary;
    }
    cout<<"Total:"<<total<<"\n";

    cout<<"average:"<<total/empCount<<"\n";
}
void saveToFile(){
    ofstream f("employees.txt");
    f<<empCount<<"\n";
for(int i=0;i<empCount;i++){


        f<<emp[i].id<<" "<<emp[i].name<<" "<<emp[i].department<<" "<<emp[i].salary<<"\n";
}
    f.close();
    cout<<"Saved to file\n";
}
void loadFromFile(){
     ifstream f("employees.txt");
     if(!f){
        cout<<"File not found\n";
        return;
    }
     f>>empCount;

     for(int i=0;i<empCount;i++){
        f>>emp[i].id>>emp[i].name>>emp[i].department>>emp[i].salary;
    }
    f.close();
    cout<<"Data loaded\n";
}
int main(){
    int choice;
    loadFromFile();
    do{

        cout<<"\n1.Add\n2.View\n3.Search\n4.Update Salary\n5.Salary Stats\n6.Save\n7.Exit\n";
        cout<<"Choice: ";
        cin>>choice;
        if(choice==1)addEmployee();
        else if(choice==2)
        {viewEmployees();
        }

        else if(choice==3)
        { 
            searchByID();
         }
        else if(choice==4)
        {updateSalary();
        }

        else if(choice==5)
        {
        salaryStats();
    }
        else if(choice==6)
        { 
            saveToFile();
        }
        else if(choice==7)
        {  
            saveToFile();
        }

        else 
    cout<<"Invalid\n";

    }while(choice!=7);
    
return 0;
}
