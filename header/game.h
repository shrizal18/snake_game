#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include "board.h"

class Game {
private:
    Food food;
    Snake snake;
    Board board;
    bool running;

public:
    Game(int width, int height);
    void run();
    void update();
    void draw();
    void processInput();
    void testSelfCollision();
};

#endif