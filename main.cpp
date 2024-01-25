#include<bits/stdc++.h>
#include "Cruise.h"
#include "Passenger.h"
#include "manager.h"
#include "Global.h"
#include "output.h"

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
    vector<string> cruises_ids = findCruises(cruises, origin_city, dest_city);
    // printCruises(cruises, cruises_ids);
    

    // show the available cruise
    // take the passenger details for proceeding to the seat booking

    return 0;
}