#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    int width;
    int height;

public:
    Board(int w, int h) : width(w), height(h) {}

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    bool isInside(int x, int y) const {
        return x >= 0 && y >= 0 && x < width && y < height;
    }
};

#endif