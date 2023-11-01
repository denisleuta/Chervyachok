#pragma once
class Obstacle {
public:
    Obstacle(int startX, int startY);

    int GetX() const;

    int GetY() const;

private:
    int x, y;
};