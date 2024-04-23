#include "../Headers/Graphics_designer.hpp"
#include "../Headers/Global.hpp"


Graphics_designer::Graphics_designer()
{
}

void Graphics_designer::Create_event(){

sf::RenderWindow window(sf::VideoMode(800,800), "Geometry Dash");
window.setView(sf::View(sf::FloatRect(0, 0, 2 * SCREEN_WIDTH, SCREEN_HEIGHT)));

}


void Graphics_designer::Create_BG(){
    background_texture.loadFromFile("Resources/BG.png");

}

void Graphics_designer::DrawBG(){
    window.clear();
    window.draw(background_sprite);
}

sf::Event* Graphics_designer::get_event(){
    return &event;
}

sf::Sprite* Graphics_designer::get_Sprite(){
    return &background_sprite;
}
sf::RenderWindow* Graphics_designer::get_window(){
    return &window;
}
sf::Texture* Graphics_designer::get_BG_Texture(){
    return &background_texture;
}

Graphics_designer::~Graphics_designer()
{
}
