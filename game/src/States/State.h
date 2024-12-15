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

    sf::RenderWindow* s_window;
    sf::Font* font;
    
    std::map<std::string,Button*> buttons;
    std::map<std::string,int>* s_supportedKeys;
    std::map<std::string,int> s_keyBindes;
    bool quit;

    std::stack<State*>* states;


    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosCamera;

    std::map<std::string,sf::Texture*> textures;
    
//functions

    virtual void initVariables()=0;
    virtual void initKeyBindes()=0;

private:

    
public:

    State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* state);

    virtual ~State();

    virtual void checkForQuit();

    virtual void updateMousePositions();

    const bool& getQuit();

    virtual void updateKeyBindes(const float& deltaTime)=0;

    virtual void updateState(const float& deltaTime)=0;

    virtual void drawState(sf::RenderTarget* target=nullptr)=0;

    virtual void endState()=0;

};

