#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class HighScoreManager {
public:
    void SaveHighScore(const std::string& playerName, int score);
    /* Когда у тебя длинные типы, используй using */
    std::vector<std::pair<std::string, int>> GetHighScores() const;

private:
    std::vector<std::pair<std::string, int>> highScores;
    void SortAndSaveScores();
};