#include "../Headers/Square_Main.hpp"
#include "../Headers/Global.hpp"
#include "../Headers/Text_handler.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Square_Main::Square_Main(){

reset();


}

void Square_Main::set_dead(bool x){
    dead = x;
}

void Square_Main::reset(){

dead = false;
score=0;
jump_value=0.8;
y=intial_y;
x = Square_start;
    highscore = H.getHighScore();
    if(highscore==-1){
        highscore=0;
    }

}

void Square_Main::intial_movement(float temp_speed){

    if (x > 400){
       
    }else{
        
        x = x + temp_speed;
    }

}

void Square_Main::load_image(){
if (dead){
        texture.loadFromFile("Resources/Images/end_face.png");
    } else if (is_jumping){
        texture.loadFromFile("Resources/Images/jumping.png");
    } else{
        texture.loadFromFile("Resources/Images/main_face.png");
    }

}

void Square_Main::set_score(int scoremain){
    score = scoremain;
}

void Square_Main::jump(float speed){

if (reach == false){

if (y > 400){
    y = y-speed;
}else if (y <= 400){
    reach = true;
}
} else{
    if (y!=intial_y){
        
        y = y+speed*1.02;
        if (y > 755){
            y = 755;
        }
    }else{
        is_jumping = false;
        reach = false;
    }
}

}
void Square_Main::draw(sf::RenderWindow& i_window,bool pressed)
{

    load_image();
    intial_movement(1);
    sprite.setPosition(x, y);
    sprite.setTexture(texture);

    // Define the texture rectangle based on the state of the object
    sf::IntRect textureRect;
  
    textureRect = sf::IntRect(0, 0, Square_size, Square_size);
    
    sprite.setTextureRect(textureRect);


    if (pressed == true && is_jumping == false){
        is_jumping =true;
        load_image();
        sprite.setTexture(texture);

    }
    
    if (score !=0){
    if (score%10==0&& count ==0){
        jump_value = jump_value + 0.1;
        count++;
    }else if(score%8==0 && score%10!=0 && count !=0){
        count =0;
    }
    }
    if(is_jumping){
        jump(jump_value);
    }
    
    Scoretext.set_string("Score: ");

    Highscore.set_string("High Score: ");
    Scorenum.set_string(std::to_string(score));
    Highscorenum.set_string(std::to_string(highscore));
    Highscore.draw(i_window,1450,0);
    Highscorenum.draw(i_window,1700,0);
    Scoretext.draw(i_window,10,0);
    Scorenum.draw(i_window,150,0);
    i_window.draw(sprite);
    
}


sf::Sprite& Square_Main::get_sprite(){
    return sprite;
}


bool Square_Main::is_dead(){
    return dead;
}



Square_Main::~Square_Main(){

}