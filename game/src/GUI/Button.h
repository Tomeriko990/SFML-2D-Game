#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Button
{

private:

    enum buttonStates{BTN_IDLE=0,BTN_HOVER,BTN_ACTIVE};
    short unsigned buttonState;


    sf::RectangleShape shape;
    sf::Font* font;

    sf::Text text;
    sf::Color textIdleColor;
    sf::Color textHoverColor;
    sf::Color textActiveColor;


    sf::Color IdleColor;
    sf::Color HoverColor;
    sf::Color ActiveColor;

    std::map<std::string,sf::Vector2f> button_states;


public:

    Button(sf::Vector2f& PosButton,sf::Vector2f& SizeButton,sf::Font* font,
    std::string text,
    sf::Color text_idle_Color,sf::Color text_hover_Color,sf::Color text_active_Color,
    sf::Color idle_Color,sf::Color hover_Color,sf::Color active_Color);

    const bool isPressed()const;
    void updateButton(const sf::Vector2f mousePos);
    void drawButton(sf::RenderTarget* target=nullptr);

    ~Button();
};


