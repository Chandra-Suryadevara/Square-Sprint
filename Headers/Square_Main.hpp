#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Square_Main {
private:
    int speed;
    bool dead;
    int score;
    const int y = 1620;
    float x;

public:
    Square_Main(); // Corrected constructor name
    void reset();
    bool is_dead();
    
    void movement(int temp_speed);
    ~Square_Main(); // Corrected destructor name
    void draw(sf::RenderWindow& i_window);
    void draw_dead(sf::RenderWindow& window);
}; // Added semicolon at the end of the class definition
