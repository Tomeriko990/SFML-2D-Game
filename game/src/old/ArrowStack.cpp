#include "Math.h"
#include "ArrowStack.h"
#include "Textures.h"
#include <iostream>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/MovementComponent.h"

ArrowStack::Arrow::Arrow(sf::Texture& Texture):
texture(Texture),available(false),speed(250.f)
{
    arrow.setTexture(this->texture);
}

void ArrowStack::Arrow::draw(sf::RenderTarget &target)
{
    target.draw(this->arrow);
}

void ArrowStack::Arrow::update(const float &deltaTime)
{
    arrow.move(deltaTime*this->direction*this->speed);
}

const bool &ArrowStack::Arrow::isAvailable()
{
    return this->available;
}

void ArrowStack::Arrow::shoot(const sf::Vector2f& Position,const sf::Vector2f& Direction)
{
    this->direction=Direction;
    Math::normalizeVector(this->direction);
    this->arrow.setPosition(Position);
    this->setRectangle();
    this->available=true;
}

void ArrowStack::Arrow::setRectangle()
{
    float deltaX = this->direction.x;
    float deltaY = this->direction.y;
    sf::Vector2f size(64.f,64.f);
    this->arrow.setTextureRect(sf::IntRect(0*size.x,0*size.y,size.x,size.y));

    if (std::abs(deltaX) < std::abs(deltaY)) 
    {
        this->arrow.setTextureRect(sf::IntRect(4*size.x,2*size.y,size.x,size.y));
        if (deltaY > 0) 
        {
            arrow.setScale(1.f, 1.f);  // ירי למטה
            //arrow.setTextureRect(sf::IntRect(4 * size.x, 2 * size.y, size.x, size.y)); 
        } 
        else 
        {
            arrow.setScale(1.f, -1.f);  // ירי למעלה
            //arrow.setTextureRect(sf::IntRect(4 * size.x, 0 * size.y, size.x, size.y)); 
        }
    }
    else 
    {
        this->arrow.setTextureRect(sf::IntRect(0*size.x,0*size.y,size.x,size.y));
        if (deltaX > 0) 
        {
            arrow.setScale(-1.f, 1.f);  // ירי ימינה
            //arrow.setTextureRect(sf::IntRect(1 * size.x, 3 * size.y, size.x, size.y));
        } 
        else 
        {
            arrow.setScale(1.f, 1.f);  // ירי שמאלה
            //arrow.setTextureRect(sf::IntRect(1 * size.x, 1 * size.y, size.x, size.y)); 
        }
    } 
    /*if(deltaX<=200&&deltaX>=-200){
        if(deltaY>0){
            arrow.setScale(1.f,-1.f);
            //arrow.setTextureRect(sf::IntRect(4 * size.x, 2 * size.y, size.x, size.y)); // up
            return;
        }
        arrow.setScale(1.f,1.f);
        //arrow.setTextureRect(sf::IntRect(4 * size.x, 0 * size.y, size.x, size.y)); // down
        return;
    } 
    if(deltaX<0){
        if(deltaY<0){
            if(deltaY>=-300)
            {// left
                arrow.setScale(1.f,1.f);
                //arrow.setTextureRect(sf::IntRect(1 * size.x, 1 * size.y, size.x, size.y)); 
                return;
            }
                arrow.setScale(1.f,-1.f);
                //arrow.setTextureRect(sf::IntRect(1 * size.x, 0 * size.y, size.x, size.y)); // left up
                return;
            }
            else{
                if(deltaY<=300)
                {// left
                    arrow.setScale(1.f,1.f);
                    //arrow.setTextureRect(sf::IntRect(1 * size.x, 1 * size.y, size.x, size.y)); 
                    return; 
                }
                arrow.setScale(1.f,1.f);
                //arrow.setTextureRect(sf::IntRect(1 * size.x, 1 * size.y,size.x,size.y)); // left down
                return;
            }
    }
    else{
        if(deltaY<0){
            if(deltaY<=300)
            {
                arrow.setScale(-1.f,1.f);
                //arrow.setTextureRect(sf::IntRect(1 * size.x, 3 * size.y, size.x, size.y));
                return;
            } // right

            arrow.setScale(-1.f,1.f);
            //arrow.setTextureRect(sf::IntRect(0 * size.x, 3 * size.y, size.x, size.y)); // right up
            return; 
        }
        else{
            if(deltaY<=300)
            {
                arrow.setScale(-1.f,1.f);
                //arrow.setTextureRect(sf::IntRect(1 * size.x, 3 * size.y, size.x, size.y));
                return;
            } // right
            arrow.setScale(-1.f,-1.f);
            //arrow.setTextureRect(sf::IntRect(1 * size.x, 2 * size.y, size.x, size.y)); // right down
            return;
            }
    }*/
}

ArrowStack::ArrowStack(sf::Sprite& Sprite,int max_Arrows):
sprite(Sprite),maxArrows(max_Arrows),currentArrows(max_Arrows)
{
    if (this->texture.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Bullet/Bullet_Texture/WEAPON_spear.png")); 
    {
        std::cout << "Error loading texture" << std::endl;
    }
    for(int i=0;i<this->maxArrows;i++)
    {
        this->Arrows.push_back(Arrow(this->texture));
    }
}

bool ArrowStack::canShoot()
{
    return this->currentArrows > 0;
}

void ArrowStack::reload(int arrows)
{
    currentArrows=std::min(this->maxArrows,arrows+this->currentArrows);
}

void ArrowStack::shootArrow(const sf::Vector2f& Direction)
{
    if(this->currentArrows>0)
    {
        for(auto &i:this->Arrows)
        {
            if(!i.isAvailable())
            {

                i.shoot(this->sprite.getPosition(),Direction);
                break;
            }
        }
        --currentArrows;
    }
}

int ArrowStack::getCurrentArrows()
{
    return this->currentArrows;
}

void ArrowStack::update(const float &deltaTime)
{
   for(auto &i:this->Arrows)
   {
        if(i.isAvailable())
        {
            i.update(deltaTime);
        }
   }
}

void ArrowStack::draw(sf::RenderTarget &target)
{
    for(auto &i:this->Arrows)
    {
        if(i.isAvailable())
        {
            i.draw(target);
        }
    }
    
}
