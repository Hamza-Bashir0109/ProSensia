#include<iostream>
#include<fstream>
using namespace std;

class student{
    public:
string rollno,name,department;
float cgpa;

void getdata(){
cout<<"enterrollno:";
cin>>rollno;
cout<<"entername:";
cin>>name;
cout<<"enterdepartment:";
cin>>department;
cout<<"entercgpa:";
cin>>cgpa;
}

void showdata(){
cout<<"rollno:"<<rollno<<endl;
cout<<"name:"<<name<<endl;
cout<<"department:"<<department<<endl;
cout<<"cgpa:"<<cgpa<<endl;
}

string getroll(){
return rollno;
}
};

void addstudent(){
student newstudent;
newstudent.getdata();
ofstream file("students.txt",ios::app);
file<<newstudent.rollno<<" "<<newstudent.name<<" "<<newstudent.department<<" "<<newstudent.cgpa<<endl;
file.close();
}

void showall(){
ifstream file("students.txt");
student temp;

while(file>>temp.rollno>>temp.name>>temp.department>>temp.cgpa){
temp.showdata();
cout<<"----------"<<endl;
}

file.close();
}

void findstudent(){
ifstream file("students.txt");
student temp;
string target;
cout<<"enterrollno:";
cin>>target;
bool found=false;

while(file>>temp.rollno>>temp.name>>temp.department>>temp.cgpa){
if(temp.getroll()==target){
temp.showdata();
found=true;
break;
}
}

file.close();
if(!found)cout<<"notfound"<<endl;
}

void updatestudent(){
ifstream infile("students.txt");
ofstream tempfile("temp.txt");
student temp;
string target;
cout<<"enterrollno:";
cin>>target;
bool updated=false;

while(infile>>temp.rollno>>temp.name>>temp.department>>temp.cgpa){
if(temp.getroll()==target){
temp.getdata();
updated=true;
}
tempfile<<temp.rollno<<" "<<temp.name<<" "<<temp.department<<" "<<temp.cgpa<<endl;
}

infile.close();
tempfile.close();
remove("students.txt");
rename("temp.txt","students.txt");

if(updated)cout<<"updated\n";
else cout<<"notfound\n";
}

void deletestudent(){
ifstream infile("students.txt");
ofstream tempfile("temp.txt");
student temp;
string target;
cout<<"enterrollno:";
cin>>target;
bool deleted=false;

while(infile>>temp.rollno>>temp.name>>temp.department>>temp.cgpa){
if(temp.getroll()!=target){
tempfile<<temp.rollno<<" "<<temp.name<<" "<<temp.department<<" "<<temp.cgpa<<endl;
}
else{
deleted=true;
}
}

infile.close();
tempfile.close();
remove("students.txt");
rename("temp.txt","students.txt");

if(deleted)cout<<"deleted\n";
else cout<<"notfound\n";
}

int main(){
int choice;

while(true){
cout<<"1:add\n2:view\n3:search\n4:update\n5:delete\n6:exit\nchoice:";
cin>>choice;

if(choice==1)
addstudent();
else if(choice==2)
showall();
else if(choice==3)
findstudent();
else if(choice==4)
updatestudent();
else if(choice==5)
deletestudent();
else if(choice==6)
break;
else cout<<"invalid\n";
}

return 0;
}
