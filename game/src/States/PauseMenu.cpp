#include "PauseMenu.h"

/**
 * @class PauseMenu
 * @brief Represents the pause menu with a background and buttons for resuming or exiting the game.
 */
PauseMenu::PauseMenu(sf::RenderWindow &Window, sf::Font &Font, std::map<std::string, Button *> &Buttons)
:window(Window), font(Font), buttons(Buttons) {
    // Initialize background
    this->backGround.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)
        )
    );
    this->backGround.setFillColor(sf::Color(20, 20, 20, 100));

    // Initialize container
    this->container.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x) / 4.f,
            static_cast<float>(window.getSize().y)
        )
    );
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
    this->container.setPosition(
        sf::Vector2f(
            static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
            0.f
        )
    );
}






















//end 

#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow &Window, sf::Font &Font, std::map<std::string, Button *> &Buttons)
:window(Window),font(Font),buttons(Buttons)
{
    this->backGround.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)
        )
    );
    this->backGround.setFillColor(sf::Color(20,20,20,100));

    this->container.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x)/4.f,
            static_cast<float>(window.getSize().y)
        )
    );
    this->container.setFillColor(sf::Color(20,20,20,200));
    this->container.setPosition(
        sf::Vector2f(
            static_cast<float>(window.getSize().x)/2.f-this->container.getSize().x/2.f,
            0.f
        )
    );
}