#pragma once
#include <SFML/Graphics.hpp>

class HitboxComponent
{
private:
    sf::Sprite& sprite;
    sf::Vector2f scale;

    sf::RectangleShape hitBox;
    float offsetX;
    float offsetY;
         
public:
    float width;
    float height;
    
    HitboxComponent(sf::Sprite& Sprite,float offset_x,float offset_y,float Width,float Height);
    ~HitboxComponent();

    const bool& isIntersect(const sf::FloatRect& frect);

    void update();
    void draw(sf::RenderTarget *target);
};

