#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Text_handler.hpp"



class Menu{
private:    
     std::vector<std::string> options = {"Resume","Restart", "Controls", "Mute","Exit"};
    sf::Texture texture;
    std::vector<Text_handler> textobjs;
    sf:: Sprite sprite;
    bool is_done =false;
    float x;
    float y;


public:
    Menu();
    void draw(sf::RenderWindow& window, sf::Event& event);
    void load_main();
    void Create_text_objs();
    std::vector<Text_handler> get_objs();
    void preprocess();


};