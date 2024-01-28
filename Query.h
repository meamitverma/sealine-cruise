#include <bits/stdc++.h>
using namespace std;

/*S: scheduling
C: cancel the passenger
P: Passenger status
F: cruise status
E: exit */

// ------Waitlist to be made if bookings are full similar to IRCTC--------

int processInput(char input)
{   
    input = toupper(input);
    if (input == 'S')
    {
        // start booking process
        cout << endl;
        printInsideBox("Ticket Booking");

        // ask for origin city, destination city and date of travel
        string origin_city, destination_city, date;
        askOriginCity(origin_city);
        askDestinationCity(destination_city);
        askDateofTravel(date);

        // show all the available cruises from the origin to destination city
        vector<Cruise> available_cruises;
        findCruises(cruises, origin_city, destination_city, available_cruises);
        
        int cruises_count = available_cruises.size();
        // if no available cruise ask the details again
        if (cruises_count == 0) {
            cout << "Sorry! theres no available cruises at the moment for your route." << endl;
            return 0;
        }
        // else diplay the available cruises
        else {
            cout << endl;
            cout << "Available Cruises from " + origin_city + " -> " + destination_city + ": " << endl;
            displayAvailableCruises(available_cruises);
        }

        // ask for the preferred cruise id from the list
        string cruise_id;
        askCruiseID(cruise_id);
        // cruise not available with this cruiseid
        while(cruises.find(cruise_id) == cruises.end()) {
            cout << "No cruises with the provided cruise id. Please recheck with the cruise id." << endl;
            askCruiseID(cruise_id);
        }

        // when cruise selected
        Cruise *cruise = &cruises[cruise_id];
        // show the cruiseDetails
        showCruise(cruise_id);

        SeatType type;
        askSeatType(type);
        int seatno = findAvailableSeat(*cruise,type);

        Ticket ticket;
        if (seatno < 0) {
            // put in waitlist;
        }
        else {
            // book the confirmed ticket
            bool ticket_status = ticket.bookTicket(cruise_id, type, seatno);

            // on ticket booking unsuccessful
            if (!ticket_status) {
                // error handling
            }
            // on ticket booking successfull
            else {
                // ask for passenger details
                Passenger passenger;
                askPassengerDetails(passenger);
                ticket.displayTicket();
            }
        }
    }
    else if (input == 'C')
    {
        // cancelTicket();
    }
    else if (input == 'P')
    {
        // passenegerStatus(); --to be made
    }
    else if (input == 'F')
    {
        // cruiseStatus(); --to be made
    }
    // exit the program
    else if (input == 'E')
    {   cout << "------------------------------------" << endl;
        cout << "|  Thankyou for using our service! |" << endl;
        cout << "|                 -Sealink Travels |" << endl;
        cout << "------------------------------------" << endl;
        exit(0);
    }
    else
    {
        cout << "ERROR! Please enter the specified Queries only." << endl;
    }

    return 1;
}
