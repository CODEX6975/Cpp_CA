#include "Bug.h"

Bug::Bug(int bugId, int x, int y, Direction dir, int bugSize)
        : id(bugId), position(make_pair(x, y)), direction(dir), size(bugSize), alive(true) {}

Bug::~Bug() {}

bool Bug::isWayBlocked() {
    int x = position.first;
    int y = position.second;

    switch (direction) {
        case Direction::North:
            return y == 0;
        case Direction::East:
            return x == 9;
        case Direction::South:
            return y == 9;
        case Direction::West:
            return x == 0;
    }
    return false;
}

int Bug::getId() const {
    return id;
}

pair<int, int> Bug::getPosition() const {
    return position;
}

Direction Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

list<pair<int, int>> Bug::getPath() const {
    return path;
}
