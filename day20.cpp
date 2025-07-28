#include<iostream>
#include<fstream>
#include<string> 
using namespace std;

const int max_books=100;

class book{
public:
int id;
string title,author;

    book(){}
    book(int id,string title,string author){
    this->id=id;
    this->title=title;
    this->author=author;
}

    void show(){
    cout<<"id:"<<id<<",title:"<<title<<",author:"<<author<<endl;
    }

~book(){}
};

class library{
    book books[max_books];
    int book_count=0;

void load(){
    ifstream in("books.txt");
    book_count=0;
    while(in>>books[book_count].id){
    in.ignore();
    getline(in,books[book_count].title);
    getline(in,books[book_count].author);
    book_count++;
}
in.close();
}

void save(){
ofstream out("books.txt");
for(int i=0;i<book_count;i++){
out<<books[i].id<<endl;
out<<books[i].title<<endl;
out<<books[i].author<<endl;
}
out.close();
}

public:
library(){load();}

void add_book(){
if(book_count>=max_books){
cout<<"library full.\n";
return;
}
int id;
string title,author;
    cout<<"enter book id:";cin>>id;
    cin.ignore();
    cout<<"enter title:";
    getline(cin,title);
    cout<<"enter author:";getline(cin,author);
    books[book_count++]=book(id,title,author);
    save();
    cout<<"book added.\n";
}

void view_books(){
load();
        cout<<"\nlist of books:\n";
        for(int i=0;i<book_count;i++){
        books[i].show();
}
}

void sort_books(){
    for(int i=0;i<book_count-1;i++){
        for(int j=i+1;j<book_count;j++){
        if(books[i].id>books[j].id){
        book temp=books[i];
        books[i]=books[j];
        books[j]=temp;
    }
}
}
save();
    cout<<"books sorted by id.\n";
}

~library(){save();}
};
class user{
protected:
string username;
public:
    user(string name){username=name;}
    virtual void menu(library& lib)=0;
    virtual ~user(){}
};
class admin:public user{
public:
    admin(string name):user(name){}
void menu(library& lib){
int choice;
do{
    cout<<"\n--admin menu--\n";
    cout<<"1.add book\n";
    cout<<"2.view books\n";
    cout<<"3.sort books\n";
    cout<<"0.exit\n";
    cout<<"choice:";cin>>choice;
switch(choice){
    case 1:
    lib.add_book();break;
    case 2:
    lib.view_books();break;
    case 3:
    lib.sort_books();break;
    case 0:cout<<"goodbye\n";break;
    default:cout<<"invalid\n";
}
    }while(choice!=0);
}
};

class student:public user{
public:
    student(string name):user(name){}
void menu(library& lib){
    int choice;
    do{
   cout<<"\n--student menu--\n";
    cout<<"1.view books\n";
    cout<<"0.exit\n";
    cout<<"choice:";cin>>choice;
    switch(choice){
    case 1:lib.view_books();break;
    case 0:cout<<"goodbye\n";break;
    default:cout<<"invalid\n";
    }
    }while(choice!=0);
}
};

int main(){
    library lib;
    string role,name;
    cout<<"login as(admin/student):";cin>>role;
    cout<<"enter username:";cin>>name;

    user* u=nullptr;
    if(role=="admin")
    u=new admin(name);
    else if
    (role=="student")u=new student(name);
    else{
    cout<<"unknown role\n";
    return 0;
}

    u->menu(lib);
delete u;
return 0;
}
