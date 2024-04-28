#ifndef BUG_H
#define BUG_H

#include <list>
#include <utility>

using namespace std;

enum class Direction { North, East, South, West };

class Bug {
protected:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int bugId, int x, int y, Direction dir, int bugSize);
    virtual ~Bug();

    virtual void move() = 0;
    bool isWayBlocked();

    int getId() const;
    pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    list<pair<int, int>> getPath() const;
    void setAlive(bool isAlive) {
        alive = isAlive;
    }
};

#endif // BUG_H
