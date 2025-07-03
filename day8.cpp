#include <iostream>
using namespace std;

bool isOdd(int n) {
    return n % 2!=0;
}

void swaping(int* x,int* y){
    if (*x > *y && (*x - *y)>10){
        int* temp=new int(*x);  
        *x= *y;
        *y=*temp;
        delete temp;
    }
    else if (*y>*x && (*y - *x)>10) {
        int*temp=new int(*y);
        *y=*x;
        *x=*temp;
        delete temp;
    }
}

void pointer_array(int* arr,int size) {
    cout<<"array elements and their addresses:\n";
    for(int i=0;i<size;i++){
        cout<<"value: "<<*(arr + i)<<" at address: "<<(arr + i)<<endl;
    }
}
int* firsteven(int* arr, int size){
    for(int i=0;i<size;i++){
        if(*(arr + i)%2==0)
            return(arr+i);
    }
    return nullptr;
}

void incrementOdds(int* arr,int size){
    for(int i=0; i<size;i++){
        if(isOdd(*(arr + i))){
            (*(arr + i))++;
        }
}
}

int main() {
    int a,b,arr[5];
    cout<<"Enter two integers";
    cin>>a>>b;

cout << "Enter 5 integers\n";
for(int i=0; i<5;i++){
        cin>>arr[i];
    }
    swaping(&a,&b);
    cout<<"\nprinting after conditional swap \n";
    cout<<"a = "<<a<<",b = "<<b<<endl;
    
      cout<<"\nprinting agter the original array:\n";
    pointer_array(arr,5);
    
incrementOdds(arr,5);
    cout<<"\nArray after incrementing odd values:\n";
    pointer_array(arr,5);

int* firstevenPtr=firsteven(arr,5);
    cout<<"\nFirst Even Element:\n";
    if(firstevenPtr!=nullptr){
         cout<<"value: "<<*firstevenPtr<<" at address: "<<firstevenPtr<<endl;
    } else{
         cout<<"No even element found in the array.\n";
    }
    return 0;
}
