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


    // seats
    // business
    int business_count = 10, businessPrice = 50000;
    vector<bool> business_seat;
    // economy
    int economy_count = 50, economyPrice = 35000;
    vector<bool> economy_seat;
    // seating
    int seating_count = 140, seatingPrice = 20000;
    vector<bool> seating_seat;

public:
    // default constructor
    Cruise() {
        id = "NULL";
        departure_time = 0000;
        departure_city = "NULL";
        arrival_time = 0000;
        arrival_city = "NULL";
        duration = 0;

        business_seat.resize(business_count, false);
        economy_seat.resize(economy_count, false);
        seating_seat.resize(seating_count, false);
    }

    // constructor for id 
    Cruise(string id){
        this->id = id;
        departure_city = "NULL";
        departure_time = 0000;
        arrival_time = 0000;
        arrival_city = "NULL";
        duration = 0;

        business_seat.resize(business_count, false);
        economy_seat.resize(economy_count, false);
        seating_seat.resize(seating_count, false);

    }

    Cruise(string id, int capacity){
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
    void setEconomySeatCount(int count) { this->economy_count = count;}
    void setBusinessSeatCount(int count) { this->business_count = count;}
    void setSeatingSeatCount(int count) { this->seating_count = count;}

    // getter function
    int getDepartureTime() { return departure_time; }
    string getDepartureCity() { return departure_city; }
    int getArrivalTime() { return arrival_time; }
    string getArrivalCity() { return arrival_city; }
    int getDuration() { return duration; }
    string  getID() { return id; }
    int getEconomySeatCount() { return economy_count; }
    int getBusinessSeatCount() { return business_count; }
    int getSeatingSeatCount() { return seating_count; }
    int getEconomyPrice() { return economyPrice; }
    int getBusinessPrice() { return businessPrice; }
    int getSeatingPrice() { return seatingPrice; }

    // calculate duration
    int calculateDuration() {
        return duration = arrival_time - departure_time;
    }
    int calculateDuration(int from, int to) {
        return duration = to - from;
    }


    // book seat
    bool bookEconomySeat(int seatno) {
        int size = economy_seat.size();
        if (seatno >= size) return false; // out of bound
        if (economy_seat[seatno]) return false; // already booked
        return economy_seat[seatno] = true;
    } 
    bool bookBusinessSeat(int seatno) {
        int size = business_seat.size();
        if (seatno >= size) return false; // out of bound
        if (business_seat[seatno]) return false; // already booked
        return business_seat[seatno] = true;
    } 
    bool bookSeatingSeat(int seatno) {
        int size = seating_seat.size();
        if (seatno >= size) return false; // out of bound
        if (seating_seat[seatno]) return false; // already booked
        return seating_seat[seatno] = true;
    } 

};