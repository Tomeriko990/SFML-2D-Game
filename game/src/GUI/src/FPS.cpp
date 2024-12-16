#include "FPS.h"
#include "Textures.h"
#include <iostream>


float:: FPS::FPSTimer=0.f;

FPS::FPS()
{
    fps.setFont(Textures::Ariel);
    frameTime.setFont(Textures::Ariel);
    fps.setFillColor(sf::Color::White);
    fps.setPosition(0.f,0.f);
    frameTime.setFillColor(sf::Color::White);
    frameTime.setPosition(90.f,0.f);      
    fps.setCharacterSize(30);    
       
}
void FPS::draw(sf::RenderWindow &window)
{
    window.draw(fps);
    //window.draw(frameTime);
}

void FPS::update(float deltaTime,sf::Vector2i mousePoswindow,sf::Vector2f mousePoscamera,
sf::Vector2i mousePosmap,sf::Vector2f& playerPos,sf::Vector2f& playerPosCamera,sf::Vector2f& pos)
{
    static float fpsTimer=0.f;
    fpsTimer+=deltaTime;
    //if(fpsTimer>=10.f)
        //{
            
            data.str("");
            data.clear();

            data<<"window: "<<mousePoswindow.x<<" "<<mousePoswindow.y<<"\n"
                <<"camera: "<<mousePoscamera.x<<" "<<mousePoscamera.y<<"\n"
                <<"MAP: "<<mousePosmap.x<<" "<<mousePosmap.y<<"\n" 
                <<"player map: "<<playerPos.x<<" "<<playerPos.y<<"\n"
                <<"player pos camera: "<<playerPosCamera.x<<" "<<playerPosCamera.y<<"\n"
                <<" pos : "<<pos.x<<" "<<pos.y<<"\n";
            fps.setString(data.str());
              
            //fps.setString(std::to_string(int(1000000/deltaTime)));
            //frameTime.setString(std::to_string(int((deltaTime/1000000.f))));
            //fpsTimer=0.f;
        //}

}
