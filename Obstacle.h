#pragma once
#include "GameObject.h"
class Obstacle :public GameObject {
public:
    /* Конструктор с такой реализацией точно не
     * надо помещать в cpp */
    Obstacle(int startX, int startY);

};