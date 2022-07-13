#include<iostream>

using namespace std;

class Base{

    public:

    //we added a keyword virtual here.
    //this is used to achieve runtime polymorphism
    //this is FUNCTION OVERRIDING in C++
    virtual void print(){
        cout<<"This is base print"<<endl;
    }

    void display(){
        cout<<"This is base display"<<endl;
    }


};

class derived : public Base{

    public:

  void print(){
        cout<<"This is derived print"<<endl;
    }

    void display(){
        cout<<"This is derived display"<<endl;
    }

};

int main(){

    Base *baseptr;

    baseptr = new derived();

    baseptr ->print();
    baseptr -> display();

  
    return 0;
}