#include <iostream>
using namespace std;

class Animal
{
protected:
    int age;

public:
    Animal(int a)
    {
        age = a;
    }
    virtual void Eat()
    {
        cout << "Animal eats food" << endl;
    }
    int get_Age()
    {
        return age;
    }
};

class Dog : public Animal
{

public:

// here dog doest not needs constructor but inorder to call the animal's constructor to set the age of the dog, we need to create an constructor for dog and then need to pass it to the animal constructor.
    Dog(int a) : Animal(a)
    {
    }

    void Eat()
    {
        cout << "Dog eats meat" << endl;
    }
};

class Cat : public Animal
{

public:

// here cat doest not needs constructor but inorder to call the animal's constructor to set the age of the cat, we need to create an constructor for cat and then need to pass it to the animal constructor.
    Cat(int a) : Animal(a) 
    {
    }

    void Eat()
    {
        cout << "Cat eats meat" << endl;
    }
};

int main()
{
    Animal *a;
    Dog dg(8); // making object of child class Dog
    Cat ct(3); // making object of child class Cat

    a = &dg;
    a->Eat();
    cout << "Dog's age is: " << a->get_Age() << endl;
    a = &ct;
    a->Eat();
    cout << "Cat's age is: " << a->get_Age() << endl;
    return 0;

}