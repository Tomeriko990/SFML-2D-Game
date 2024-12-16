#include "HitboxComponent.h"

// Constructor: Initializes the hitbox based on the sprite's position, scale, and given dimensions
HitboxComponent::HitboxComponent(sf::Sprite &Sprite, float offset_x, float offset_y, float Width, float Height)
    : sprite(Sprite), offsetX(offset_x), offsetY(offset_y), width(Width), height(Height)
{
    // Set the initial position of the hitbox using the sprite's position and the provided offsets
    this->hitBox.setPosition(this->sprite.getPosition().x - offsetX, this->sprite.getPosition().y - offsetY);
    
    // Set the size of the hitbox
    this->hitBox.setSize(sf::Vector2f(width, height));
    
    // Make the hitbox transparent, with a green outline for debugging purposes
    this->hitBox.setFillColor(sf::Color::Transparent);
    this->hitBox.setOutlineThickness(1.f);
    this->hitBox.setOutlineColor(sf::Color::Green);
}

// Destructor (no special handling needed for this case)
HitboxComponent::~HitboxComponent()
{
}

// Checks if the hitbox intersects with another given rectangle (for collision detection)
const bool& HitboxComponent::isIntersect(const sf::FloatRect &frect)
{
    return this->hitBox.getGlobalBounds().intersects(frect); // Return the result directly
}

// Updates the position of the hitbox based on the sprite's position
void HitboxComponent::update()
{
    // Update the position of the hitbox, applying the offsets
    this->hitBox.setPosition(this->sprite.getPosition().x - offsetX, this->sprite.getPosition().y - offsetY);
}

// Draws the hitbox for debugging purposes (can be removed in the final game)
void HitboxComponent::draw(sf::RenderTarget *target)
{
    target->draw(this->hitBox);
}





