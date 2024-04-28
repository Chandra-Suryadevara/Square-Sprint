#pragma once
#include <iostream>

class HighScoreManager {
private:
    std::string fileName;

public:
    HighScoreManager();
    void saveHighScore(int score);


    int getHighScore();
};

