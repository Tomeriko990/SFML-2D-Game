#pragma once
#include <SFML/Graphics.hpp>
#include "ArrowStack.h"
class Enemy
{
private:
    sf::Vector2i size;
    sf::Text HealthText;
    float moveSpeed;
public:
    sf::Sprite Sprite;
    int HealthPoint;
public:
    friend class Map;

    Enemy();
    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window,float deltaTime);
    void ChangeHP(int damage);

};



