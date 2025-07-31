#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    vector<int>marks;
    set<string>depart;

    map<string,int>deptCount;
    int n;

    cout<<"Enter number of students:\n";
    cin>>n;


    for(int i=0;i<n;++i){
        int mark;
        string dept;

        cout<<"Enter marks of student\n"<<i+1<<":";
        cin>>mark;
        marks.push_back(mark);

        cout<<"Enter department of student "<<i+1<<endl;
        cin>>dept;

        depart.insert(dept);
        deptCount[dept]++;
    }
    sort(marks.begin(),marks.end());


    cout<<"\nSorted Student Marks:\n";
for(int m:marks){
        cout<<m<<" ";
}


    cout<<"\n\nUnique dept:\n";
    for(const string&d:depart){
        cout<<d<<"\n";
    }
    cout<<"\nDepartment-wise Student Count:\n";
    for(const auto&pair:deptCount){
        cout<<pair.first<<":"<<pair.second<<"\n";
    }

return 0;
}
