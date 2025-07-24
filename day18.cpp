#include<iostream>
using namespace std;

class complexnumber{public:
float realpart,imaginarypart;

complexnumber(){
realpart=0;
imaginarypart=0;
}

complexnumber(float r,float i){
realpart=r;
imaginarypart=i;
}

void showresult(){
cout<<"result:"<<realpart;
if(imaginarypart>=0)cout<<"+";
cout<<imaginarypart<<"i"<<endl;
}

complexnumber operator+(complexnumber other){
return complexnumber(realpart+other.realpart,imaginarypart+other.imaginarypart);
}

complexnumber operator-(complexnumber other){
return complexnumber(realpart-other.realpart,imaginarypart-other.imaginarypart);
}

complexnumber operator*(complexnumberother){
float newreal=realpart*other.realpart-imaginarypart*other.imaginarypart;
float newimag=realpart*other.imaginarypart+imaginarypart*other.realpart;
return complexnumber(newreal,newimag);
}

bool operator==(complexnumber other){
return(realpart==other.realpart&&imaginarypart==other.imaginarypart);
}
};

int main(){

complexnumber num1(2,3),num2(1,4);

complexnumber sum=num1+num2;
sum.showresult();

complexnumber diff=num1-num2;
diff.showresult();

complexnumber product=num1*num2;
product.showresult();

if(num1==num2)
cout<<"equal"<<endl;
else
cout<<"not_equal"<<endl;

return 0;
}
