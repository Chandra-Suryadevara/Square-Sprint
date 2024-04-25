#include "Square.hpp"
#include "Global.hpp"


Square::Square(){

reset();


}


void Square:reset(){

dead = false;
speed = 1;
score=0;


}

void Square::draw(sf::RenderWindow& i_window)
{
	sf::Sprite sprite;

	sf::Texture texture;
	texture.loadFromFile("Resources/Images/Normal_face.png");

	sprite.setPosition(x, round(y));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(Square_size * (0 >= speed), Square_size * dead, Square_size, Square_size));

	i_window.draw(sprite);
}

bool Square::is_dead(){
    return dead;
}