#pragma once 

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Square{
    private:
        int speed;
        bool dead;
        int score;
        const int y;
        float x;



    public:
        Sqaure();
        void reset();
        bool is_dead();
        ~Sqaure();
        void draw(sf::RenderWindow& i_window);

        

}