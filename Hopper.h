#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength; // Private member for hop length

public:
    Hopper(int bugId, int x, int y, Direction dir, int bugSize, int hopLen);
    virtual ~Hopper();

    virtual void move() override;
};

#endif // HOPPER_H
