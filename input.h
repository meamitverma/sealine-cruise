#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file for reading
    std::ifstream inputFile("example.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        // Process each line as needed
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
