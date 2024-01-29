#include<bits/stdc++.h>
using namespace std;

// precomputing
void preprocessing() {
    // take all cruises details from the file
    string filename = "cruise_data.txt"; 
    readCruisesFromFile(filename);
}

// printer functions
void printInsideBox(string msg) {
    int n = msg.length();
    // print the upper border
    for (int i = 0; i < n + 4; i++) cout << "-";
    cout << endl;

    //print the message
    cout << "| " << msg << " |" << endl;

     // print the lower border
    for (int i = 0; i < n + 4; i++) cout << "-";
    cout << endl;
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

void displayAvailableCruises(vector<Cruise> cruises) {
    
    string heading = "CRUISE ID | DEPARTURE TIME | ARRIVAL TIME";
    printInsideBox(heading);

    for (Cruise cruise : cruises) {
        string msg = cruise.getID() + " | " + to_string(cruise.getDepartureTime()) + " | " + to_string(cruise.getArrivalTime());
        printInsideBox(msg);
    }
}

// requesting data from user
void askOriginCity(string &city) {
    cout << "Enter your origin city: "; cin >> city;
}
void askDestinationCity(string &city) {
    cout << "Enter the destination: "; cin >> city;
}
void askDateofTravel(string &date) {
    cout << "Enter date of travel: "; cin >> date;
}
void askCruiseID(string &id) {
    cout << "Enter your preferred CRUISE ID: "; cin >> id;
}
void askSeatType(SeatType &type) {
    string input;
    cout << "Enter your preferred seat type: "; cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    if (input == "E" || input == "ECONOMY" || input == "EC") {
        type = Economy;
    }
    else if (input == "B" || input == "BUSINESS" || input == "BS") {
        type = Business;
    }
    else if (input == "S" || input == "SEATING" || input == "ST") {
        type = Seating;
    }
    else {
        cout << "Please select the correct class type:" << endl;
        askSeatType(type);
    }
}

void askPassengerDetails(Passenger &p) {
    string name; int age;
    cout << "Enter passenger Name: "; cin >> name;
    cout << "Enter passenger's Age: "; cin >> age;

    p.setPassengerName(name);
    p.setAge(age);
}

void askPNR(string &pnr) {
    cout << "Enter your PNR to proceed:"; cin >> pnr;
}

// computing functions
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

int findAvailableSeat (Cruise &cruise, SeatType type) {
    vector<bool> seats;
    if (type == Economy) seats = cruise.getEconomySeats();
    else if (type == Business) seats = cruise.getBusinessSeats();
    else if (type == Seating) seats = cruise.getSeatingSeats();
    
    int total_seats = seats.size();
    for (int i = 0; i < total_seats; i++) {
        if (!seats[i]) return i;
    }

    return -1;
}

// todo
void showCruise(string cruise_id) {
    // print all the seats with their seat number
    Cruise cruise = cruises[cruise_id];

    // cruise details
    // cout<<"Cruise id: "<<cruise.getID()<<endl;
    // cout<<"Departure City: "<<cruise.getDepartureCity()<<endl;
    // cout<<"Arrival City: "<<cruise.getArrivalCity()<<endl;
    // cout<<"Departure Time: "<<cruise.getDepartureTime()<<endl;
    // cout<<"Arrival Time: "<<cruise.getArrivalTime()<<endl;
    // // business seats
    // cout<<"Available Business class seats: "<<cruise.getBusinessSeatCount()<<endl;

    // // economy seats
    // cout<<"Availabe economy class seats: "<<cruise.getEconomySeatCount()<<endl;
    // // seating seats
    // cout<<"Available general class seats: "<<cruise.getSeatingSeatCount()<<endl;

    int b=cruise.getBusinessSeatCount();
    int e=cruise.getEconomySeatCount();
    int s=cruise.getSeatingSeatCount();
    vector<bool> ec=cruise.getEconomySeats();
    vector<bool> bc=cruise.getBusinessSeats();
    vector<bool> sc=cruise.getSeatingSeats();
    drawCruiseBlueprint(e,b,s,ec,bc,sc);
}