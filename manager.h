#include<bits/stdc++.h>
using namespace std;

void preprocessing() {
    // take all cruises details from the file
    string filename = "cruise_data.txt"; 
    readCruisesFromFile(filename);
}

void welcome() {
    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << "<==> Welcome to SeaLink Travels <==>" << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
}

void showQueryInfo() {
    cout << "------------------------------------------------" << endl;
    cout << "Select one of the following queries to proceed:" << endl;
    cout << "S -> To Book Ticket" << endl;
    cout << "C -> To Cancel Ticket" << endl;
    cout << "P -> For Ticket Status" << endl;
    cout << "F -> For Cruise Details" << endl;
    cout << "E -> Exit the program" << endl;
    cout << "------------------------------------------------" << endl;
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
    Cruise cruise = cruises[cruise_id];

    // cruise details
    cout<<"Cruise id: "<<cruise.getID()<<endl;
    cout<<"Departure City: "<<cruise.getDepartureCity()<<endl;
    cout<<"Arrival City: "<<cruise.getArrivalCity()<<endl;
    cout<<"Departure Time: "<<cruise.getDepartureTime()<<endl;
    cout<<"Arrival Time: "<<cruise.getArrivalTime()<<endl;
    // business seats
    cout<<"Available Business class seats: "<<cruise.getBusinessSeatCount()<<endl;

    // economy seats
    cout<<"Availabe economy class seats: "<<cruise.getEconomySeatCount()<<endl;
    // seating seats
    cout<<"Available general class seats: "<<cruise.getSeatingSeatCount()<<endl;

    int b=cruise.getBusinessSeatCount();
    int e=cruise.getEconomySeatCount();
    int s=cruise.getSeatingSeatCount();
    vector<bool> ec=cruise.getEconomySeats();
    vector<bool> bc=cruise.getBusinessSeats();
    vector<bool> sc=cruise.getSeatingSeats();
    drawCruiseBlueprint(e,b,s,ec,bc,sc);
}