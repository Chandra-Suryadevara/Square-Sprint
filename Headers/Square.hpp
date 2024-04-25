#pragma once 

#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Square_Main {
private:
        int speed;
        bool dead;
        int score;
        const int y;
        float x;
public:
        Sqaure_Main();
        void reset();
        bool is_dead();
        ~Sqaure_Main();
        void draw(sf::RenderWindow& i_window);

        

}