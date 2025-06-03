#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Tester;  // Forward declaration of friend class

class Vehicle {
protected:
    string name;
private:
    int engineCapacity;
    float fuelEfficiency;
    int topSpeed;

public:
    Vehicle(string n, int ec, float fe, int ts) : name(n), engineCapacity(ec), fuelEfficiency(fe), topSpeed(ts) {}

    friend class Tester; // Declaring Tester as a friend class
};

#endif
