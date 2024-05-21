#include <iostream>
#include "../Headers/Block.hpp"
#include "../Headers/Global.hpp"

#include <SFML/Graphics.hpp>



Block::Block(){
    touched = false;
    location_x = Block_start;
    location_y=Block_height;
    load_image();
    movement_started = false;   
}

bool Block::get_touched(){
    return touched;
}

void Block::load_image(){
    texture.loadFromFile("Resources/Images/block.png");
    
}

void Block::movement(float temp_speed){

if (location_x > 0){
    movement_started = true;
    location_x = location_x-temp_speed;
}else{
    reset();
    
}

}




void Block::reset(){
    location_x=Block_start;
    movement_started=false;
    touched =false;
    load_image();
}

bool Block::get_movestart(){
    return movement_started;
}

sf::Sprite& Block::get_sprite(){
    return sprite;
}

void Block::draw(sf::RenderWindow& window, bool touch){
    movement(1);
    sprite.setPosition(location_x, location_y);
    if (touch){
    texture.loadFromFile("Resources/Images/coin.png");
    }

    sprite.setTexture(texture);

    // Define the texture rectangle based on the state of the object
    sf::IntRect textureRect;
  
    textureRect = sf::IntRect(0, 0, Block_size,Block_size);
    
    sprite.setTextureRect(textureRect);

    window.draw(sprite);


}
    
