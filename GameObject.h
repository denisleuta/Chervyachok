#pragma once
class GameObject {
public:
    /* Да, мы вам говорили разбивать на файлы по максимуму.
     * Но вы, вероятно, уже знаете, что такое inline функции. 
     * Так что функции с реализацией в одну-две строки можно
     * и в заголовке оставить, особенно если этих функций пару штук  */
    GameObject(int startX, int startY);
    int GetX() const;
    int GetY() const;

protected:
    int x, y;
};