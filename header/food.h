#ifndef FOOD_H
#define FOOD_H
#include "point.h"
#include<cstdlib> //for random funciton {rand()}
#include <ctime> //for time:- seeding random function

class Food{
    private:
        Point position; //position holds the location of the food as a Point(x,y) 
    public:
        Food(int board_width, int board_height);
        //^creating a new food object immediatelty spawns the food somewhere on board

        void respawn(int board_width, int board_height);
        //^randomly changes the food position called after snake head touches the food block

        Point getPosition();
        //getter funct to see where the food currently is

};

#endif