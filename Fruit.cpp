#include "Fruit.h"
#include <algorithm>


    Fruit::Fruit() : x(0), y(0) {}

    Fruit::Fruit(int maxX, int maxY) {
        Respawn(maxX, maxY);
    }

    int Fruit::GetX() const {
        return x;
    }

    int Fruit::GetY() const {
        return y;
    }

    void Fruit::Respawn(int maxX, int maxY) {
        x = rand() % maxX;
        y = rand() % maxY;
    }

