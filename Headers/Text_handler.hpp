#pragma once

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Text_handler{

    private:
         sf::Font font;
         sf::Text text;
         std::string set_text;


    public:

        Text_handler();
        void load_font();
        void set_color();
        void set_string(std::string textwanted);
        void set_size(int size);
        void draw(sf::RenderWindow& window,float x,float y ,int size = 54);
        sf::Text& get_text();
        std::string get_set_text();





};