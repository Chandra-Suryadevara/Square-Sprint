#include "Square_Main.hpp"
#include "Global.hpp"
#include <SFML/Graphics.hpp>

Square_Main::Square_Main(){

reset();


}


void Square_Main:reset(){

dead = false;
speed = 1;
score=0;
x = Square_start;
y=136;

}

void Square_Main::draw(sf::RenderWindow& i_window)
{
	sf::Sprite sprite;

	sf::Texture texture;
	texture.loadFromFile("Resources/Images/Normal_face.png");

	sprite.setPosition(x, round(y));
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(Square_size * (0 >= speed), Square_size * dead, Square_size, Square_size));

	i_window.draw(sprite);
}

bool Square_Main::is_dead(){
    return dead;
}