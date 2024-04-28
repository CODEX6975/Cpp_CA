#include "Crawler.h"
#include <cstdlib>

Crawler::Crawler(int bugId, int x, int y, Direction dir, int bugSize)
        : Bug(bugId, x, y, dir, bugSize) {}

Crawler::~Crawler() {}

void Crawler::move() {
    if (!isAlive()) return;

    int x = position.first;
    int y = position.second;


    switch (direction) {
        case Direction::North:
            if (y > 0) {
                --y;
                position.second = y;
            }
            break;
        case Direction::East:
            if (x < 9) {
                ++x;
                position.first = x;
            }
            break;
        case Direction::South:
            if (y < 9) {
                ++y;
                position.second = y;
            }
            break;
        case Direction::West:
            if (x > 0) {
                --x;
                position.first = x;
            }
            break;
    }

    path.push_back(make_pair(x, y));
}
