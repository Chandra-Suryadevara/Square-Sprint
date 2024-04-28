#include "../Headers/Audio_game.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>



Audio_game::Audio_game(){

load_song();
Game_music.play();
x = 1700;
y = 100;

}


void Audio_game::load_song(){

if(!Game_music.openFromFile("/home/tanjiro/Github/Geometry-Dash/Resources/Audio/Music.wav")){
    std::cout<<"cannot load song";

}
}

void Audio_game::load_icons(){

if (mute){
        texture.loadFromFile("Resources/Images/mute.png");
    } else {
        texture.loadFromFile("Resources/Images/unmute.png");
    }
}

void Audio_game::draw(sf::RenderWindow& window){
    sf::Sprite sprite;
    load_icons();
    sprite.setPosition(x, y);
    sprite.setTexture(texture);
    sf::IntRect textureRect;
    textureRect = sf::IntRect(0, 0, 100,100);
    sprite.setTextureRect(textureRect);
    window.draw(sprite);
    sprite_local = sprite;
}

void Audio_game::change_audio(){
    
    if (mute){
        Game_music.setVolume(50);
        mute = false;
    }else{
    Game_music.setVolume(0);
    mute = true;
    }

}

void Audio_game::mute_music(){

    Game_music.setVolume(0);
    mute = true;
}

void Audio_game::unmute(){
    Game_music.setVolume(50);
        mute = false;

}



sf::Sprite& Audio_game::get_sprite(){
    return sprite_local;
}