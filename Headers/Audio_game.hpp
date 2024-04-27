#pragma once 
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Audio_game {

    private:
    
        sf::Texture texture;
        sf::Sprite sprite_local;
        sf::Music Game_music;
        float x;
        float y;
        bool mute =false;
    public:
        Audio_game();
        void load_icons();
        void load_song();
        void draw(sf::RenderWindow& window);
        sf::Sprite& get_sprite();

        void change_audio();
 


};