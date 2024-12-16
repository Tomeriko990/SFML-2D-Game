#pragma once
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/MovementComponent.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/AnimationComponent.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/HitboxComponent.h"

class Entity
{
private:
    // Containers for textures and animations
    std::map<std::string, sf::Texture*> textures;  // Store textures by key (e.g., "idle", "walk")
    std::map<std::string, AnimationComponent*> AnimationsC;  // Store animation components by key (e.g., "idle", "attack")

    // Components for entity behavior
    sf::Sprite* sprite;  // Pointer to the entity's sprite for rendering
    HitboxComponent* hitboxComponent;  // Pointer to the entity's hitbox component for collision detection
    MovementComponent* moveMentComponent;  // Pointer to the movement component to control movement and velocity

    // Entity stats
    float HealthPoint;  // Entity's current health
    float firerRate;  // Rate of fire (if relevant for this entity)

    // Pure virtual functions to be implemented in derived classes
    virtual void initVariables() = 0;  // Initializes entity variables
    virtual void initTextures(std::map<std::string, sf::Texture*>* Textures) = 0;  // Initializes textures from a map

public:
    // Constructor and Destructor
    Entity();  // Constructor to initialize the entity
    virtual ~Entity();  // Virtual destructor for proper cleanup of derived classes

    // Methods for setting up the entity
    virtual void setSprite();  // Sets the sprite for the entity
    virtual void setPosition(const sf::Vector2f& position);  // Sets the entity's position on screen

    // Methods for creating components
    virtual void createHitboxComponent(float offset_x, float offset_y, float Width, float Height);  // Create hitbox component
    virtual void createMoveMentComponent(const float& maxVelocity, const float& acceleration, const float& deceleration);  // Create movement component
    virtual void createAnimationComponent(std::string key);  // Create animation component for the entity (e.g., for idle, walking, etc.)

    // Movement-related method
    virtual void move(const float& deltaTime, const float& dir_x, const float& dir_y);  // Moves the entity based on input direction and time delta

    // Update and draw methods
    virtual void update(const float& deltaTime) = 0;  // Pure virtual method to update entity's state (e.g., movement, animation)
    virtual void drawEntity(sf::RenderTarget* target = nullptr);  // Draw the entity to a target (default to nullptr for default target)

};





