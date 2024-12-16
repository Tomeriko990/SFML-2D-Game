#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <stack>
#include "States/Main_menu_state.h"

// Game_Engine class is responsible for the overall game logic,
// including window management, event handling, and managing different states of the game.
class Game_Engine
{
private:
    // Window
    sf::RenderWindow* window;           // SFML window object
    sf::Vector2u windowSize;            // Window dimensions
    sf::Event sfEvent;                  // SFML event object to handle events
    sf::ContextSettings settings;       // Settings for the OpenGL context of the window

    // Delta time
    sf::Clock clock;                    // Clock to track time for the frame rate
    float deltaTime;                    // The time that has passed since the last frame

    // Supported keys (e.g., keyboard inputs)
    std::map<std::string, int> supportedKeys;

    // States stack (for game state management)
    std::stack<State*> states;          // Stack for storing the current game state(s)
    
public:
    // Constructor
    Game_Engine();

    // Initialization functions
    void initWindow();                  // Initializes the SFML window
    void initKeys();                    // Initializes supported keys for handling user input
    void initStates();                  // Initializes the initial game state(s)

    // Update functions (called every frame)
    void updateDeltaTime();             // Updates delta time to manage frame rate
    void updateSFMLEvents();            // Updates events like keyboard, mouse, window events
    void update();                      // Main update function to update game logic

    // Draw functions (called every frame)
    void draw();                        // Draws objects on the window

    // Main game loop
    void run();                         // Starts and runs the game loop

    // Destructor
    virtual ~Game_Engine();             // Destructor to clean up resources (like window)
};








