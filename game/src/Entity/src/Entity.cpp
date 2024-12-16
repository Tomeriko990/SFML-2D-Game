#include "Entity.h"

// Constructor: Initializes components and sets default values for Health and Fire Rate
Entity::Entity()
    : hitboxComponent(nullptr), moveMentComponent(nullptr),
      HealthPoint(100.f), firerRate(120.f) 
{
    // Initialize any other necessary variables or components here
}

// Method to create and set the entity's sprite
void Entity::setSprite()
{
    this->sprite = new sf::Sprite();  // Dynamically allocate a new sprite object
    // Optionally, you can set a texture here for the sprite, e.g.:
    // this->sprite->setTexture(*this->textures[key]);
}

// Method to set the position of the entity's sprite
void Entity::setPosition(const sf::Vector2f& position)
{
    if (this->sprite)
    {
        this->sprite->setPosition(position.x, position.y);  // Set the sprite's position
    }
}

// Method to create a HitboxComponent for the entity, used for collision detection
void Entity::createHitboxComponent(float offset_x, float offset_y, float Width, float Height)
{
    this->hitboxComponent = new HitboxComponent(*this->sprite, offset_x, offset_y, Width, Height);  // Create the hitbox component based on the sprite's position
}

// Method to create a MovementComponent for the entity, used for handling movement
void Entity::createMoveMentComponent(const float& maxVelocity, const float& acceleration, const float& deceleration)
{
    this->moveMentComponent = new MovementComponent(*this->sprite, maxVelocity, acceleration, deceleration);  // Create the movement component for the entity
}

// Method to create an AnimationComponent for the entity (currently commented out)
void Entity::createAnimationComponent(std::string key)
{
    // This can be used to initialize an animation component (e.g., setting animations based on key)
    // Example:
    // this->animationComponent = new AnimationComponent(*this->textures[key], *this->sprite);
}

// Method to move the entity based on input directions (x and y) and deltaTime
void Entity::move(const float& deltaTime, const float& dir_x, const float& dir_y)
{
    if (this->sprite && this->moveMentComponent)
    {
        this->moveMentComponent->move(deltaTime, dir_x, dir_y);  // Pass the movement data to the MovementComponent for updating the entity's position
    }
}

// Method to draw the entity and its components to the specified render target (e.g., the window)
void Entity::drawEntity(sf::RenderTarget* target)
{
    if (this->sprite)
    {
        target->draw(*this->sprite);  // Draw the sprite to the target
    }
    if (this->hitboxComponent)
    {
        this->hitboxComponent->draw(target);  // Optionally, draw the hitbox for debugging purposes
    }
}

// Destructor: Properly deallocates memory used by the entity's components
Entity::~Entity()
{
    delete this->sprite;  // Delete the sprite object
    delete this->hitboxComponent;  // Delete the hitbox component
    delete this->moveMentComponent;  // Delete the movement component
    for (auto& i : this->AnimationsC)  // Loop through and delete all animation components
    {
        delete i.second;
    }
    // Optionally, delete the animation component if it's used (currently commented out):
    // delete this->animationComponent;
}
