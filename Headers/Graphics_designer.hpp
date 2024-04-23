#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Graphics_designer
{
private:
    sf::Event event;
    sf::Sprite background_sprite;
    sf::Texture background_texture;
    
    sf::RenderWindow window;
public:
    Graphics_designer();
    void Create_event();
    sf::Event* get_event();
    sf::RenderWindow* get_window();
    sf::Sprite* get_Sprite();
    sf::Texture* get_BG_Texture();
    void DrawBG();
    void Create_BG();
    ~Graphics_designer();
};

