#pragma once
#include <SFML/Graphics.hpp>

// Enum to represent movement states (Idle, Up, Left, Down, Right)
enum movementStates { IDLE = 0, UP, LEFT, DOWN, RIGHT };

class MovementComponent
{
protected:
    sf::Sprite& sprite;  // The sprite this component will control

    float maxVelocity;    // Maximum velocity the sprite can move at
    float acceleration;   // Acceleration factor for sprite movement
    float deceleration;   // Deceleration factor to slow down the sprite

    sf::Vector2f velocity; // Current velocity of the sprite (X, Y)
   
public:
    // Constructor: Initializes the movement component with values for max velocity, acceleration, and deceleration
    MovementComponent(sf::Sprite& Sprite, float MaxVelocity, float Acceleration, float Deceleration);

    // Getter for velocity
    const sf::Vector2f& getVelocity() const;

    // Getter for max velocity
    const float& getMaxVelocity() const;

    // Check the current movement state (e.g., IDLE, UP, DOWN)
    const bool getMovementState(const short unsigned state) const;

    // Move the sprite based on the direction and deltaTime
    virtual void move(const float& deltaTime, const float& dir_x, const float& dir_y);

    // Update the movement logic (e.g., apply acceleration/deceleration)
    virtual void update(const float& deltaTime);

    // Destructor
    virtual ~MovementComponent();
};






