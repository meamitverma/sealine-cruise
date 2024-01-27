
#include<bits/stdc++.h>
// #include "Cruise.cpp"
// #include "input.cpp"
// #include "Global.h"

using namespace std;

void preprocessing() {
    // take all cruises details from the file
    string filename = "cruise_data.txt"; 
    readCruisesFromFile(filename);
}

// returns the list of available cruise ids
void findCruises(map<string, Cruise> cruises, string origin, string dest, vector<Cruise> &available_cruises) {
    // vector<Cruise> available_cruises;
    for (auto it : cruises) {
        Cruise cruise = it.second;
        // get the cruise origin city and cruise destination
        string cruise_origin = cruise.getDepartureCity();
        string cruise_dest = cruise.getArrivalCity();

        // if passengers origin & dest matches with cruises origin & dest
        // add it to the available cruises
        if (cruise_origin == origin && cruise_dest == dest) {
            available_cruises.push_back(cruise);
        }   
    }

    // return available_cruises;
}

// todo
void showCruise(string cruise_id) {
    // print all the seats with their seat number
    // cruise details
    // business seats
    // economy seats
    // seating seats
}