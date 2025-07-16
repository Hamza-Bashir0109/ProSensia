#include <iostream>
using namespace std;
class student{
    private:
    string name;
    int roll_no;
    int marks[3];
    int total;
    float average;

    public:
    student(int id,string n,int m1,int m2,int m3){
        name=n;
        roll_no=id;
        marks[0]=m1;
        marks[1]=m2;
        marks[2]=m3;
        total=m1+m2+m3;
        average=total/3.0;
    }
    
void display(){
cout<<"Roll No: "<<roll_no<<endl;
cout<<"Name: "<<name<<endl;
cout<<"Marks: "<<marks[0]<<","<<marks[1]<<","<<marks[2]<<endl;
cout<<"Total: "<<total<<endl;
cout<<"Average: "<<average<<endl;
}
int getTotal(){return total;}

};
void sort(student arr[],int n){
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(arr[i].getTotal()<arr[j].getTotal()){
student temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
}
int main(){
student s[3]={
student(1,"Ali",80,90,85),
student(2,"Sara",75,95,80),
student(3,"Ahmed",85,85,90)};
sort(s,3);
for(int i=0;i<3;i++){
s[i].display();
cout<<endl;
}
return 0;
}