#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Square_Main {
private:
    int speed;
    bool dead;
    int score;
    const int y;
    float x;

public:
    Square_Main(); // Corrected constructor name
    void reset();
    bool is_dead();
    ~Square_Main(); // Corrected destructor name
    void draw(sf::RenderWindow& i_window);
}; // Added semicolon at the end of the class definition
