#include <iostream>
using namespace std;

class shape{
    public:

    virtual void draw(){
        cout<<"drawing a shape\n";
    }

    virtual ~shape();
};

class rectangle:public shape{
    public:
    void draw() override{
        cout<<"Drawing a recangle\n";
    }
   virtual ~rectangle();
};
class circle:public shape{
    public:
    void draw() override{
        cout<<"Drawing a circle\nn";
    }
   virtual ~circle();
};
class triangle:public shape{
    public:
    void draw() override{
        cout<<"Drawing a triangle\n";
    }
   virtual ~triangle();
};
shape::~shape() {}
rectangle::~rectangle() {}
circle::~circle() {}
triangle::~triangle() {}
int main() {
    const int size=3;
    shape* s[size]; 

   s[0]=new circle();
   s[1]=new rectangle();
   s[2]=new triangle();

    for (int i=0;i<size;++i){
        s[i]->draw();
    }
    for (int i=0;i<size;++i){
        delete s[i];
    }
return 0;
}