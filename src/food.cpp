#include "../header/food.h"

Food::Food(int board_width, int board_height){
    std::srand(std::time(nullptr)); 
    respawn(board_width, board_height);
}

void Food::respawn(int board_width, int board_height){
    int x = 1 + std::rand() % (board_width - 2);
int y = 1 + std::rand() % (board_height - 2);

    position = Point(x, y);
}

Point Food::getPosition(){
    return position;
}