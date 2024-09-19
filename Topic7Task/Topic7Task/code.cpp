#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FootballPlayer {
    char lastName[50];   
    char position[20];   
    int age;             
    int games;           
    int goals;           
};


void createBinaryFile(const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Could not create the file!" << endl;
        return;
    }

    
    FootballPlayer players[] = {
        {"Ivanov", "Forward", 25, 5, 3},
        {"Petrov", "Defender", 30, 5, 0},
        {"Sidorov", "Forward", 27, 5, 4},
        {"Kuznetsov", "Midfielder", 24, 5, 2},
        {"Smirnov", "Forward", 28, 5, 5}
    };

    for (const auto& player : players) {
        outFile.write(reinterpret_cast<const char*>(&player), sizeof(FootballPlayer));
    }

    outFile.close();
}


void findBestForward(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Could not open the file!" << endl;
        return;
    }

    FootballPlayer player;
    FootballPlayer bestForward;
    bestForward.goals = -1;

    while (inFile.read(reinterpret_cast<char*>(&player), sizeof(FootballPlayer))) {
        if (strcmp(player.position, "Forward") == 0 && player.games == 5) {
            if (player.goals > bestForward.goals) {
                bestForward = player;
            }
        }
    }

    inFile.close();

    if (bestForward.goals != -1) {
        cout << "Best forward over the last 5 games: " << bestForward.lastName
            << ", Goals: " << bestForward.goals << endl;
    }
    else {
        cout << "No forwards found for the last 5 games!" << endl;
    }
}

int main() {
    const string filename = "football_players.dat";

    createBinaryFile(filename);

    findBestForward(filename);

    return 0;
}