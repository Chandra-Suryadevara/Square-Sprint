#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Square_Main {
private:
    bool dead;
    int score;
    const int intial_y = 1620;
    float y;
    bool reach = false;
    float x;
    bool is_jumping =false;
    sf::Texture texture;
    sf::Sprite sprite_local;

public:
    Square_Main(); // Corrected constructor name
    void reset();
    bool is_dead();
    void load_image();
    void jump();
    void intial_movement(float temp_speed);
    sf::Sprite& get_sprite();
    ~Square_Main(); // Corrected destructor name
    void draw(sf::RenderWindow& i_window,bool pressed);
    void draw_dead(sf::RenderWindow& window);
}; // Added semicolon at the end of the class definition
