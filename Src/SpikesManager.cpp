#include "../Headers/SpikesManager.hpp"
#include "../Headers/Spikes.hpp"
#include "../Headers/HighScoreManager.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

SpikesManager::SpikesManager(){

restart();
}

int SpikesManager::generaterandomnum(int limit1, int limit2){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(limit1, limit2); 
    
    int randomNumber = dis(gen);
    return randomNumber;
}

void SpikesManager::createOBJS(){
for (int i=0;i<generaterandomnum(1,3);i++){
        if (i ==0){
            Spikes S1;
            Obuj_spikes.push_back(S1);

        }else if(i == 1){
            Spikes S2;
            S2.set_location(1900+100);
            Obuj_spikes.push_back(S2);

        }else{
            Spikes S3;
            S3.set_location(1900+200);
            Obuj_spikes.push_back(S3);
        }

    }
}

void SpikesManager::restart(){
    HighScoreManager H;
    H.saveHighScore(score);


    Obuj_spikes.clear();

score =0;
speed =0.9;

}

int SpikesManager::draw(sf::RenderWindow& window, bool& lock){
    
    if (score !=0){
    if (score%10==0&&count ==0){

        
        speed = speed + 0.1;

        count++;
    }else if(score%8==0 && score%10!=0 && count !=0){
        count =0;
    }
    }
    if (Obuj_spikes.size()!=0){
     lastelementpostion = sf::Vector2i(Obuj_spikes.back().get_sprite().getPosition());
    }
    if (Obuj_spikes.size()==0 || lastelementpostion.x<900){
    createOBJS();
    }
    for( int i=0; i<Obuj_spikes.size();i++){
        if (lock){
            Obuj_spikes[i].stop_movement();
        }else{
            Obuj_spikes[i].resume_movement();
        }
        std::string result = Obuj_spikes[i].draw(window,speed);
        if (result == "done"){
            Obuj_spikes.erase(Obuj_spikes.begin()+i);
            score++;
        }
    }
    return score;
 
}


std::vector<Spikes>& SpikesManager::get_spikes(){

    return Obuj_spikes;
}