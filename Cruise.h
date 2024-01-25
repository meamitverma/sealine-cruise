#include <bits/stdc++.h>
using namespace std;



class Cruise{
private:
    string id; // cruise id

    // departures
    int departure_time; // in 24hr (1313)
    string departure_city;

    // arrival
    int arrival_time; // in 24hr (1315)
    string arrival_city;

    int duration; // in minute
    int capacity = 200;

public:

    // constructor for id 
    Cruise(int id){
        this->id = id;
        departure_city = "NULL";
        departure_time = 0000;
        arrival_time = 0000;
        arrival_city = "NULL";
        duration = 0;
        this->capacity = capacity;
    }

    Cruise(int id, int capacity){
        this->id = id;
        departure_city = "NULL";
        departure_time = 0000;
        arrival_time = 0000;
        arrival_city = "NULL";
        duration = calculateDuration(departure_time, arrival_time);
        this->capacity = capacity;
    }

    // setter function
    void setDepartureTime(int depart_time) { this->departure_time = depart_time; }
    void setDepartureCity(string depart_city) { this->departure_city = depart_city; }
    void setArrivalTime(int arrival_time) { this->arrival_time = arrival_time; }
    void setArrivalCity(string arrival_city) { this->arrival_city = arrival_city; }
    void setDuration(int min) { this->duration = duration; }

    // getter function
    int getDepartureTime() { return departure_time; }
    string getDepartureCity() { return departure_city; }
    int getArrivalTime() { return arrival_time; }
    string getArrivalCity() { return arrival_city; }
    int getDuration() { return duration; }
    string  getID() { return id; }

    // calculate duration
    int calculateDuration(int from, int to) {
        return to - from;
    }

    

};