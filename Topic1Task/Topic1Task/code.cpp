#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    int time; 
    cout << "Enter the time in minutes: ";
    cin >> time;


    long long numberOfBacteria = pow(2, time);


    ofstream outputFile("bacteria_count.txt");
    if (!outputFile) {
        cerr << "Unable to open file for writing!" << endl;
        return EXIT_FAILURE;
    }


    outputFile << "Number of bacteria after " << time << " minutes: " << numberOfBacteria << endl;


    outputFile.close();

    cout << "The number of bacteria after " << time << " minutes has been written to 'bacteria_count.txt'." << endl;

    return 0;
}