#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Button.h"
//#include "/Users/tomerantebi/Documents/rpgGame/game/src/Entity.h"

class State
{
protected:
    sf::RenderWindow* s_window;                    // Render window pointer
    std::unique_ptr<sf::Font> font;                 // Use smart pointer for automatic memory management

    std::map<std::string, std::unique_ptr<Button>> buttons;  // Use unique pointer for buttons map
    std::map<std::string,int>* s_supportedKeys;     // Mapping of supported keys
    std::map<std::string,int> s_keyBindes;          // Mapping of key bindings
    bool quit;                                     // Quit flag

    std::stack<std::unique_ptr<State>>* states;     // Smart pointer for state stack

    sf::Vector2i mousePosScreen;                    // Mouse position in screen coordinates
    sf::Vector2i mousePosWindow;                    // Mouse position in window coordinates
    sf::Vector2f mousePosCamera;                    // Mouse position in camera coordinates

    std::map<std::string, std::unique_ptr<sf::Texture>> textures;  // Use unique pointer for textures map

    // Virtual functions to be implemented by derived classes
    virtual void initVariables() = 0;
    virtual void initKeyBindes() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys, std::stack<std::unique_ptr<State>>* state);
    virtual ~State();                             // Virtual destructor for proper cleanup in derived classes

    virtual void checkForQuit();                  // Checks if the game should quit
    virtual void updateMousePositions();          // Updates mouse position

    const bool& getQuit();                        // Returns the quit flag

    // Virtual update and draw functions to be implemented by derived classes
    virtual void updateKeyBindes(const float& deltaTime) = 0;
    virtual void updateState(const float& deltaTime) = 0;
    virtual void drawState(sf::RenderTarget* target = nullptr) = 0;

    virtual void endState();                      // Ends the current state
};
