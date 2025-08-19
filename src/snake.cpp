#include "../header/snake.h"

Snake::Snake(int startX, int startY) {
    Point head(startX, startY);
    body.push_back(head);
    drxn = "RIGHT";
}

void Snake::move() {
    Point head = body[0];
    Point newHead = head;

    if (drxn == "UP") newHead.y -= 1;
    else if (drxn == "DOWN") newHead.y += 1;
    else if (drxn == "LEFT") newHead.x -= 1;
    else if (drxn == "RIGHT") newHead.x += 1;

    body.insert(body.begin(), newHead);

    if (!pendingGrow) {
        body.pop_back();  
    } else {
        pendingGrow = false;  
    }
}

void Snake::setGrowPending() {
    pendingGrow = true;
}

void Snake::changeDrxn(std::string newDrxn) {
    if ((drxn == "UP" && newDrxn == "DOWN") ||
        (drxn == "DOWN" && newDrxn == "UP") ||
        (drxn == "LEFT" && newDrxn == "RIGHT") ||
        (drxn == "RIGHT" && newDrxn == "LEFT")) return;
    drxn = newDrxn;
}

bool Snake::checkSelfCollision() {
    Point head = body[0];
    for (int i = 1; i < body.size(); ++i) {
        if (body[i].x == head.x && body[i].y == head.y) return true;
    }
    return false;
}

Point Snake::getHead() {
    return body[0];
}

std::vector<Point> Snake::getBody() {
    return body;
}

std::string Snake::getDirection() {
    return drxn;
}