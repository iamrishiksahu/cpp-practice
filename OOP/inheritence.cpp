#include <iostream>

using namespace std;

class LivingBeings
{

public:

    LivingBeings(){
        cout<<"Living being constructor called!"<<endl;
    }
    void callLiving()
    {
        cout << "Living beings called!" << endl;
    }
};

class Animal : public LivingBeings
{

public:

    Animal(){
        cout<<"Animal Called"<<endl;
    }
    void callAnimal()
    {
        cout << "Animal Called" << endl;
    }
};

class Dog : public Animal
{

public:
    Dog(){
        cout<<"Dog constructor called!"<<endl;
    }
    void callDog()
    {
        cout << "Dog is called!" << endl;
    }
};

class Bird :  public Dog
{

public:
    Bird()
    {
        cout << "Bird is created man!";
    }

    void callBird()
    {
        cout << "Bird is called" << endl;
    }
};

int main()
{
    Bird b;
    return 0;
}