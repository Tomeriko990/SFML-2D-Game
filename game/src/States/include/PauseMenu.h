#pragma once
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Button.h"

class PauseMenu
{
private:
    
    sf::RenderWindow& window;
    sf::RectangleShape backGround;
    sf::RectangleShape container;
    
    sf::Font& font;
    sf::Text menuText;
    std::map<std::string,Button*>& buttons;

    void initBackGround();
    void initButtons();

public:
    PauseMenu(sf::RenderWindow& Window,sf::Font& Font,std::map<std::string,Button*>& Buttons);
    ~PauseMenu();

    void update(const float& deltaTime);
    void draw(sf::RenderTarget& target);
};

