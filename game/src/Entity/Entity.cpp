#include "Entity.h"

Entity::Entity()
:hitboxComponent(nullptr),moveMentComponent(nullptr),
HealthPoint(100.f),firerRate(120.f)
{
}

void Entity::setSprite()
{
    this->sprite=new sf::Sprite();
    //this->sprite->setTexture(*this->textures[key]);
}

void Entity::setPosition(const sf::Vector2f& position)
{
    if(this->sprite)
    {
        this->sprite->setPosition(position.x,position.y);
    }
}

void Entity::createHitboxComponent(float offset_x, float offset_y, float Width, float Height)
{
    this->hitboxComponent=new HitboxComponent(*this->sprite,offset_x,offset_y,Width,Height);
}

void Entity::createMoveMentComponent(const float &maxVelocity, const float &acceleration, const float &deceleration)
{
    this->moveMentComponent=new MovementComponent(*this->sprite,maxVelocity,acceleration,deceleration);
}

void Entity::createAnimationComponent(std::string key)
{
    //this->animationComponent=new AnimationComponent(*this->textures[key],*this->sprite);
}

void Entity::move(const float &deltaTime, const float &dir_x, const float &dir_y)
{
    if(this->sprite&&this->moveMentComponent)
    {
        this->moveMentComponent->move(deltaTime,dir_x,dir_y);
    }  
}

void Entity::drawEntity(sf::RenderTarget *target)
{
    if(this->sprite)
    {
        target->draw(*this->sprite);
    }
    if(this->hitboxComponent)
    {
        this->hitboxComponent->draw(target);
    }
}

Entity::~Entity()
{
    delete this->sprite;
    delete this->hitboxComponent;
    delete this->moveMentComponent;
    for(auto& i:this->AnimationsC)
    {
        delete i.second;
    }
    //delete this->animationComponent;
}
