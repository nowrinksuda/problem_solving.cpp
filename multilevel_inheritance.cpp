// 2. Multilevel Inheritance Problem:

//    Imagine you're designing software for a car rental agency. Create a base class called `Vehicle` with properties like `fuelType` and `capacity`. Derive a class `Car` from `Vehicle`, representing different cars available for rent, with an additional property `numSeats`. Further derives a class `Sedan` from `Car`, representing sedan cars with extra boot space. Implement member functions to display details of each vehicle including fuel type, capacity, number of seats, and boot space for sedans. Test your code by creating objects representing different types of cars and displaying their 
#include <bits/stdc++.h>
using namespace std;
class Vehicle {
protected:
    string fuelType;
    int capacity;
public:
    Vehicle(string fuel, int cap) : fuelType(fuel), capacity(cap) {}
    void displayDetails() {
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Capacity: " << capacity << " liters" << endl;
    }
};

class Car : public Vehicle {
protected:
    int numSeats;
public:
    Car(string fuel, int cap, int seats) : Vehicle(fuel, cap), numSeats(seats) {}
    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Number of Seats: " << numSeats << endl;
    }
};

class Sedan : public Car {
private:
    int bootSpace;
public:
    Sedan(string fuel, int cap, int seats, int boot) : Car(fuel, cap, seats), bootSpace(boot) {}
    void displayDetails() {
        Car::displayDetails();
        cout << "Boot Space: " << bootSpace << " liters" << endl;
    }
};

int main() {
    Sedan mySedan("Petrol", 50, 5, 500);
    cout << "Details of Sedan:" << endl;
    mySedan.displayDetails();
    return 0;
}
