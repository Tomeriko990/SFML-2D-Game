#include "Game_Engine.h"
#include <fstream>


Game_Engine::Game_Engine()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
   
}

void Game_Engine::initWindow()

{
    this->windowSize.x=1122;
    this->windowSize.y=800;

    this->settings.antialiasingLevel=8;
    this->window=new sf::RenderWindow(sf::VideoMode(windowSize.x,windowSize.y),"RPG Game",sf::Style::Default,settings);
    this->window->setFramerateLimit(120);

}

void Game_Engine::initKeys()
{
    std::ifstream file("/Users/tomerantebi/Documents/rpgGame/config/supported_keys.txt");

    if(file.is_open())
    {
        std::string key="";
        int key_value=0;

        while(file>> key >>key_value)
        {
            this->supportedKeys[key]=key_value;
        }
    }
    file.close();
}

void Game_Engine::initStates()
{
    this->states.push(new Main_menu_state(this->window,&this->supportedKeys,&this->states));
}

void Game_Engine::updateDeltaTime()
{
    this->deltaTime=this->clock.restart().asSeconds();
}

void Game_Engine::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent)) {

        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }         
    }
}

void Game_Engine::update()
{
    this->updateDeltaTime();
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->updateState(this->deltaTime);

        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            State* state=this->states.top();
            this->states.pop();
            delete state;
            
        }
    }
    // states is empty then end program
    else
    {
        this->window->close();
    }
}

void Game_Engine::draw()
{

    this->window->clear();

    // draw 

    if (!this->states.empty())
    {
        this->states.top()->drawState(this->window);
    }

    this->window->display();
}

void Game_Engine::run()
{
    while(this->window->isOpen())
    {
        this->update();
        this->draw();
    }
}

Game_Engine::~Game_Engine()
{
    delete this->window;
    while(!this->states.empty())
    {
        this->states.top()->endState();
        State* state=this->states.top();
        this->states.pop();
        delete state;
    }
    
}
