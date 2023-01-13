#include<iostream>

using namespace std;

//General Syntax to define a class

class node {
    //add data members and function members here
};



class B{

    //here a and b are by default private
    int a; int b;

    void unInheritableFunction(){
        cout<<"This function cannot be inherited";
    }

    public:
        //every member which we write under this public
        //is all public (functions also)
        int c; int d;
        //here c and d are public

        void print(){
            cout<<"This is the print function called.";
        }

    protected:
        //every member which we write under this protected
        //is all protected (functions also)
        int l; int g;
        //here l and g are protected.

};

//here B and node are inherited in C. 
//Constructor of B will be called first then of node
// only public and protected data members of A & node
// will be inherited to C as public functions. Other member /// types will not be inherited
class C: public B, public node{

    int a , b;

    public:
        int c; int d;

        void inheritedFunc(){
            cout<<"Inherited func called!";
        }    
};

int main(){

    C c;
    c.inheritedFunc();


    return 0;
}