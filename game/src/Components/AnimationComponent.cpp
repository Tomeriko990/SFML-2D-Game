#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Texture& tile_sheet,sf::Sprite& sprite)
:tileSheet(tile_sheet),Sprite(sprite),lastAnimation(nullptr),priorityAnimation(nullptr)
{
    textureSize=this->tileSheet.getSize();
}

void AnimationComponent::addAnimation(
    std::string key,
    const float& animationTimer,
    int startX,int startY,int endX,int endY,int width,int height)
{
    this->Animations[key]=new Animation(Sprite,animationTimer,startX,startY,endX,endY,width,height);                                 
}

const bool &AnimationComponent::isDone(std::string key)
{
    return this->Animations[key]->isDone();
}

const bool& AnimationComponent::play(std::string key, const float &deltaTime,const bool& priotrity)
{
    if(this->priorityAnimation)
    {
        if(this->lastAnimation!=this->Animations[key])
        {
            if(this->lastAnimation==nullptr)
            {
                this->lastAnimation=this->Animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation=this->Animations[key];
            }
        }
        
        if(this->priorityAnimation->play(deltaTime))
        {
            this->priorityAnimation=nullptr;
        }
    }
    else
    {
        if(priotrity)
        {
            this->priorityAnimation=this->Animations[key];
        }
        if(this->lastAnimation!=this->Animations[key])
        {
            if(this->lastAnimation==nullptr)
            {
                this->lastAnimation=this->Animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation=this->Animations[key];
            }
        }
        this->Animations[key]->play(deltaTime);
    }
    return this->Animations[key]->isDone();
}

const bool& AnimationComponent::play(std::string key, const float &deltaTime,const float& modifierPercent,const bool& priotrity)
{
    if(this->priorityAnimation)
    {
        if(this->lastAnimation!=this->Animations[key])
        {
            if(this->lastAnimation==nullptr)
            {
                this->lastAnimation=this->Animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation=this->Animations[key];
            }
        }
        if(this->priorityAnimation->play(deltaTime,modifierPercent))
        {
            this->priorityAnimation=nullptr;
        }
    }
    else
    {
        if(priotrity)
        {
            this->priorityAnimation=this->Animations[key];
        }
        if(this->lastAnimation!=this->Animations[key])
        {
            if(this->lastAnimation==nullptr)
            {
                this->lastAnimation=this->Animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation=this->Animations[key];
            }
        }
        this->Animations[key]->play(deltaTime,modifierPercent);
    }
    return this->Animations[key]->isDone();
}

AnimationComponent::~AnimationComponent()
{
    for (auto &pair : this->Animations)
    {
        delete pair.second;
    }
}
