#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include "../Headers/Graphics_designer.hpp"
#include "../Headers/Square.hpp"
#include <SFML/Graphics.hpp>

int main() {
    Graphics_designer Model;
    Square main_char;
    
    Model.run();
    main_char.draw(Model.get_windows());

    return 0;
}
