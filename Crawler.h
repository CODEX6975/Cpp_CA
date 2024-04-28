#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(int bugId, int x, int y, Direction dir, int bugSize);
    virtual ~Crawler();

    virtual void move() override;
};

#endif // CRAWLER_H
