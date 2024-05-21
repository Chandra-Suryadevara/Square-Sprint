#pragma once 
#include <SFML/Graphics.hpp>
#include "Spikes.hpp"
#include "Global.hpp"


class SpikesManager{


    private:
        std::vector<Spikes> Obuj_spikes;
        float speed;
        sf::Vector2i lastelementpostion;
        int score;
        int count =0;
    public:
        SpikesManager();
        int draw(sf::RenderWindow& Window, bool& lock);
        int generaterandomnum(int limit1, int limit2);
        void createOBJS();
        void set_score(int score1);
        void restart();
        std::vector<Spikes>& get_spikes(); 
        


};