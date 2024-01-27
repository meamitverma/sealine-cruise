#include <bits/stdc++.h>
using namespace std;

class Passenger{
private: 
    string name;
    int age;
    string departure_city;
    string arrival_city;
    SeatType seat_pref; // business or economy


public:
    // default constructor
    Passenger() {
        name = "passenger";
        age = 0;
        departure_city = "NULL";
        arrival_city = "NULL";
        seat_pref = Seating;
    }
    Passenger(string name, int age){
        this->name = name;
        this->age = age;
        departure_city = "";
        arrival_city = "";
        seat_pref = Seating;
    }

    // getters
    string getName() { return name; }
    int getAge() { return age;}
    string getDepartureCity() { return departure_city; }
    string getArrivalCity() { return arrival_city;}
    SeatType getSeatPref() { return seat_pref; }

    //setters
    void setDepartureCity(string city) { this->departure_city = city; }
    void setArrivalCity(string city) { this->arrival_city = city; }

};