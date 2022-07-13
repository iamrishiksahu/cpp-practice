#include<iostream>

using namespace std;

class Complex{

    int a;
    int b;

    public:

        Complex(int x, int y){
            a =x;
            b =y;
        }

        //Operator overloading
        //we are overloading the work of '+' operator
        //to create a custom meaning of it for
        //this class

        Complex operator + (Complex const &c){

            Complex res(a+c.a, b+c.b);
            // res.a = a+ c.a;
            // res.b = b+c.b;
            return res;


        }

        void print(){

            cout<<a<<" + i"<<b;
        }
};

class A{

    public:

        //this is function overloading
        void welcome(){
            cout<<"This is welcome"<<endl;
        }
        void welcome(int a){
            cout<<"This is welcome 2"<<endl;
        }
};

int main(){

    A a;

    a.welcome();
    a.welcome(3);

    Complex x(2, 3);
    Complex y(4,5);
    Complex n = x + y;
    n.print();

    


}