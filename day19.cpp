#include<iostream>
#include<fstream>
usingnamespace std;

classstudent{public:
stringrollno,name,department;floatcgpa;

voidgetdata(){
cout<<"enterrollno:";cin>>rollno;
cout<<"entername:";cin>>name;
cout<<"enterdepartment:";cin>>department;
cout<<"entercgpa:";cin>>cgpa;
}

voidshowdata(){
cout<<"rollno:"<<rollno<<endl;
cout<<"name:"<<name<<endl;
cout<<"department:"<<department<<endl;
cout<<"cgpa:"<<cgpa<<endl;
}

stringgetroll(){
returnrollno;
}
};

voidaddstudent(){
studentnewstudent;
newstudent.getdata();
ofstreamfile("students.txt",ios::app);
file<<newstudent.rollno<<" "<<newstudent.name<<" "<<newstudent.department<<" "<<newstudent.cgpa<<endl;
file.close();
}

voidshowall(){
ifstreamfile("students.txt");
studenttemp;

while(file>>temp.rollno>>temp.name>>temp.department>>temp.cgpa){
temp.showdata();
cout<<"----------"<<endl;
}

file.close();
}

voidfindstudent(){
ifstreamfile("students.txt");
studenttemp;
stringtarget;
cout<<"enterrollno:";cin>>target;
boolfound=false;

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

voidupdatestudent(){
ifstreaminfile("students.txt");
ofstreamtempfile("temp.txt");
studenttemp;
stringtarget;
cout<<"enterrollno:";cin>>target;
boolupdated=false;

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

voiddeletestudent(){
ifstreaminfile("students.txt");
ofstreamtempfile("temp.txt");
studenttemp;
stringtarget;
cout<<"enterrollno:";cin>>target;
booldeleted=false;

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

intmain(){
intchoice;

while(true){
cout<<"1:add\n2:view\n3:search\n4:update\n5:delete\n6:exit\nchoice:";
cin>>choice;

if(choice==1)addstudent();
elseif(choice==2)showall();
elseif(choice==3)findstudent();
elseif(choice==4)updatestudent();
elseif(choice==5)deletestudent();
elseif(choice==6)break;
else cout<<"invalid\n";
}

return0;
}