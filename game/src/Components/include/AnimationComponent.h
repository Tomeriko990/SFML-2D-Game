#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AnimationComponent
{
private:

    sf::Texture& tileSheet;
    sf::Sprite& Sprite;

    sf::Vector2u textureSize;

    class Animation
    {
    public:
        sf::Sprite& sprite;

        float animationTimer;
        float timer;

        sf::IntRect startRect;
        sf::IntRect currentRect;
        sf::IntRect endRect;
        int width;
        int height;

        bool done;

        Animation(sf::Sprite& Sprite,const float&animationtimer,int startX,int startY,int endX,int endY,int Width,int Height)
        :sprite(Sprite),done(false),animationTimer(animationtimer),timer(0.f),width(Width),height(Height)
        {
            this->startRect=sf::IntRect(startX*Width,startY*Height,Width,Height);
            this->currentRect=this->startRect;
            this->endRect=sf::IntRect(endX*Width,endY*Height,Width,Height);
        }
        ~Animation(){};

        const bool& play(const float& deltaTime)
        {
            this->done=false;
            this->timer+=deltaTime*100.f;

            if(this->timer>=this->animationTimer)
            {
                //Reset timer
                this->timer=0.f;

                // Update the current rectangle for the animation frames
                if(this->currentRect!=this->endRect)
                {
                    this->currentRect.left+=this->width;
                }

                //Reset when reach the end
                else
                {
                    this->done=true;
                    this->currentRect=this->startRect;
                } 
            }
            // Update the sprite's texture rectangle
            this->sprite.setTextureRect(this->currentRect);
            return this->done;
        }

        const bool& play(const float& deltaTime,float mod_percent)
        {
            this->done=false;
            if(mod_percent<0.5f){mod_percent=0.5f;}

            this->timer+=deltaTime*100.f*mod_percent;

            if(this->timer>=this->animationTimer)
            {
                //Reset timer
                this->timer=0.f;

                // Update the current rectangle for the animation frames
                if(this->currentRect!=this->endRect)
                {
                    this->currentRect.left+=this->width;
                }

                //Reset when reach the end
                else
                {
                    this->done=true;
                    this->currentRect=this->startRect;
                } 
            }
            // Update the sprite's texture rectangle
            this->sprite.setTextureRect(this->currentRect);
            return this->done;
        }
        
        void reset()
        {
            this->timer=this->animationTimer;
            this->currentRect=this->startRect;
        }

        const bool& isDone()
        {
            return this->done;
        }
    };
    std::map<std::string,Animation*> Animations;
    Animation* priorityAnimation;
    Animation* lastAnimation;
public:

    AnimationComponent(sf::Texture&tile_sheet,sf::Sprite& sprite);

    void addAnimation(
        std::string key,
        const float& animationTimer,
        int startX,int startY,int endX,int endY,
        int width,int height);

    const bool& isDone(std::string key);
    const bool& play(std::string key,const float& deltaTime,const bool& priotrity);
    const bool& play(std::string key,const float& deltaTime,const float& modifierPercent,const bool& priotrity);     

    virtual ~AnimationComponent();
};


