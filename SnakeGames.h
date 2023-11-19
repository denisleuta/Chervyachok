#pragma once
/* В Файл надо включать только те заогловки, которые 
 * в нем непосредственно используются. Нельзя надеяться
 * на транзитивное включение, потому что его всегда
 * случайно могут убрать, потому что не знают, что есть
 * какая-то зависимость в других файлах */
#include "Snake.h"
#include "Fruit.h"
#include "Obstacle.h"
#include <vector>
#include "GameRenderer.h"
#include "GameLogic.h"
#include "HighScoreManager.h"
#include "InputHandler.h"
#include <Windows.h> //а как мне пользоваться
#include <fstream>

class SnakeGame {
public:
    SnakeGame(int w, int h);
    int GetScore() const;
    void Setup();
    void RunGameLoop();
    void Obstacles();
    void GenerateObstacles();
private:
    bool IsGameOver() const; // почему это приватное? оно же const

    bool gameOver;
    const int width;
    const int height;
    int score;
    Snake snake;
    Fruit fruit;
    std::vector<Obstacle> obstacles;
    const int numObstacles = 15;
    /* Хорошо, что enum, но не тот. Надо enum class, он не позволяет
     * неявного преобразования */
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
};
