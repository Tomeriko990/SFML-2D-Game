#include "Enemy.h"
#include "Textures.h"

Enemy::Enemy():size(64,64),moveSpeed(200.0f),HealthPoint(100)
{
    Sprite.setTexture(Textures::Skeleton);
    Sprite.setTextureRect(sf::IntRect(0,2*size.y,size.x,size.y));
    Sprite.scale(sf::Vector2f(3,3));
    Sprite.setPosition(500,500);
    HealthText.setFont(Textures::Ariel);
    HealthText.setFillColor(sf::Color::White);
    HealthText.setString(std::to_string(HealthPoint));
    HealthText.setPosition(Sprite.getPosition());
}
void Enemy::update(sf::RenderWindow& window)
{
    if(HealthPoint == 0 && Sprite.getTexture() != &Textures::SkeletonDead){
        Sprite.setTexture(Textures::SkeletonDead);
    }
    else
    {
        Sprite.setPosition(500,500);
    }
}
void Enemy::draw(sf::RenderWindow& window,float deltaTime)
{
    if(HealthPoint>=0)
    {
        static float elapsedTime=0.f;
        static int frameIndex=0;
        elapsedTime+=deltaTime;
        if(HealthPoint==0)
        {
            if(elapsedTime>=0.5f)
            {
                elapsedTime=0.f;
                Sprite.setTextureRect(sf::IntRect(frameIndex * size.x,0* size.y, size.x, size.y));
                frameIndex++;
                window.draw(Sprite);
                if(frameIndex==6){HealthPoint--;}
            }
        }
        else
        {
            window.draw(HealthText);
        }
        window.draw(Sprite);
    }
}
void Enemy::ChangeHP(int damage=0)
{
    HealthPoint-=damage;
    HealthText.setString(std::to_string(HealthPoint));
    HealthText.setPosition(Sprite.getPosition());
}
