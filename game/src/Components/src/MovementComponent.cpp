#include "MovementComponent.h"

// Constructor: Initializes the movement component with sprite and movement parameters
MovementComponent::MovementComponent(sf::Sprite& Sprite, float MaxVelocity, float Acceleration, float Deceleration)
    : sprite(Sprite), maxVelocity(MaxVelocity), acceleration(Acceleration), deceleration(Deceleration)
{
}

// Getter: Returns the current velocity of the sprite
const sf::Vector2f& MovementComponent::getVelocity() const
{
    return this->velocity;
}

// Getter: Returns the maximum velocity the sprite can move at
const float& MovementComponent::getMaxVelocity() const
{
    return this->maxVelocity;
}

// Checks the current movement state based on velocity
const bool MovementComponent::getMovementState(const short unsigned state) const
{
    switch (state)
    {
    case IDLE:
        // The sprite is idle if both X and Y velocity are zero
        if (this->velocity.x == 0.f && this->velocity.y == 0.f) { return true; }
        break;

    case UP:
        // The sprite is moving up if the Y velocity is negative
        if (this->velocity.y < 0.f) { return true; }
        break;

    case LEFT:
        // The sprite is moving left if the X velocity is negative
        if (this->velocity.x < 0.f) { return true; }
        break;

    case DOWN:
        // The sprite is moving down if the Y velocity is positive
        if (this->velocity.y > 0.f) { return true; }
        break;

    case RIGHT:
        // The sprite is moving right if the X velocity is positive
        if (this->velocity.x > 0.f) { return true; }
        break;
    }
    return false;
}

// Moves the sprite based on the input directions (X and Y) and deltaTime
void MovementComponent::move(const float& deltaTime, const float& dir_x, const float& dir_y)
{
    // Accelerating the sprite's velocity in both X and Y directions based on input
    this->velocity.x += this->acceleration * dir_x * deltaTime;
    this->velocity.y += this->acceleration * dir_y * deltaTime;

    // Clamping velocity to ensure it doesn't exceed the maximum allowed velocity
    if (this->velocity.x > maxVelocity) { this->velocity.x = maxVelocity; }
    else if (this->velocity.x < -maxVelocity) { this->velocity.x = -maxVelocity; }

    if (this->velocity.y > maxVelocity) { this->velocity.y = maxVelocity; }
    else if (this->velocity.y < -maxVelocity) { this->velocity.y = -maxVelocity; }
}

// Updates the sprite's velocity, applying deceleration and updating its position
void MovementComponent::update(const float& deltaTime)
{
    // Apply deceleration to X velocity, gradually slowing down the sprite
    if (this->velocity.x > 0.f)
    {
        this->velocity.x -= this->deceleration * deltaTime;
        if (this->velocity.x < 0.f) { this->velocity.x = 0.f; }
    }
    else if (this->velocity.x < 0.f)
    {
        this->velocity.x += this->deceleration * deltaTime;
        if (this->velocity.x > 0.f) { this->velocity.x = 0.f; }
    }

    // Apply deceleration to Y velocity, gradually slowing down the sprite
    if (this->velocity.y > 0.f)
    {
        this->velocity.y -= this->deceleration * deltaTime;
        if (this->velocity.y < 0.f) { this->velocity.y = 0.f; }
    }
    else if (this->velocity.y < 0.f)
    {
        this->velocity.y += this->deceleration * deltaTime;
        if (this->velocity.y > 0.f) { this->velocity.y = 0.f; }
    }

    // Move the sprite only if there is some velocity (X or Y)
    if (this->velocity.x != 0.f || this->velocity.y != 0.f)
    {
        this->sprite.move(this->velocity);
    }
}

// Destructor (no need for specific implementation since we don't have dynamic memory allocation in this class)
MovementComponent::~MovementComponent()
{
}

