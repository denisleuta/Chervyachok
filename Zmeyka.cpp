#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Fruit.h"
#include "Snake.h"
#include "GameLogic.h"
#include "GameRenderer.h"
#include "HighScoreManager.h"
#include "InputHandler.h"
#include "Obstacle.h"
#include "SnakeGames.h"
#include "Timer.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    Timer gameTimer;
    double gameTime = 0.0;
    HighScoreManager highScoreManager; // Создание экземпляра HighScoreManager

    while (true) {
        SnakeGame game(20, 20);
        game.Setup();
        game.RunGameLoop();

        gameTime = gameTimer.GetElapsedTime();
        cout << "Время вашей игровой сессии: " << gameTime << " секунд" << endl;

        int score = game.GetScore();

        cout << "Введите ваше имя: ";
        string playerName;
        cin >> playerName;

        highScoreManager.SaveHighScore(playerName, score);

        cout << "Лучшие счета:\n";
        vector<pair<string, int>> highScores = highScoreManager.GetHighScores();
        for (const auto& entry : highScores) {
            cout << entry.first << ": " << entry.second << endl;
        }

        this_thread::sleep_for(chrono::seconds(3));
    }

    return 0;
}