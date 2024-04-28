#include "../Headers/Graphics_designer.hpp"
#include "../Headers/Global.hpp"
#include "../Headers/Square_Main.hpp"
#include "../Headers/Spikes.hpp"
#include "../Headers/Audio_game.hpp"
#include "../Headers/SpikesManager.hpp"
#include "../Headers/Menu.hpp"
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
    Menu Bar;
    bool menuopen= false;
    bool jump = false;
    std::string chossen;
    bool dead= false;
    std::vector<Text_handler> textobjs=Bar.get_objs();
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
             if (event.key.code == sf::Keyboard::Space) {
                jump = true;
             }else if (event.key.code == sf::Keyboard::M) {
                game_audio.change_audio();
             }
             else if (event.key.code == sf::Keyboard::Up) {
                jump = true;
             }
             else if (event.key.code == sf::Keyboard::Escape) {
                menuopen = !menuopen;
             }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            
                if (event.mouseButton.button == sf::Mouse::Left) {
                    
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    
                    if(menuopen || dead){
                        //check this fucntioon not working as intended 

                    textobjs=Bar.get_objs();
                    for (int i=0;i<textobjs.size();i++){

                        if (textobjs[i].get_text().getGlobalBounds().contains(mousePos.x,mousePos.y)) {
                            
                            chossen= textobjs[i].get_set_text();

                        }}
                    }
                    if (game_audio.get_sprite().getGlobalBounds().contains(mousePos.x,mousePos.y)) {
                        
                        game_audio.change_audio();

                    }}
        }
        
        }
    
        
        std::vector<Spikes> sprite_vector = Manager.get_spikes();
         
        for (int i=0;i<sprite_vector.size();i++){
            if (main_char.get_sprite().getGlobalBounds().intersects(sprite_vector[i].get_sprite().getGlobalBounds())) {
            
            dead = true;
            main_char.set_dead(dead);
            }
        }
        
        sf::Sprite background_sprite(background_texture);
        DrawBG(background_sprite);
        main_char.draw(window,jump);
        game_audio.draw(window);
        if (menuopen||dead){
            menuopen=true;
            Bar.draw(window,event,dead);
        }
        if (chossen !="NULL"){
            if (chossen=="Resume"){
                menuopen = false;   

            }else if (chossen == "Restart"){
                
                main_char.reset();
                Manager.restart();
                menuopen = false;
                dead =false;
            }else if(chossen=="Mute" ){
                game_audio.mute_music();
            
            }else if(chossen=="Unmute" ){
                game_audio.unmute();
            
            }else if (chossen=="Exit"){
                Manager.restart();
                window.close();
            }
        }

        main_char.set_score(Manager.draw(window,menuopen));
        window.display();
        jump = false;
        chossen="NULL";
    
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

