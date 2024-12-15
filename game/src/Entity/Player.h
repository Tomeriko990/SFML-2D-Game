#pragma once
#include <SFML/Graphics.hpp>
#include "/Users/tomerantebi/Documents/rpgGame/game/src/old/ArrowStack.h"
#include "Entity.h"

class Player:

public Entity
{
private:

    bool isAttacking;
    bool shootingArrow;
    bool isMoving;
    unsigned shootIndex;

    ArrowStack* quiver;

    void initVariables();
    void initTextures(std::map<std::string,sf::Texture*>* Textures);
    void initComponents();
    
public:

    Player(const sf::Vector2f& position,std::map<std::string, sf::Texture*>*Textures);

    ~Player();

    void update(const float& deltaTime);
    void shoot(const float& deltaTime,sf::Vector2f& Direction);
    void updateArrows(const float& deltaTime);
    
    void drawArrows(sf::RenderTarget& target);
    //void update(sf::Vector2f& playerPosMap,sf::Vector2i& mousePosMap,float deltaTime,Enemy& enemy);
    //void draw(sf::RenderWindow& window,float deltaTime);
    inline const sf::Vector2f& getPosition(){return this->sprite->getPosition();}
    inline const bool& isShooting(){return this->shootingArrow;}

    
};

