#pragma once


#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Block {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool touched;
    int location_x;
    int location_y;
    bool movement_started;

public:
    Block();
    bool get_touched();
    void load_image();
    bool get_movestart();
    void movement(float temp_speed);
    sf::Sprite& get_sprite();
    void draw(sf::RenderWindow& window,bool touch);
    

void reset();
    
}; 
