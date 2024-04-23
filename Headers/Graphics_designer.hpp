#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Graphics_designer {
public:
    Graphics_designer();
    ~Graphics_designer();

    void Create_BG();
    void run();
    void DrawBG(const sf::Sprite& background_sprite);
    sf::Event* get_event();
    sf::RenderWindow* get_window();
    sf::Texture* get_BG_Texture();

private:
    sf::RenderWindow window;
    sf::Texture background_texture;
    sf::Event event;
};
