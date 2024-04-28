#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Board::Board() {}

Board::~Board() {
    // Free memory allocated for Bug objects in bugVector
    for (Bug* bug : bugVector) {
        delete bug;
    }
}

void Board::initializeBugBoard(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    char bugType;
    int bugId, x, y, size, hopLength;

    while (file >> bugType >> bugId >> x >> y >> size) {
        Direction dir;
        switch (bugType) {
            case 'C':
                dir = Direction::East; //default direction for crawler
                break;
            case 'H':
                file >> hopLength;
                dir = Direction::North; //default direction for hopper
                break;
            default:
                cout << "Error: Invalid bug type " << bugType << endl;
                continue;
        }

        if (bugType == 'C') {
            bugVector.push_back(new Crawler(bugId, x, y, dir, size));
        } else {
            bugVector.push_back(new Hopper(bugId, x, y, dir, size, hopLength));
        }

        //update cellMap
        cellMap[make_pair(x, y)].push_back(bugVector.back());
    }

    file.close();
}

void Board::displayAllBugs() {
    cout << "All Bugs:" << endl;
    for (Bug* bug : bugVector) {
        cout << "ID: " << bug->getId() << " Type: " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper")
             << " Location: (" << bug->getPosition().first << "," << bug->getPosition().second << ")"
             << " Size: " << bug->getSize() << " Direction: " << static_cast<int>(bug->getDirection())
             << " Status: " << (bug->isAlive() ? "Alive" : "Dead") << endl;
    }
}

void Board::findBugByID(int bugId) {
    bool found = false;
    for (Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            found = true;
            cout << "Bug found:" << endl;
            cout << "ID: " << bug->getId() << " Type: " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper")
                 << " Location: (" << bug->getPosition().first << "," << bug->getPosition().second << ")"
                 << " Size: " << bug->getSize() << " Direction: " << static_cast<int>(bug->getDirection())
                 << " Status: " << (bug->isAlive() ? "Alive" : "Dead") << endl;
            break;
        }
    }
    if (!found) {
        cout << "Bug " << bugId << " not found." << endl;
    }
}

void Board::tapBugBoard() {
    for (Bug* bug : bugVector) {
        bug->move();
        pair<int, int> newPos = bug->getPosition();
        pair<int, int> oldPos = make_pair(newPos.first, newPos.second);

        //check if there are multiple bugs in the new position
        if (cellMap.count(newPos) && cellMap[newPos].size() > 1) {
            // Implement fight/eat functionality here
            // You need to decide how to handle fights and update bugVector and cellMap accordingly
            // This is just a placeholder implementation
            bug->setAlive(false); // Mark the bug as dead for now
        }

        // Update cellMap
        cellMap[newPos].push_back(bug);
        cellMap[oldPos].erase(std::remove(cellMap[oldPos].begin(), cellMap[oldPos].end(), bug), cellMap[oldPos].end());
    }
}

void Board::displayLifeHistory() {
    cout << "Life History of Bugs:" << endl;
    for (Bug* bug : bugVector) {
        cout << "ID: " << bug->getId() << " Type: " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper")
             << " Path: ";
        for (auto& pos : bug->getPath()) {
            cout << "(" << pos.first << "," << pos.second << ")";
        }
        cout << " Status: " << (bug->isAlive() ? "Alive" : "Dead") << endl;
    }
}

void Board::writeLifeHistoryToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    file << "Life History of Bugs:" << endl;
    for (Bug* bug : bugVector) {
        file << "ID: " << bug->getId() << " Type: " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper")
             << " Path: ";
        for (auto& pos : bug->getPath()) {
            file << "(" << pos.first << "," << pos.second << ")";
        }
        file << " Status: " << (bug->isAlive() ? "Alive" : "Dead") << endl;
    }

    file.close();
}

void Board::displayAllCells() {
    cout << "All Cells:" << endl;
    for (auto& entry : cellMap) {
        cout << "(" << entry.first.first << "," << entry.first.second << "): ";
        if (entry.second.empty()) {
            cout << "empty" << endl;
        } else {
            for (Bug* bug : entry.second) {
                cout << (dynamic_cast<Crawler*>(bug) ? "Crawler " : "Hopper ") << bug->getId() << ", ";
            }
            cout << endl;
        }
    }
}

void Board::runSimulation() {
    int round = 0;
    bool gameover = false;

    // Continue simulation until the game is over
    while (!gameover) {
        cout << "Round " << round << endl;
        cout << "----------------------------------" << endl;

        // Simulate tapping the bug board
        tapBugBoard();

        // Display current state of the bug board
        displayAllCells();

        // Check if the game is over
        gameover = isGameOver();

        // Increment round counter
        round++;
    }

    cout << "Game Over!" << endl;
}

bool Board::isGameOver() {
    // Check if only one bug is alive
    int aliveCount = 0;
    for (Bug* bug : bugVector) {
        if (bug->isAlive()) {
            aliveCount++;
        }
    }
    return aliveCount == 1;
}
