#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct Cruise {
    std::string name;
    std::string destination;
    int duration;
    double price;
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
        std::getline(file, cruise.name);
        std::getline(file, cruise.destination);
        file >> cruise.duration;
        file >> cruise.price;
        
        cruises.push_back(cruise);
    }

    file.close();
    return cruises;
}

int main() {
    std::string filename = "cruises.txt";  // Adjust the filename as needed
    std::vector<Cruise> cruises = readCruisesFromFile(filename);

    // Print the read cruise details
    std::cout << "Cruise Details:\n";
    for (const Cruise& cruise : cruises) {
        std::cout << "Name: " << cruise.name << std::endl;
        std::cout << "Destination: " << cruise.destination << std::endl;
        std::cout << "Duration: " << cruise.duration << " days" << std::endl;
        std::cout << "Price: $" << cruise.price << std::endl;
        std::cout << std::endl; // Add a separator between cruises
    }

    return 0;
}
