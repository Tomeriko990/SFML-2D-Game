#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite &Sprite,float offset_x,float offset_y,float Width,float Height)
:sprite(Sprite),offsetX(offset_x),offsetY(offset_y),width(Width),height(Height)
{
    this->sprite.getScale();
    this->hitBox.setPosition(this->sprite.getPosition().x-offsetX,this->sprite.getPosition().y-offsetY);
    this->hitBox.setSize(sf::Vector2f(width,height));
    this->hitBox.setFillColor(sf::Color::Transparent);
    this->hitBox.setOutlineThickness(1.f);
    this->hitBox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{
}

const bool& HitboxComponent::isIntersect(const sf::FloatRect &frect)
{
    if(this->hitBox.getGlobalBounds().intersects(frect))
    {
        return true;
    }
    return false;
}

void HitboxComponent::update()
{
    this->hitBox.setPosition(this->sprite.getPosition().x,this->sprite.getPosition().y);
}

void HitboxComponent::draw(sf::RenderTarget *target)
{
    target->draw(this->hitBox);
}
