#pragma once
class Snake {
public:
    Snake();
    Snake(int startX, int startY);
    void Move(int newX, int newY);
    bool IsColliding(int newX, int newY) const;
    int GetX() const;
    int GetY() const;

private:
    int x, y;
    int tailX[100];
    int tailY[100];
    int nTail;
};