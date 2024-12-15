#pragma once
#include <SFML/Graphics.hpp>

enum movementStates{IDLE=0,UP,LEFT,DOWN,RIGHT};

class MovementComponent
{
protected:

    sf::Sprite& sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;

    sf::Vector2f velocity;
   
public:
    MovementComponent(sf::Sprite& Sprite,float MaxVelocity,float Acceleration,float Deceleration);

    const sf::Vector2f& getVelocity() const;
    const float& getMaxVelocity() const;

    const bool getMovementState(const short unsigned state) const;

    virtual void move(const float& deltaTime,const float& dir_x,const float& dir_y);

    virtual void update(const float& deltaTime);

    virtual ~MovementComponent();
};

