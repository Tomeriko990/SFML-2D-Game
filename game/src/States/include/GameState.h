// GameState.h
#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Player.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/States/PauseMenu.h"

/**
 * @class GameState
 * @brief Handles the main gameplay state, including player actions and pause menu functionality.
 */
class GameState : public State {
private:
    // State variables
    bool paused; ///< Indicates if the game is currently paused.

    // Core objects
    Player* player; ///< Pointer to the player object.
    PauseMenu* pauseMenu; ///< Pointer to the pause menu object.

    // Textures
    std::map<std::string, sf::Texture*> textures; ///< Stores game textures.

    // Initialization functions
    void initVariables(); ///< Initializes internal variables.
    void initPauseMenuState(); ///< Sets up the pause menu.
    void initKeyBindes(); ///< Binds keys for this state.
    void initTextures(); ///< Loads required textures.

public:
    // Constructors and Destructors
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    ~GameState();

    // Accessors
    const bool& isPaused(); ///< Returns whether the game is paused.

    // Core Functions
    void updateKeyBindes(const float& deltaTime); ///< Updates key bindings.
    void updateState(const float& deltaTime); ///< Updates the main state.
    void updatePauseState(const float& deltaTime); ///< Updates the pause state.

    void drawState(sf::RenderTarget* target = nullptr); ///< Draws the main state.
    void drawPauseState(sf::RenderTarget* target = nullptr); ///< Draws the pause state.

    void endState(); ///< Ends the state and performs cleanup.
};















#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/Player.h"
#include "/Users/tomerantebi/Documents/rpgGame/game/src/States/PauseMenu.h"


class GameState:

public State

{
private:

    bool paused;

    Player* player;
    PauseMenu* pauseMenu;

    void initVariables();
    void initPauseMenuState();
    void initKeyBindes();
    void initTextures();

public:

    GameState(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);
    ~GameState();

    const bool& isPaused();
    
    void updateKeyBindes(const float& deltaTime);
    void updateState(const float& deltaTime);
    void updatePauseState(const float& deltaTime);

    void drawState(sf::RenderTarget* target=nullptr);
    void drawPauseState(sf::RenderTarget* target=nullptr);

    void endState();
};

