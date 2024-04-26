#pragma once


#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Spikes {
private:
    const int y = 1685;
    float x;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Spikes();
    void load_image();
    void set_location(float user_x);
    sf::Sprite& get_sprite();
    void draw(sf::RenderWindow& window);
    void movement(float speed);
    
    
}; 
