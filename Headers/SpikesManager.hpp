#pragma once 
#include <SFML/Graphics.hpp>
#include "Spikes.hpp"
#include "Global.hpp"


class SpikesManager{


    private:
        std::vector<Spikes> Obuj_spikes;
        float speed;
        sf::Vector2i lastelementpostion;
    public:
        SpikesManager();
        void draw(sf::RenderWindow& Window);
        int generaterandomnum(int limit1, int limit2);
        void createOBJS();
        std::vector<Spikes>& get_spikes(); 
        


};