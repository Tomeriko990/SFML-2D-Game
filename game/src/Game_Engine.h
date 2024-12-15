#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <stack>
#include "States/Main_menu_state.h"

class Game_Engine
{

private:

    //window 
    sf::RenderWindow* window;
    sf::Vector2u windowSize;
    sf::Event sfEvent;
    sf::ContextSettings settings;

    //delta time 
    sf::Clock clock;
    float deltaTime;

    std::map<std::string,int> supportedKeys;
    std::stack<State*> states;
    
    
public:

    Game_Engine();

    void initWindow();
    void initKeys();
    void initStates();

    void updateDeltaTime();
    void updateSFMLEvents();
    void update();

    void draw();
    void run();

    virtual ~Game_Engine();
};

