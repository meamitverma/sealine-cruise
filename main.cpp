#include<bits/stdc++.h>
// #include "Cruise.h"
// #include "Passenger.h"
#include "manager.h"
#include "Global.h"
// #include "output.h"
// #include "input.h"

using namespace std;

int main() {
    // welcome to the sealink
    cout << "Welcome to SeaLink Travels" << endl;


    // find the desired cruise for the user where to where
    string origin_city, dest_city;
    // origin
    cout << "Enter orgin city: " << endl;
    cin >> origin_city;

    // dest
    cout << "Enter destination city: " << endl;
    cin >> dest_city;

    // show cruises 
    Cruise c1("123");
    c1.setDepartureCity("Kochi");
    c1.setArrivalCity("Lk");

    Cruise c2("12321");
    c2.setDepartureCity("Chennai");
    c2.setArrivalCity("ad");

    vector<Cruise> cruises;
    cruises.push_back(c1);
    cruises.push_back(c2);
    
    vector<Cruise> available_cruises = findCruises(cruises, origin_city, dest_city);
    cout << "Available Cruises:" << endl;
    for (Cruise c : available_cruises) {
        cout << c.getID() << endl;
        cout << c.getDepartureCity() << endl;
        cout << c.getArrivalCity() << endl;
        cout << endl;
    }

    // show the available cruise
    // take the passenger details for proceeding to the seat booking

    return 0;
}