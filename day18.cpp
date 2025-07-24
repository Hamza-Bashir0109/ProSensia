#include<iostream>
usingnamespace std;

classcomplexnumber{public:
floatrealpart,imaginarypart;

complexnumber(){
realpart=0;
imaginarypart=0;
}

complexnumber(floatr,floati){
realpart=r;
imaginarypart=i;
}

voidshowresult(){
cout<<"result:"<<realpart;
if(imaginarypart>=0)cout<<"+";
cout<<imaginarypart<<"i"<<endl;
}

complexnumberoperator+(complexnumberother){
returncomplexnumber(realpart+other.realpart,imaginarypart+other.imaginarypart);
}

complexnumberoperator-(complexnumberother){
returncomplexnumber(realpart-other.realpart,imaginarypart-other.imaginarypart);
}

complexnumberoperator*(complexnumberother){
floatnewreal=realpart*other.realpart-imaginarypart*other.imaginarypart;
floatnewimag=realpart*other.imaginarypart+imaginarypart*other.realpart;
returncomplexnumber(newreal,newimag);
}

booloperator==(complexnumberother){
return(realpart==other.realpart&&imaginarypart==other.imaginarypart);
}
};

intmain(){

complexnumbernum1(2,3),num2(1,4);

complexnumbersum=num1+num2;
sum.showresult();

complexnumberdiff=num1-num2;
diff.showresult();

complexnumberproduct=num1*num2;
product.showresult();

if(num1==num2)
cout<<"equal"<<endl;
else
cout<<"not_equal"<<endl;

return0;
}