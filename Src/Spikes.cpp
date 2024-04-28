#include "../Headers/Spikes.hpp"
#include "../Headers/Global.hpp"
#include <iostream>



Spikes::Spikes(){
    x = initial_location_spike;
    movementlock=true;

load_image();

}

void Spikes::set_location(float user_x){


x = user_x;

}
void Spikes::load_image(){
    texture.loadFromFile("Resources/Images/spikes.png");
}

void Spikes::movement(float speed){
    if(movementlock == true){
    x  =  x - speed;
    }
}

void Spikes::resume_movement(){
    movementlock = true;
}
void Spikes::stop_movement(){
    movementlock= false;
}

std::string Spikes::draw(sf::RenderWindow& window, float speed){
    sprite.setTexture(texture);
    sprite.setPosition(x, y); 
    sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
    

    if (x>-100){
        
        movement(speed);
        
    }else{
        return "done";
    }
    window.draw(sprite);
    return "null";
}


sf::Sprite& Spikes::get_sprite(){
    return sprite;
}