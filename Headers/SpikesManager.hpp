#pragma once 
#include <SFML/Graphics.hpp>
#include "./Spikes.hpp"
#include "Global.hpp"


class SpikesManager{


    private:
        std::vector<Spikes> OBJS;
        float speed;
    public:
        SpikesManager();
        void draw(sf::RenderWindow& Window);
        


};