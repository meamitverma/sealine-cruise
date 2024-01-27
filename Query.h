#include<bits/stdc++.h>
#include "Ticket.h"
using namespace std;

/*S: scheduling
C: cancel the passenger
P: Passenger status
F: cruise status
E: exit */

// ------Waitlist to be made if bookings are full similar to IRCTC--------

class Query{
    private: char input;
    public: 
            void takeInput(){
                cout<<"Enter 'S' for scheduling a Cruise, 'C' for cancelling the passenger ticket, 'P' for Passenger status, 'F' for Cruise status, 'E' to exit: " <<endl;  
                cin>>input;
                if(input == 'S'){
                    
                    //bookTicket();
                } else if(input == 'C'){
                    //cancelTicket();
                } else if(input == 'P'){
                    //passenegerStatus(); --to be made 
                } else if(input == 'F'){
                    //cruiseStatus(); --to be made
                } else if(input == 'E'){
                    cout<<"Exit succeful "<<endl;
                } else{
                    cout<<"ERROR! Please enter the specified Queries only."<<endl;
                }
            }

};
