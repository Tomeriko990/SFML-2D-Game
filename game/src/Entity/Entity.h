#pragma once
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/MovementComponent.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/AnimationComponent.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/HitboxComponent.h"

class Entity
{
private:

protected:
    std::map<std::string,sf::Texture*> textures;
    std::map<std::string,AnimationComponent*> AnimationsC;
    
    sf::Sprite* sprite;

    HitboxComponent* hitboxComponent;
    MovementComponent* moveMentComponent;
    //AnimationComponent* animationComponent;

    float HealthPoint;
    float firerRate;


    virtual void initVariables()=0;
    virtual void initTextures(std::map<std::string,sf::Texture*>* Textures)=0;
    
public:

    Entity();
    virtual ~Entity();

    virtual void setSprite();
    virtual void setPosition(const sf::Vector2f& position);

    virtual void createHitboxComponent(float offset_x,float offset_y,float Width,float Height);
    virtual void createMoveMentComponent(const float& maxVelocity,const float &acceleration,const float &deceleration);
    virtual void createAnimationComponent(std::string key);    
    
    virtual void move(const float& deltaTime,const float& dir_x,const float& dir_y);

    virtual void update(const float& deltaTime)=0;

    virtual void drawEntity(sf::RenderTarget* target=nullptr);

};

