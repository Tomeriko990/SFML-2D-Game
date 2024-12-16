#include<iostream>
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Game_Engine.h"

// Entry point of the program
int main() 
{
    // Create an instance of the game engine
    Game_Engine game;

    // Run the game engine (the game will start here)
    game.run();

    return 0;   // Successful program exit
}

