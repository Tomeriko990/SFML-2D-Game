#pragma once
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/old/ArrowStack.h"
#include "Entity.h"

// Player class inherits from Entity and represents a player in the game with actions like movement and shooting.
class Player : public Entity
{
private:
    // State flags to track the player's actions and conditions
    bool isAttacking;  // Flag indicating if the player is attacking
    bool shootingArrow;  // Flag indicating if the player is shooting an arrow
    bool isMoving;  // Flag indicating if the player is moving
    unsigned shootIndex;  // Index to manage arrow shooting

    // Quiver (arrow stack) for storing and managing arrows
    ArrowStack* quiver;

    // Private methods for initialization
    void initVariables();  // Initialize member variables
    void initTextures(std::map<std::string, sf::Texture*>* Textures);  // Load textures for the player
    void initComponents();  // Initialize components (e.g., movement, hitbox)

public:
    // Constructor: Initializes the player at a given position with a reference to a texture map
    Player(const sf::Vector2f& position, std::map<std::string, sf::Texture*>* Textures);

    // Destructor: Cleans up the resources used by the player
    ~Player();

    // Update function to handle player actions, movement, and logic
    void update(const float& deltaTime);  // Updates the player state (e.g., movement, shooting, etc.)

    // Shoot an arrow from the quiver, based on the direction and deltaTime
    void shoot(const float& deltaTime, sf::Vector2f& Direction);

    // Update the status of all arrows (e.g., movement, collision, etc.)
    void updateArrows(const float& deltaTime);

    // Draw arrows on the screen
    void drawArrows(sf::RenderTarget& target);

    // Inline getter for the player position
    inline const sf::Vector2f& getPosition() { return this->sprite->getPosition(); }

    // Inline getter for checking if the player is currently shooting
    inline const bool& isShooting() { return this->shootingArrow; }
};
