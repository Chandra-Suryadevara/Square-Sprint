#pragma once


#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Spikes {
private:
    int speed;
    const int y = 1620;
    float x;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Spikes();
    void load_image();
    
    
}; 
