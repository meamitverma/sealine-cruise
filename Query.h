#include <bits/stdc++.h>
using namespace std;

/*S: scheduling
C: cancel the passenger
P: Passenger status
F: cruise status
E: exit */

// ------Waitlist to be made if bookings are full similar to IRCTC--------

void processInput(char input)
{   
    input = toupper(input);
    if (input == 'S')
    {
        // bookTicket();
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
}
