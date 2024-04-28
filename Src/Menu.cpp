#include "../Headers/Menu.hpp"
#include <iostream>
#include "../Headers/Global.hpp"
#include "../Headers/Text_handler.hpp"

Menu::Menu(){

x=600;
y=100;


}





void Menu::Create_text_objs(){
if (textobjs.size() == 0){
for (int i=0;i<options.size();i++){
    if (i ==0){
           Text_handler T1;
   T1.set_string(options[i]);
    textobjs.push_back(T1);
        }else if(i == 1){
            Text_handler T2;
               T2.set_string(options[i]);
    textobjs.push_back(T2);
        }else if (i==2){ 
            Text_handler T3;
              T3.set_string(options[i]);
    textobjs.push_back(T3);
        }else{
            Text_handler T4;
    T4.set_string(options[i]);
    textobjs.push_back(T4);
}
}
}
}

std::vector<Text_handler> Menu::get_objs(){
    return textobjs;
}

void Menu::load_main(){

    texture.loadFromFile("Resources/Images/Menu.png");
}

void Menu::preprocess(){
    load_main();
    sprite.setTexture(texture);

    sprite.setPosition(x, y);

    sf::IntRect textureRect(0, 0, 600, 600);
    sprite.setTextureRect(textureRect);
    Create_text_objs();
    
    
}

void Menu::draw(sf::RenderWindow& window, sf::Event& event) {

    if (!is_done){
        preprocess();
        is_done =true;
        
    }
    
    window.draw(sprite);
    for (int i=0;i<textobjs.size();i++){
        textobjs[i].draw(window,750,200+75*i);
    }

   }

