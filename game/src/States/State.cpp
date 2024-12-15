#include "State.h"

State::State(sf::RenderWindow *window,std::map<std::string,int>* supportedKeys,std::stack<State *>* state)
{

    this->s_window=window;
    this->s_supportedKeys=supportedKeys;
    this->states=state;

    this->quit=false;

}

State::~State()
{
    for (auto &pair : this->textures)
    {
        delete pair.second;
    }
}

void State::checkForQuit()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("CLOSE"))))
    {
        this->quit=true;
    }
}

void State::updateMousePositions()
{
    this->mousePosScreen=sf::Mouse::getPosition();
    this->mousePosWindow=sf::Mouse::getPosition(*this->s_window);
    this->mousePosCamera=this->s_window->mapPixelToCoords(sf::Mouse::getPosition(*this->s_window));
}

const bool& State::getQuit()
{
    return this->quit;
}
