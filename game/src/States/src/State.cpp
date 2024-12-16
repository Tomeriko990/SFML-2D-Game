#include "State.h"

// Constructor - Initializes the state with window, supported keys, and state stack
State::State(sf::RenderWindow *window, std::map<std::string,int>* supportedKeys, std::stack<State *>* state)
{
    this->s_window = window;                          // Store window reference
    this->s_supportedKeys = supportedKeys;             // Store supported keys map
    this->states = state;                              // Store pointer to state stack
    this->quit = false;                                // Initialize quit flag to false
}

// Destructor - Frees dynamically allocated texture memory
State::~State()
{
    // Iterate over all textures and delete dynamically allocated memory
    for (auto &pair : this->textures)
    {
        delete pair.second;                            // Free memory allocated for textures
    }
}

// Check if the player pressed the key to quit the game
void State::checkForQuit()
{
    // Check if the close key (mapped in s_keyBindes) is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("CLOSE"))))
    {
        this->quit = true;                           // Set quit flag to true
    }
}

// Update mouse position in different coordinate spaces
void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();                  // Get mouse position relative to screen
    this->mousePosWindow = sf::Mouse::getPosition(*this->s_window);   // Get mouse position relative to window
    this->mousePosCamera = this->s_window->mapPixelToCoords(sf::Mouse::getPosition(*this->s_window)); // Map pixel position to camera coordinates
}

// Returns the current quit flag
const bool& State::getQuit()
{
    return this->quit;  // Return reference to quit flag
}
