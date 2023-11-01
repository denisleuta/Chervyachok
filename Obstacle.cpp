#include "Obstacle.h"



    Obstacle::Obstacle(int startX, int startY) : x(startX), y(startY) {}

    int Obstacle::GetX() const {
        return x;
    }

    int Obstacle::GetY() const {
        return y;
    }

