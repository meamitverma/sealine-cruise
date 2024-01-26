#include<bits/stdc++.h>
// #include "Cruise.cpp"
// #include "Global.cpp"

using namespace std;




// Function to read cruise details from a file
void readCruisesFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    // vector<Cruise> cruises;
    string line;

    while (getline(file, line)) {
        // Assuming each attribute is on a separate line
        int depart_time, arrival_time;
        string depart_city, arrival_city;

        // getting id from the file and creating its object
        string cruise_id;
        getline(file, cruise_id);
        
        // cruise object
        Cruise cruise(cruise_id);

        // departure time
        file >> depart_time;
        getline(file, line);
        getline(file, depart_city);
        file >> arrival_time;
        getline(file, line);
        getline(file, arrival_city);


        // setting all the values to the cruise object
        cruise.setDepartureTime(depart_time);
        cruise.setDepartureCity(depart_city);
        cruise.setArrivalTime(arrival_time);
        cruise.setArrivalCity(arrival_city);
        cruise.calculateDuration();
        
        cruises.push_back(cruise);
    }

    file.close();
}

// int main() {
//     string filename = "cruise_data.txt"; 
//     vector<Cruise> cruisess = readCruisesFromFile(filename);
    
//     cruises = cruisess;

//     return 0;
// }