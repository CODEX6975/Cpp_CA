#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int bugId, int x, int y, Direction dir, int bugSize, int hopLen)
        : Bug(bugId, x, y, dir, bugSize), hopLength(hopLen) {}

Hopper::~Hopper() {}

void Hopper::move() {
    if (!isAlive()) return;

    int x = position.first;
    int y = position.second;


    switch (direction) {
        case Direction::North:
            for (int i = 0; i < hopLength; ++i) {
                if (y > 0) --y;
                else break;
            }
            position.second = y;
            break;
        case Direction::East:
            for (int i = 0; i < hopLength; ++i) {
                if (x < 9) ++x;
                else break;
            }
            position.first = x;
            break;
        case Direction::South:
            for (int i = 0; i < hopLength; ++i) {
                if (y < 9) ++y;
                else break;
            }
            position.second = y;
            break;
        case Direction::West:
            for (int i = 0; i < hopLength; ++i) {
                if (x > 0) --x;
                else break;
            }
            position.first = x;
            break;
    }

    path.push_back(make_pair(x, y));
}
