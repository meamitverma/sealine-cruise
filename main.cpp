#include<bits/stdc++.h>
#include "Cruise.h"
#include "Global.h"
#include "Passenger.h"
#include "input.h"
#include "gui.h"
#include "manager.h"
// #include "output.h"
#include "Ticket.h"
#include "Query.h"

using namespace std;


int main() {
    preprocessing();

    // welcome to the sealink
    welcome();

    while (1 > 0) {
        cout << endl;
        showQueryInfo();

        // process query 
        cout << "Query: ";
        char query; cin >> query;
        int qstatus = processInput(query);

        if (qstatus != -1) continue;
    }

    
    // take the passenger details for proceeding to the seat booking
    // string passenger_name; int passenger_age;
    // cout << "Enter passenger Name: " << endl;
    // cin >> passenger_name;
    // cout << "Enter passenger's Age: " << endl;
    // cin >> passenger_age;

    // Passenger passenger(passenger_name, passenger_age);
    // if (ticker_status == true) {
    //     ticket.setPassenger(passenger);
    // }

    // P -> passenger/ticket status -> display the ticket
    // ticket.displayTicket();


    return 0;
}

// date
// select cruise
// select seat type;
// passenger details
// display passenger details
// ticket 


