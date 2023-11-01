#include "GameRenderer.h"
#include <iostream>

void GameRenderer::Draw(const Snake& snake, const Fruit& fruit, const std::vector<Obstacle>& obstacles, int width, int height, int score) const {
    system("cls");
    for (int i = 0; i < width + 1; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                std::cout << "#";
            if (i == snake.GetY() && j == snake.GetX())
                std::cout << "0";
            else if (i == fruit.GetY() && j == fruit.GetX())
                std::cout << "F";
            else {
                bool isObstacle = false;
                for (const Obstacle& obstacle : obstacles) {
                    if (obstacle.GetX() == j && obstacle.GetY() == i) {
                        std::cout << "@";
                        isObstacle = true;
                        break;
                    }
                }
                if (!isObstacle) {
                    if (snake.IsColliding(j, i))
                        std::cout << "o";
                    else
                        std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 1; i++)
        std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}