// 5. Hierarchical Inheritance Problem:

//    Imagine you're creating a virtual pet simulator game. Design a base class called `Animal` with properties like `name` and `sound`, representing different animals in the game. Derive classes `Dog`, `Cat`, and `Cow` from `Animal`, representing different types of pets. Implement member functions to make each animal object produce its respective sound. Test your code by creating objects of each derived class and simulating interactions with the virtual pets.

#include <bits/stdc++.h>
using namespace std;
class Animal {
protected:
    string name;
    string sound;

public:
    Animal(const string& _name, const string& _sound) : name(_name), sound(_sound) {}
    virtual void makeSound() const {
        cout << name << " says " << sound << endl;
    }
};
class Dog : public Animal {
public:
    Dog(const string& _name) : Animal(_name, "Woof") {}
};
class Cat : public Animal {
public:
    Cat(const string& _name) : Animal(_name, "Meow") {}
};
class Cow : public Animal {
public:
    Cow(const string& _name) : Animal(_name, "Moo") {}
};

int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");
    Cow cow("Bessie");
    cout << "Interacting with virtual pets:" << endl;
    dog.makeSound();
    cat.makeSound();
    cow.makeSound();

    return 0;
}