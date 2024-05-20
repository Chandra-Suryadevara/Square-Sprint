#pragma once

#include <SFML/Graphics.hpp>
#include "HighScoreManager.hpp"
#include "Text_handler.hpp"
#include "Global.hpp"

class Square_Main {
private:
    bool dead;
    int score;
    const int intial_y = 755;
    float y;
    bool reach = false;
    float x;
    float jump_value;
    bool is_jumping =false;
    sf::Texture texture;
    sf::Sprite sprite;
    HighScoreManager H;
    Text_handler Scoretext;
    Text_handler Scorenum;
    Text_handler Highscore;
    Text_handler Highscorenum;
    int highscore;
    int count;
public:
    Square_Main(); // Corrected constructor name
    void reset();
    bool is_dead();
    int get_score();
    void load_image();
    void jump(float speed);
    void intial_movement(float temp_speed);
    sf::Sprite& get_sprite();
    void set_score(int scoremain);


    void set_dead(bool x);
    ~Square_Main(); // Corrected destructor name
    void draw(sf::RenderWindow& i_window,bool pressed);
    void draw_dead(sf::RenderWindow& window);
}; // Added semicolon at the end of the class definition
