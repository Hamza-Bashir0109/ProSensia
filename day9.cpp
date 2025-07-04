#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Student{
    int id;
    char name[50];
    float marks;
    char grade;
};
char calculateGrade(float marks){
if(marks>=85)
return 'A';
else if(marks>=70)
return 'B';
else if(marks>=50)
return 'C';
else return 'F';
}
void addstudent(const Student& s,const char* filename){
    if(s.marks<0||s.marks>100){
        cout<<"Invalid marks! Must be between 0 and 100.\n";
        return;
    }
    ofstream fout(filename,ios::app);
    if(!fout){
        cout<<"Error with file\n";
        return;
    }

    fout<<s.id<<'|'<<s.name<<'|'<<s.marks<<'|'<<s.grade<<'\n';
    fout.close();
    cout<<"Student added.\n";
}

void displaystudent(const char* filename){
    ifstream fin(filename);
    if(!fin){
        cout<<"Error with opening\n";
        return;
    }
    cout<<"Id| name | Mark | Grade\n";
    
    char line[100];
    while(fin.getline(line,100)){
        char* token=strtok(line,"|");
        int id=atoi(token);
        token=strtok(NULL,"|");
       char name[50];
        strcpy(name,token);
         token=strtok(NULL,"|");
          float marks=atof(token);
         token=strtok(NULL,"|");
        char grade=token[0];
           cout<<id<<" | "<<name<<" | "<<marks<<" | "<<grade<<'\n';
    }

fin.close();
}

void search(const char* filename,int searchID){
    ifstream fin(filename);
    if(!fin){
        cout<<"Error opening file.\n";
    return;
    }
    bool found=false;
    char line[100];
    while(fin.getline(line,100)){
        char* token=strtok(line,"|");
        int id=atoi(token);
    if(id==searchID){
        token=strtok(NULL,"|");
        char name[50];
           strcpy(name,token);
         token=strtok(NULL,"|");
        float marks=atof(token);
        token=strtok(NULL,"|");
            char grade=token[0];
       cout<<"ID: "<<id<<"\nName: "<<name<<"\nMarks: "<<marks<<"\nGrade: "<<grade<<'\n';
        found=true;
        break;
        }
    }
     if(!found){
    cout<<"Student not found.\n";
}
fin.close();
}
int main(){
    const char* file="student.txt";
    int choice;
    do{
        cout<<"\n1.add student\n2.display all students\n3. Search student by id\n4.Exit\nEnter choice: ";
        cin>>choice;
        if(choice==1){
            Student s;
            cout<<"Enter ID:";
            cin>>s.id;
            cout<<"Enter Name:";
            cin.ignore();
            cin.getline(s.name,50);
            cout<<"Enter Marks: ";
            cin>>s.marks;
            s.grade=calculateGrade(s.marks);
        addstudent(s,file);
        }
        else if(choice==2){
        displaystudent(file); }
        else if(choice==3){
        int id;
        cout<<"Enter id to search: ";
        cin>>id;
        search(file,id);
        }
        else if(choice==4){
             cout<<"Exited\n";
        }
       else{
             cout<<"Invalid choice.\n";
        }
}while(choice!=4);

return 0;
}
