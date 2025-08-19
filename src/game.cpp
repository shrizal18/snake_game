#include "../header/game.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

Game::Game(int width, int height)
    : snake(width / 2, height / 2),
      food(width, height),
      board(width, height),
      running(true) {}

void Game::draw() {
    system("cls"); 

    Point foodPos = food.getPosition();
    std::vector<Point> body = snake.getBody();

    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
            // Wall borders
            if (y == 0 || y == board.getHeight() - 1 || x == 0 || x == board.getWidth() - 1) {
                std::cout << "#";
                continue;
            }

            bool printed = false;

            // Snake body
            for (int i = 0; i < body.size(); ++i) {
                if (body[i].x == x && body[i].y == y) {
                    std::cout << (i == 0 ? "@" : "0"); // Head as @, body as 0
                    printed = true;
                    break;
                }
            }

            // Food
            if (!printed && foodPos.x == x && foodPos.y == y) {
                std::cout << "F";
                printed = true;
            }

            // Empty
            if (!printed) std::cout << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Score: " << snake.getLength() - 1 << "\n";
}


void Game::processInput() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
            case 'w': case 'W': case 72: snake.changeDrxn("UP"); break;
            case 's': case 'S': case 80: snake.changeDrxn("DOWN"); break;
            case 'a': case 'A': case 75: snake.changeDrxn("LEFT"); break;
            case 'd': case 'D': case 77: snake.changeDrxn("RIGHT"); break;
        }
    }
}

void Game::run() {
    while (running) {
        draw();
        processInput();
        update();
        std::this_thread::sleep_for(std::chrono::milliseconds(130));
    }

    draw();
    std::cout << "Game Over! Final Score: " << snake.getLength() - 1 << "\n";
}

void Game::update() {
    Point currentHead = snake.getHead();
    Point nextHead = currentHead;

    if (snake.getDirection() == "UP") nextHead.y -= 1;
    else if (snake.getDirection() == "DOWN") nextHead.y += 1;
    else if (snake.getDirection() == "LEFT") nextHead.x -= 1;
    else if (snake.getDirection() == "RIGHT") nextHead.x += 1;

    if (!board.isInside(nextHead.x, nextHead.y)) {
        running = false;
        return;
    }

    if (nextHead.x == food.getPosition().x && nextHead.y == food.getPosition().y) {
        snake.setGrowPending(); 
        food.respawn(board.getWidth(), board.getHeight());
    }

    snake.move(); // always called, grows if flagged

    if (snake.checkSelfCollision()) {
        running = false;
    }
}