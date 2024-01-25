#include <iostream>
#include <bits/stdc++.h>
// #include "Ticket.h"
#include "Global.h"

using namespace std;

class Passenger{
private: 
    string name;
    int age;
    string departure_city;
    string arrival_city;
    SeatType seat_pref; // business or economy

public:
    Passenger(string name, int age){
        this->name = name;
        this->age = age;
        departure_city = "";
        arrival_city = "";
        seat_pref = SeatType::Economy;
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