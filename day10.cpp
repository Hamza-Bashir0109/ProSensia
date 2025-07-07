#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct inventory{
   int id,quantity;
   string name;
   float price;
};
string gettoken(string& line) {
    size_t pos=line.find(" | ");
    string token;
if(pos!=string::npos){
        token=line.substr(0, pos);
        line=line.substr(pos + 3);
    } else {
        token=line;
        line="";
    }
    size_t start=token.find_first_not_of(" ");
    size_t end=token.find_last_not_of(" ");
    if (start==string::npos || end==string::npos) 
    return "";

    return token.substr(start,end-start+ 1);
}
void add_item(const string& file){
    inventory obj;
    cout<<"Enter the name of item\n";
    cin>>obj.name;
    cout<<"enter the id od item\n";
    cin>>obj.id;
    cout<<"enter the quantity\n";
    cin>>obj.quantity;
    cout<<"enter the price\n";
    cin>>obj.price;

    ofstream add(file,ios::app);

    if(add.is_open()){
        add<<obj.id<<" | "<< obj.name<<" | "<<obj.price<<" | "<<obj.quantity<<endl;
        add.close();
        cout<<"item added successfully\n";
    }
    else{
        cout<<"Cannot opent the file\n";
    }
}
void display(const string& file){
          ifstream read(file);
          if(!read){
            cout<<"cannot open file\n";
            return;
          }
     string line;
    cout<<"\nID | Name | Price | Quantity\n";
    cout<<"----------------------------------------\n";

    while(getline(read, line)){
        inventory item;
        string temp;

        temp=gettoken(line);
        if(temp.empty()) continue;
        item.id=stoi(temp);

        item.name=gettoken(line);

        temp=gettoken(line);
        if(temp.empty()) continue;
        item.price=stof(temp);

        temp=gettoken(line);
        if(temp.empty()) continue;
        item.quantity=stoi(temp);

        cout<<item.id<<" | "<<item.name<<" | "<< item.price<<" | "<<item.quantity<<endl;
    }
    read.close();   
}
void searchId(const string& file,int id){
     ifstream search(file);
     if(!search){
        cout<<"cannot open file\n";
         return;
     }    
     string line;
    bool found=false;
    while(getline(search, line)){
        inventory item;
        string temp;

        temp=gettoken(line);
        if(temp.empty()) continue;
        item.id=stoi(temp);

        item.name=gettoken(line);

        temp=gettoken(line);
        if(temp.empty()) continue;
        item.price=stof(temp);

        temp=gettoken(line);
        if(temp.empty()) continue;
        item.quantity=stoi(temp);

    if(item.id==id){
            cout<<"\nItem Found:\n"<<"ID: "<<item.id<<"\nName: "<<item.name<<"\nQuantity: "<<item.quantity<<"\nPrice: "<<item.price<<"\n";
            found = true;
            break;
     }
}
    if (!found) {
        cout << "Item not found.\n";
    }
search.close();
}
void Delete(const string& file,int id){
    ifstream read(file);
    ofstream temp("temp.txt");
if(!read ||!temp){
        cout << "File error.\n";
        return;
}
    string line;
    bool deleted = false;
    while (getline(read, line)) {
        string tempLine=line;
        string token=gettoken(tempLine);  
        if(token.empty()) continue;
        int currentId=stoi(token);
        if (currentId==id && !deleted){
        deleted=true; 
        continue;
    }
        temp<<line<<endl;  
}
    read.close();
    temp.close();
    remove(file.c_str());
    rename("temp.txt", file.c_str());
    if (deleted)
    cout<<"Item deleted successfully\n";
    else
    cout<<"Item id not found\n";
}

void update(const string& file,int id,int delta){
    ifstream read(file);
    ofstream temp("temp.txt");
if(!read || !temp){
        cout<<"File error.\n";
        return;
    }
    string line;
    bool updated=false;
while (getline(read, line)){
        string originalLine=line;
        string tempToken;
        inventory item;

        tempToken=gettoken(line);
        if(tempToken.empty()) continue;
        item.id=stoi(tempToken);

        item.name=gettoken(line);

        tempToken=gettoken(line);
        if(tempToken.empty()) continue;
        item.price=stof(tempToken);

        tempToken=gettoken(line);
        if(tempToken.empty()) continue;
        item.quantity=stoi(tempToken);

        if(item.id==id){
            item.quantity+=delta;
            if(item.quantity<0) item.quantity=0;
            temp<<item.id<<" | "<<item.name<<" | "<< item.price<<" | "<<item.quantity<<endl;
            updated=true;
        } else{
            temp<<originalLine<<endl;
        }
    }

    read.close();
    temp.close();

    remove(file.c_str());
    rename("temp.txt", file.c_str());
if (updated)
        cout << "Quantity updated successfully.\n";
    else
        cout << "Item ID not found.\n";
        
}

int main(){

    int id,q;
    string file="inventory.txt";
int choice;

    do{
        cout<<"choose a number\n";
        cout<<"1. add item\n2. View All Items\n3. Search by ID\n4. Update Quantity\n5. Delete Item\n6. Exit\n";
        cin>>choice;
    if(choice==1){
        add_item(file);
    }
    else if(choice==2){
        display(file);
    }
    else if(choice==3){
        cout<<"enter the id to search\n";
        cin>>id;
        searchId(file,id);
    }
    else if(choice==4){
        cout<<"enter the id of item to updtae quantity of\n";
        cin>>id;
        cout<<"enete the change in quantity that +ive or -ive\n";
        cin>>q;
        update(file,id,q);
    }
    else if(choice==5){
        cout<<"enter the id of itam to delete\n";
        cin>>id;
        Delete(file,id);
    }
    else if(choice==6){
        cout<<"exited";
        break;
    }
    else{
        cout<<"invalid choice";
    }
    }while(true);
    return 0;
}
