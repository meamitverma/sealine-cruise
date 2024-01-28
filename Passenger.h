#include <bits/stdc++.h>
using namespace std;

class Passenger{
private: 
    string name;
    int age;

public:
    // default constructor
    Passenger() {
        name = "passenger";
        age = 0;
    }
    Passenger(string name, int age){
        this->name = name;
        this->age = age;
    }

    // getters
    string getName() { return name; }
    int getAge() { return age;}

    //setters
    void setPassengerName(string name) { this->name = name; }
    void setAge(int age) {this->age = age;}

};