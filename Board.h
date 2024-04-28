#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include "Bug.h"
#include <string>

class Board {
private:
    std::vector<Bug*> bugVector; // Vector to store pointers to Bug objects
    std::map<std::pair<int, int>, std::vector<Bug*>> cellMap; // Map to store bugs in each cell

public:
    Board();
    ~Board();
    bool isGameOver();
    void initializeBugBoard(const std::string& filename);// Initialize the bug board from file
    void displayAllBugs(); // Display details of all bugs on the board
    void findBugByID(int bugId); // Find a bug by its ID and display its details
    void tapBugBoard(); // Simulate tapping the bug board
    void displayLifeHistory(); // Display life history of all bugs
    void writeLifeHistoryToFile(const std::string& filename); // Write life history of all bugs to a file
    void displayAllCells(); // Display all cells and the bugs occupying each cell
    void runSimulation(); // Run simulation by tapping the board every second
};

#endif // BOARD_H
