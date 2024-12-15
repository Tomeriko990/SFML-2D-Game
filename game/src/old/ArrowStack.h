#pragma once
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/MovementComponent.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Components/AnimationComponent.h"
#include <vector>
class ArrowStack
{
    class Arrow
    {
    
    public:
        float speed;
        sf::Vector2f direction;
        bool available;

        sf::Texture& texture;
        sf::Sprite arrow;

        Arrow(sf::Texture& Texture);
        void setRectangle();
        void draw(sf::RenderTarget &target);
        void shoot(const sf::Vector2f& Position,const sf::Vector2f& Direction);
        void update(const float& deltaTime);
        const bool& isAvailable();
    };

    int maxArrows;
    int currentArrows;

    sf::Texture texture;
    sf::Sprite& sprite;

    std::vector<Arrow> Arrows;
public:
    ArrowStack(sf::Sprite& Sprite,int max_Arrows);

    bool canShoot();
    void reload(int arrows);
    void shootArrow(const sf::Vector2f& Direction);
    int getCurrentArrows();

    void update(const float &deltaTime);
    void draw(sf::RenderTarget &target);
};

