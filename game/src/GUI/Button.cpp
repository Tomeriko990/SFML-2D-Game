#include "Button.h"

Button::Button(sf::Vector2f& PosButton,sf::Vector2f& SizeButton,sf::Font* font,
    std::string text,
    sf::Color text_idle_Color,sf::Color text_hover_Color,sf::Color text_active_Color,
    sf::Color idle_Color,sf::Color hover_Color,sf::Color active_Color
)
:font(font),textIdleColor(text_idle_Color),textHoverColor(text_hover_Color),textActiveColor(text_active_Color),
IdleColor(idle_Color),HoverColor(hover_Color),ActiveColor(active_Color)

{

    this->buttonState=BTN_IDLE;

    this->shape.setPosition(PosButton);
    this->shape.setSize(SizeButton);

    this->text.setFont(*this->font);
    this->text.setFillColor(sf::Color::White);
    this->text.setString(text);
    this->text.setCharacterSize(50);

    this->text.setPosition(
        (this->shape.getPosition().x+this->shape.getGlobalBounds().width/2.f)-this->text.getGlobalBounds().width/2.f,
        (this->shape.getPosition().y+this->shape.getGlobalBounds().height/2.f)-this->text.getGlobalBounds().height/2.f
    );

    
    this->shape.setFillColor(this->IdleColor);
}

const bool Button::isPressed() const
{
    if(this->buttonState==BTN_ACTIVE)
    {
        return true;
    }
    return false;
}

void Button::updateButton(const sf::Vector2f mousePos)
{
    this->buttonState=BTN_IDLE;

    if(this->text.getGlobalBounds().contains(mousePos))
    {
       
        this->buttonState=BTN_HOVER;
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            this->buttonState=BTN_ACTIVE;
        }
    }

    switch (this->buttonState)
    {

    case BTN_IDLE:
        this->shape.setFillColor(this->IdleColor);
        this->text.setFillColor(this->textIdleColor);
        break;

    case BTN_HOVER:
        this->shape.setFillColor(this->HoverColor);
        this->text.setFillColor(this->textHoverColor);
        break;

    case BTN_ACTIVE:
        this->shape.setFillColor(this->ActiveColor);
        this->text.setFillColor(this->textActiveColor);
        break;        
    
    default:
        break;
    }
}

void Button::drawButton(sf::RenderTarget *target)
{
    target->draw(this->shape);
    target->draw(this->text);
}

Button::~Button()
{
}
