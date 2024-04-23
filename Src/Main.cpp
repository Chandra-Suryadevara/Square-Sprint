#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include "../Headers/Graphics_designer.hpp"
#include <SFML/Graphics.hpp>



int main(){
Graphics_designer Model;

Model.Create_event();
Model.Create_BG();
std::cout<<"Hello";
sf::Event* event = Model.get_event();
sf::RenderWindow* window = Model.get_window();


 while (window->isOpen())
    {
        
        while (window->pollEvent(*event))
        {
            // "close requested" event: we close the window
            if (event->type == sf::Event::Closed)
                window->close();
        }
        std::cout<<"Hello123";
        window->display();
		
    }

return 0;
}