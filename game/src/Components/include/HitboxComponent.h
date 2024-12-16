#pragma once
#include <SFML/Graphics.hpp>

class HitboxComponent
{
private:
    sf::Sprite& sprite;            // Reference to the sprite that this hitbox belongs to
    sf::RectangleShape hitBox;     // The hitbox shape itself (RectangleShape for collision detection)
    float offsetX;                 // X offset from the sprite position
    float offsetY;                 // Y offset from the sprite position
    sf::Vector2f scale;            // Scale of the hitbox (can be different from the sprite scale)

public:
    float width;                   // Width of the hitbox
    float height;                  // Height of the hitbox

    // Constructor: Initializes the hitbox with the given dimensions and offsets
    HitboxComponent(sf::Sprite& Sprite, float offset_x, float offset_y, float Width, float Height);
    
    // Destructor (no special handling needed for this case)
    ~HitboxComponent();

    // Checks if the hitbox intersects with another rectangle (used for collision detection)
    const bool& isIntersect(const sf::FloatRect& frect);

    // Updates the position and scale of the hitbox based on the sprite's current position and scale
    void update();

    // Draws the hitbox on the provided render target (for debugging purposes)
    void draw(sf::RenderTarget* target);
};






