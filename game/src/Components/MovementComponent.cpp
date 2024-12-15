#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& Sprite,float MaxVelocity,float Acceleration,float Deceleration)
:sprite(Sprite),maxVelocity(MaxVelocity),acceleration(Acceleration),deceleration(Deceleration)
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
    return this->velocity;
}

const float &MovementComponent::getMaxVelocity() const
{
    return this->maxVelocity;
}

const bool MovementComponent::getMovementState(const short unsigned state) const
{
    switch (state)
    {
    case IDLE:
        if(this->velocity.x==0.f&&this->velocity.y==0.f){return true;}
        break;

    case UP:
        if(this->velocity.y<0.f){return true;}
        break;

    case LEFT:
        if(this->velocity.x<0.f){return true;}
        break;  

    case DOWN:
        if(this->velocity.y>0.f){return true;}
        break;

    case RIGHT:
        if(this->velocity.x>0.f){return true;}
        break;    
    }
    return false;
}

void MovementComponent::move(const float &deltaTime, const float &dir_x, const float &dir_y)
{
    // Accelerating X & Y based on input directions
    this->velocity.x+=this->acceleration*dir_x*deltaTime;
    this->velocity.y+=this->acceleration*dir_y*deltaTime;

    // Limiting velocity (preventing velocity leak)
    if (this->velocity.x > maxVelocity){this->velocity.x = maxVelocity;}
    else if (this->velocity.x < -maxVelocity){this->velocity.x = -maxVelocity;}

    if (this->velocity.y > maxVelocity){this->velocity.y = maxVelocity;}
    else if (this->velocity.y < -maxVelocity){this->velocity.y = -maxVelocity;}
}

void MovementComponent::update(const float &deltaTime)
{
    // Decelerating X
    if(this->velocity.x>0.f)
    {
        this->velocity.x-=this->deceleration*deltaTime;
        if(this->velocity.x<0.f){this->velocity.x=0.f;}
    }
    else if(this->velocity.x<0.f)
    {
        this->velocity.x+=this->deceleration*deltaTime;
        if(this->velocity.x>0.f){this->velocity.x=0.f;}
    }

    // Decelerating Y
    if(this->velocity.y>0.f)
    {
        this->velocity.y-=this->deceleration*deltaTime;
        if(this->velocity.y<0.f){this->velocity.y=0.f;}
    }
    else if(this->velocity.y<0.f)
    {
        this->velocity.y+=this->deceleration*deltaTime;
        if(this->velocity.y>0.f){this->velocity.y=0.f;}
    }

    // Move the sprite
    if(this->velocity.x!=0.f||this->velocity.y!=0.f)
    {
        this->sprite.move(this->velocity);
    }
}

MovementComponent::~MovementComponent()
{
}
