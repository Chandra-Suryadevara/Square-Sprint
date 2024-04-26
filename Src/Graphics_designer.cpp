#include "../Headers/Graphics_designer.hpp"
#include "../Headers/Global.hpp"
#include "../Headers/Square_Main.hpp"
#include <iostream>

Graphics_designer::Graphics_designer() : window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Geometry Dash") {
    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
}

void Graphics_designer::Create_BG() {
    background_texture.loadFromFile("Resources/Images/BG.png");
}

void Graphics_designer::run() {
    Create_BG();
    Square_Main main_char;  

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Sprite background_sprite(background_texture);
        DrawBG(background_sprite);
        main_char.draw(window);
        
        window.display();
    }
}

void Graphics_designer::DrawBG(const sf::Sprite& background_sprite) {
    window.clear();
    window.draw(background_sprite);
}

sf::Event* Graphics_designer::get_event() {
    return &event;
}

sf::RenderWindow* Graphics_designer::get_window() {
    return &window;
}

sf::Texture* Graphics_designer::get_BG_Texture() {
    return &background_texture;
}

Graphics_designer::~Graphics_designer() {}

