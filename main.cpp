#include<bits/stdc++.h>
#include "Cruise.h"
#include "Global.h"
#include "Passenger.h"
#include "input.h"
#include "gui.h"
#include "manager.h"
// #include "output.h"
#include "Query.h"
#include "Ticket.h"

using namespace std;


int main() {
    preprocessing();

    // welcome to the sealink
    welcome();
    showQueryInfo();

    cout << "Query: ";
    char query; cin >> query;
    processInput(query);

    // find the desired cruise for the user where to where
    string origin_city, dest_city;
    // origin
    cout << "Enter orgin city: " << endl;
    cin >> origin_city;

    // dest
    cout << "Enter destination city: " << endl;
    cin >> dest_city; 
    
    // show the available cruise
    vector<Cruise> available_cruises; 
    findCruises(cruises, origin_city, dest_city, available_cruises);
    cout << "Available Cruises:" << endl;
    for (Cruise c : available_cruises) {
        // display cruise details
        cout << c.getID() << endl;
        cout << c.getDepartureCity() << endl;
        cout << c.getArrivalCity() << endl;
        cout << endl;
    }

    // take cruise id as input from the available cruises
    string cruise_id; 
    string date;
    cout << "Enter cruise id to book:" << endl;
    cin >> cruise_id; 
    // cout << "Enter date of travel:" << endl;
    // cin >> date;

    Ticket ticket;
    bool ticker_status = ticket.bookTicket(cruise_id, Economy, 2);

    showCruise(cruise_id); // todo

    // take the passenger details for proceeding to the seat booking
    string passenger_name; int passenger_age;
    cout << "Enter passenger Name: " << endl;
    cin >> passenger_name;
    cout << "Enter passenger's Age: " << endl;
    cin >> passenger_age;

    Passenger passenger(passenger_name, passenger_age);
    if (ticker_status == true) {
        ticket.setPassenger(passenger);
    }

    // P -> passenger/ticket status -> display the ticket
    ticket.displayTicket();


    return 0;
}

// date
// select cruise
// select seat type;
// passenger details
// display passenger details
// ticket 


