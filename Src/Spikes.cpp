#include "../Headers/Spikes.hpp"
#include "../Headers/Global.hpp"



Spikes::Spikes(){
    x = initial_location_spike;

load_image();

}

void Spikes::set_location(float user_x){


x = user_x;

}
void Spikes::load_image(){
    texture.loadFromFile("Resources/Images/spikes.png");
}

void Spikes::movement(float speed){
    x  =  x - speed;
}

std::string Spikes::draw(sf::RenderWindow& window){
    sprite.setTexture(texture);
    sprite.setPosition(x, y); 
    sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
    if (x!=-200){
        movement(0.5);
    }else{
        return "done";
    }
    window.draw(sprite);
    return "null";
}


sf::Sprite& Spikes::get_sprite(){
    return sprite;
}