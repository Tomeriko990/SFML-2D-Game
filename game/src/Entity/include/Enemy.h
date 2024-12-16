#pragma once
#include <SFML/Graphics.hpp>
#include "ArrowStack.h"

class Enemy
{
private:
    sf::Vector2i size;  // Holds the size of the enemy (not yet used in the code)
    sf::Text HealthText;  // Text object for displaying health
    sf::Font font;  // Font used for the health text
    float moveSpeed;  // The movement speed of the enemy

public:
    sf::Sprite Sprite;  // The graphical representation of the enemy (sprite)
    int HealthPoint;  // The health points of the enemy

public:
    // The 'Map' class is a friend of this class, giving it access to private members
    friend class Map;

    // Constructor for the Enemy class
    Enemy();
    
    // Method to update the enemy's state (movement, health, etc.) each frame
    void update(sf::RenderWindow& window, float deltaTime);  

    // Method to draw the enemy and its health text to the screen
    void draw(sf::RenderWindow& window, float deltaTime);

    // Method to modify the enemy's health when it takes damage
    void ChangeHP(int damage=0);

    // Setter method for setting the font for the health text (allows external configuration)
    void setFont(const sf::Font& f) { font = f; }
};






