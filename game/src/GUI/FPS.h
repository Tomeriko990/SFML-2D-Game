#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
class FPS
{
private:
   sf::Text fps;
   sf::Text frameTime;
   std::stringstream data;
   sf::Vector2i mousePosWindow;
   sf::Vector2f mousePosCamera;
   sf::Vector2i mousePosMap; 
   static float FPSTimer;
public:
    FPS();
    void draw(sf::RenderWindow& window);
    void update(float deltaTime,sf::Vector2i mousePoswindow,sf::Vector2f mousePoscamera,
    sf::Vector2i mousePosmap,sf::Vector2f& playerPos,sf::Vector2f& playerPosCamera,sf::Vector2f& pos);
};


