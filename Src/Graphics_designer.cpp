#include "../Headers/Graphics_designer.hpp"
#include "../Headers/Global.hpp"
#include "../Headers/Square_Main.hpp"
#include "../Headers/Spikes.hpp"
#include "../Headers/Audio_game.hpp"
#include "../Headers/SpikesManager.hpp"
#include <iostream>

Graphics_designer::Graphics_designer() : window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Geometry Dash") {
    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
}

void Graphics_designer::Create_BG() {
    background_texture.loadFromFile("Resources/Images/BG.png");
}

void Graphics_designer::run() {
    Create_BG();
    Audio_game game_audio;
    Square_Main main_char;
    SpikesManager Manager;
    bool jump = false;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
             if (event.key.code == sf::Keyboard::Space) {
                jump = true;
             }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            
                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    std::cout << "Sprite Position: (" << mousePos.x << ", " << mousePos.y << ")" << std::endl;

                    if (game_audio.get_sprite().getGlobalBounds().contains(mousePos.x,mousePos.y)) {
                        
                        game_audio.change_audio();

                    }}
        }
        
        }
        std::vector<Spikes> sprite_vector = Manager.get_spikes();
        for (int i=0;i<sprite_vector.size();i++){
            if (main_char.get_sprite().getGlobalBounds().intersects(sprite_vector[i].get_sprite().getGlobalBounds())) {
            
            window.close();
            }
        }
        sf::Sprite background_sprite(background_texture);
        DrawBG(background_sprite);
        main_char.draw(window,jump);
        game_audio.draw(window);
        Manager.draw(window);
        jump = false;
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

