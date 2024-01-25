#include<bits/stdc++.h>
#include "Cruise.h"

using namespace std;

// returns the list of available cruise ids
vector<Cruise> findCruises(vector<Cruise> cruises, string origin, string dest) {
    vector<string> available_cruises;
    int n = cruises.size();
    for (int i = 0; i < n; i++) {
        Cruise cruise = cruises[i];
        // get the cruise origin city and cruise destination
        string cruise_origin = cruise.getDepartureCity();
        string cruise_dest = cruise.getArrivalCity();

        // if passengers origin & dest matches with cruises origin & dest
        // add it to the available cruises
        if (cruise_origin == origin && cruise_dest == dest) {
            available_cruises.push_back(cruise.getID());
        }   
    }
}