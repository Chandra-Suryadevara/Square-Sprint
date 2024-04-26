#include "../Headers/Square_Main.hpp"
#include "../Headers/Global.hpp"
#include <SFML/Graphics.hpp>

Square_Main::Square_Main(){

reset();


}


void Square_Main::reset(){

dead = true;
speed = 2;
score=0;
x = Square_start;

}


void Square_Main::draw(sf::RenderWindow& i_window)
{
    sf::Sprite sprite;
    sf::Texture texture;
    if (dead){
        texture.loadFromFile("Resources/Images/End_Face.png");
    } else {
        texture.loadFromFile("Resources/Images/Normal_face.png");
    }

    sprite.setPosition(x, y);
    sprite.setTexture(texture);

    // Define the texture rectangle based on the state of the object
    sf::IntRect textureRect;
    if (dead) {
        textureRect = sf::IntRect(0, 0, Square_size, Square_size);
    } else {
        textureRect = sf::IntRect(0, 0, Square_size, Square_size);
    }
    sprite.setTextureRect(textureRect);

    i_window.draw(sprite);
}




bool Square_Main::is_dead(){
    return dead;
}



Square_Main::~Square_Main(){

}