#pragma once


#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Spikes {
private:
    int y = 740;
    float x;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Spikes();
    void load_image();
    void set_location(float user_x);
    sf::Sprite& get_sprite();
    std::string draw(sf::RenderWindow& window);
    void movement(float speed);
    
    
}; 
