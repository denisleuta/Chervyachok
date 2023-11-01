#pragma once
class Fruit {
public:
    Fruit();
    Fruit(int maxX, int maxY);
    int GetX() const;
    int GetY() const;
    void Respawn(int maxX, int maxY);
private:
    int x, y;
};