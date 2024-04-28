#include "Board.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "Bug Simulation Game\n";
    cout << "1. Initialize Bug Board\n";
    cout << "2. Display All Bugs\n";
    cout << "3. Find a Bug\n";
    cout << "4. Tap the Bug Board\n";
    cout << "5. Display Life History of all Bugs\n";
    cout << "6. Exit\n";
}

int main() {
    Board board;

    int choice;
    bool exitGame = false;

    while (!exitGame) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Initialize Bug Board
                board.initializeBugBoard("/C++Projects/C++_CA/bugs.txt");
                cout << "Bug board initialized.\n";
                break;
            case 2:
                // Display All Bugs
                board.displayAllBugs();
                break;
            case 3:
                // Find a Bug
                int bugId;
                cout << "Enter Bug ID to find: ";
                cin >> bugId;
                board.findBugByID(bugId);
                break;
            case 4:
                // Tap the Bug Board
                board.tapBugBoard();
                cout << "Bug board tapped.\n";
                break;
            case 5:
                // Display Life History of all Bugs
                board.displayLifeHistory();
                break;
            case 6:
                // Exit
                cout << "Exiting the game.\n";
                exitGame = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
