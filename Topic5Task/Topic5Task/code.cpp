#include <iostream>
#include <fstream>
#include <cstring> // For string operations
#include <sstream> // For string stream
using namespace std;

int main() {
    ifstream inputFile("input.txt"); // Open file for reading
    ofstream outputFile("output.txt"); // Open file for writing

    if (!inputFile.is_open()) {
        cerr << "Failed to open file input.txt" << endl;
        return 1;
    }

    int wordLengthToRemove;
    cout << "Enter the length of words to remove: ";
    cin >> wordLengthToRemove; // Get the length from the user

    string line;
    while (getline(inputFile, line)) { // Read the file line by line
        stringstream ss(line); // Create a stream to process the line
        string word;
        string modifiedLine;

        while (ss >> word) { // Extract words from the line
            if (word.length() != wordLengthToRemove) { // If the word length is not equal to the specified length
                modifiedLine += word + " "; // Add the word to the new line
            }
        }

        outputFile << modifiedLine << endl; // Write the modified line to the output file
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Processing completed. Results have been written to output.txt." << endl;

    return 0;
}