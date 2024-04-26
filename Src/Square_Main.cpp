#include "../Headers/Square_Main.hpp"
#include "../Headers/Global.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Square_Main::Square_Main(){

reset();


}


void Square_Main::reset(){

dead = false;
score=0;
y=intial_y;
x = Square_start;

}

void Square_Main::intial_movement(float temp_speed){

    
    if (x > 800){
       
    }else{
        x = x + temp_speed;
    }

}

void Square_Main::load_image(){
if (dead){
        texture.loadFromFile("Resources/Images/End_Face.png");
    } else {
        texture.loadFromFile("Resources/Images/Normal_face.png");
    }

}

void Square_Main::jump(){
if (reach == false){

if (y > 900){
    y = y-2.2;
}else if (y <= 900){
    reach = true;
}
} else{
    if (y!=intial_y){
        
        y = y+2.2;
        if (y > 1620){
            y = 1620;
        }
    }else{
        std::cout<<"here";
        is_jumping = false;
        reach = false;
    }
}

}
void Square_Main::draw(sf::RenderWindow& i_window,bool pressed)
{
    sf::Sprite sprite;
    load_image();
    intial_movement(2);
    sprite.setPosition(x, y);
    sprite.setTexture(texture);

    // Define the texture rectangle based on the state of the object
    sf::IntRect textureRect;
  
    textureRect = sf::IntRect(0, 0, Square_size, Square_size);
    
    sprite.setTextureRect(textureRect);


    if (pressed == true && is_jumping == false){
        is_jumping =true;
    }

    if(is_jumping){
        jump();
    }

    i_window.draw(sprite);
    sprite_local = sprite;
}

sf::Sprite& Square_Main::get_sprite(){
    return sprite_local;
}


bool Square_Main::is_dead(){
    return dead;
}



Square_Main::~Square_Main(){

}