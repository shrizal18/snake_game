#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <string>
#include "point.h"

class Snake {
    std::vector<Point> body;
    std::string drxn;
    bool pendingGrow = false;

public:
    Snake(int startX, int startY);
    void move();
    void setGrowPending(); 
    void changeDrxn(std::string newDrxn);
    bool checkSelfCollision();
    Point getHead();
    int getLength() { return body.size(); }
    std::vector<Point> getBody();
    std::string getDirection();
};

#endif