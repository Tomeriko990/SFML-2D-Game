#include "Game_Engine.h"
#include <fstream>

// Constructor initializes the window, keys, and states
Game_Engine::Game_Engine()
{
    this->initWindow();    // Initialize the window
    this->initKeys();      // Initialize the supported keys from the configuration file
    this->initStates();    // Initialize the game states (e.g., main menu)
}

// Initializes the window with default settings
void Game_Engine::initWindow()
{
    this->windowSize.x = 1122;   // Set window width
    this->windowSize.y = 800;    // Set window height

    this->settings.antialiasingLevel = 8;  // Set antialiasing level to 8 for smoother graphics
    this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "RPG Game", sf::Style::Default, settings);
    this->window->setFramerateLimit(120);  // Limit the frame rate to 120 FPS
}

// Initializes the supported keys from the configuration file
void Game_Engine::initKeys()
{
    std::ifstream file("/Users/tomerantebi/Documents/rpgGame/config/supported_keys.txt");

    // Read the keys and their associated integer values from the file
    if (file.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (file >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;   // Store the key and its value in the map
        }
    }
    file.close();  // Close the file after reading
}

// Initializes the game states, e.g., starting with the main menu
void Game_Engine::initStates()
{
    this->states.push(new Main_menu_state(this->window, &this->supportedKeys, &this->states));
}

// Updates the delta time (time passed since last frame)
void Game
