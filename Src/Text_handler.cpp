#include "../Headers/Text_handler.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>



Text_handler::Text_handler(){

}


void Text_handler::set_color(){

text.setFillColor(sf::Color::White);

}

void Text_handler::load_font(){
    font.loadFromFile("Resources/Font/font.otf");
    text.setFont(font);
}

void Text_handler::set_size(int size){
    text.setCharacterSize(size);
}

void Text_handler::set_string(std::string textwanted){
set_text=textwanted;
text.setString(textwanted);
}

void Text_handler::draw(sf::RenderWindow& window,float x,float y ,int size){

load_font();
set_size(size);
text.setPosition(x, y);
set_color();
window.draw(text);
}

sf::Text& Text_handler::get_text(){
    return text;
}

std::string Text_handler::get_set_text(){
    return set_text;
}

