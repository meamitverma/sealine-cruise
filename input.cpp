/*#include <iostream>
#include <fstream>
#include <string>
#include "Cruise.h"
using namespace std;

int main() {
    // Open a file for reading
    ifstream inputFile("example.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    // Read the file line by line
    string line;
    while (getline(inputFile, line)) {
        // Process each line as needed
        //std::cout << line << std::endl;
        istringstream iss(line);
        
        // Variables to store data from the file
        int id, departureTime, arrivalTime, duration;
        string departureCity, arrivalCity;

        // Read data from the stringstream
        if (iss >> id >> departureTime >> departureCity >> arrivalTime) {
            // Create a Cruise object with the read data
            Cruise cruise(id);
            cruise.setDepartureTime(departureTime);
            cruise.setDepartureCity(departureCity);
            cruise.setArrivalTime(arrivalTime);
            cruise.setArrivalCity(arrivalCity);
            cruise.setDuration(duration);
        

            // Process each Cruise object as needed
            cout << "Cruise ID: " << cruise.getID() << endl;
            cout << "Departure Time: " << cruise.getDepartureTime() << endl;
            cout << "Departure City: " << cruise.getDepartureCity() << endl;
            cout << "Arrival Time: " << cruise.getArrivalTime() << endl;
            cout << "Arrival City: " << cruise.getArrivalCity() << endl;
            cout << "Duration: " << cruise.getDuration() << endl;
            cout << "-----------------------" << std::endl;
        } else {
            cerr << "Error reading line from the file!" << std::endl;
        }
    }
    

    // Close the file
    inputFile.close();

    return 0;
}*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct Cruise {
    std::string id;
    std::string departureCity;
    int departureTime;
    int arrivalTime;
    std:: string arrivalCity;
};

// Function to read cruise details from a file
std::vector<Cruise> readCruisesFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    std::vector<Cruise> cruises;
    std::string line;

    while (std::getline(file, line)) {
        Cruise cruise;
        
        // Assuming each attribute is on a separate line
        std::getline(file, cruise.id);
        file >> cruise.departureTime;
        std :: getline(file, line);
        std::getline(file, cruise.departureCity);
        file >> cruise.arrivalTime;
        std::getline(file, line);
        std :: getline(file, cruise.arrivalCity);

        
        cruises.push_back(cruise);
    }

    file.close();
    return cruises;
}

int main() {
    std::string filename = "example.txt";  // Adjust the filename as needed
    std::vector<Cruise> cruises = readCruisesFromFile(filename);

    // Print the read cruise details
    std::cout << "Cruise Details:\n";
    for (const Cruise& cruise : cruises) {
        std::cout << "Name: " << cruise.id << std::endl;
        std::cout << "Departure Time: " << cruise.departureTime << std::endl;
        std::cout << "Departure City: " << cruise.departureCity << std::endl;
        std::cout << "Arrival Time: " << cruise.arrivalTime << std:: endl;
        std:: cout << "Arrival City: " << cruise.arrivalCity << std:: endl;
        std::cout << std::endl; // Add a separator between cruises
    }

    return 0;
}