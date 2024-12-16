// --- GameState.cpp ---
#include "GameState.h"

/**
 * @brief Initializes textures for the player.
 */
void GameState::initTextures() {
    this->textures["PLAYER_WALK"] = new sf::Texture();
    if (!this->textures["PLAYER_WALK"]->loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Player/Assets/Player/Textures/player_walk.png")) {
        std::cerr << "Error loading PLAYER_WALK texture" << std::endl;
    }

    this->textures["PLAYER_ATTACK_BOW"] = new sf::Texture();
    if (!this->textures["PLAYER_ATTACK_BOW"]->loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Player/Assets/Player/Textures/player_bow.png")) {
        std::cerr << "Error loading PLAYER_BOW texture" << std::endl;
    }
}

/**
 * @brief Initializes variables and core objects for the game state.
 */
void GameState::initVariables() {
    this->player = new Player(
        sf::Vector2f(200.f, 200.f), &this->textures
    );
    this->font = new sf::Font();
    this->pauseMenu = new PauseMenu(*this->s_window, *this->font, this->buttons);
}

/**
 * @brief Binds keys to actions for the game state by reading from a configuration file.
 */
void GameState::initKeyBindes() {
    std::ifstream file("/Users/tomerantebi/Documents/rpgGame/config/gameState_keybinds.txt");

    if (file.is_open()) {
        std::string key1 = "";
        std::string key2 = "";

        while (file >> key1 >> key2) {
            std::cout << key1 << " " << key2 << std::endl;
            this->s_keyBindes[key1] = this->s_supportedKeys->at(key2);
        }
    } else {
        std::cerr << "ERROR::GAMESTATE::COULD NOT OPEN gameState_keybinds.txt" << std::endl;
    }
    file.close();
}

/**
 * @brief Constructs the game state, initializing textures, variables, and key bindings.
 */
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states) 
: State(window, supportedKeys, states) {
    this->initTextures();
    this->initVariables();
    this->initKeyBindes();
}

/**
 * @brief Destroys the game state, releasing allocated resources.
 */
GameState::~GameState() {
    delete this->player;
    delete this->font;
    delete this->pauseMenu;
}

/**
 * @brief Updates key bindings and handles player input.
 */
void GameState::updateKeyBindes(const float &deltaTime) {
    static float timer = 0.f;
    timer += deltaTime;
    this->paused = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("CLOSE"))) && timer >= 0.1f) {
        timer = 0.f;
        this->paused = true;
    }

    if (!this->isPaused()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !this->player->isShooting()) {
            float deltaX = mousePosCamera.x - this->player->getPosition().x;
            float deltaY = mousePosCamera.y - this->player->getPosition().y;
            sf::Vector2f direction(deltaX, deltaY);
            this->player->shoot(deltaTime, direction);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_UP")))) {
            this->player->move(deltaTime, 0.f, -1.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_DOWN")))) {
            this->player->move(deltaTime, 0.f, 1.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_LEFT")))) {
            this->player->move(deltaTime, -1.f, 0.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_RIGHT")))) {
            this->player->move(deltaTime, 1.f, 0.f);
        }
    }
}

/**
 * @brief Updates the game state.
 */
void GameState::updateState(const float &deltaTime) {
    this->updateMousePositions();
    this->updateKeyBindes(deltaTime);
    if (!this->isPaused()) {
        if (this->player) {
            this->player->update(deltaTime);
        }
    } else {
        this->updatePauseState(deltaTime);
    }
}

/**
 * @brief Updates the pause menu state.
 */
void GameState::updatePauseState(const float &deltaTime) {
    this->pauseMenu->update(deltaTime);
}

/**
 * @brief Draws the game state or pause menu, depending on the current state.
 */
void GameState::drawState(sf::RenderTarget *target) {
    if (!this->isPaused()) {
        if (this->player) {
            this->player->drawEntity(target);
            this->player->drawArrows(*target);
        }
    } else {
        if (this->pauseMenu) {
            this->pauseMenu->draw(*target);
        }
    }
}

/**
 * @brief Ends the game state, marking it for termination.
 */
void GameState::endState() {
    this->quit = true;
}








//end/////////////////////




#include "GameState.h"


void GameState::initTextures()
{
    this->textures["PLAYER_WALK"]=new sf::Texture();
    if (!this->textures["PLAYER_WALK"]->loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Player/Assets/Player/Textures/player_walk.png"))
    {
        std::cerr << "Error loading PLAYER_WALK texture" << std::endl;
    }
    
    this->textures["PLAYER_ATTACK_BOW"]=new sf::Texture();
    if (!this->textures["PLAYER_ATTACK_BOW"]->loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/Player/Assets/Player/Textures/player_bow.png"))
    {
        std::cerr << "Error loading PLAYER_BOW texture" << std::endl;
    }
}

void GameState::initVariables()
{
    this->player=new Player(
        sf::Vector2f(200.f,200.f),&this->textures
    );
    this->font=new sf::Font();
    this->pauseMenu=new PauseMenu(*this->s_window,*this->font,this->buttons);
}

void GameState::initKeyBindes()
{
    std::ifstream file("/Users/tomerantebi/Documents/rpgGame/config/gameState_keybinds.txt");

    if(file.is_open())
    {

        std::string key1="";
        std::string key2="";

        while(file>>key1>>key2)
        {
            std::cout<<key1<<" "<<key2<<std::endl;
            this->s_keyBindes[key1]=this->s_supportedKeys->at(key2);
        }
        
    }
    else
    {
        std::cerr << "ERROR::GAMESTATE::COULD NOT OPEN gameState_keybinds.txt" << std::endl;
        return;
    }
    file.close();
}

GameState::GameState(sf::RenderWindow *window,std::map<std::string,int> *supportedKeys,std::stack<State *>* states) 
:State(window, supportedKeys,states)
{
    this->initTextures();
    this->initVariables();
    this->initKeyBindes();
}

GameState::~GameState()
{
    delete this->player;
    delete this->font;
    delete this->pauseMenu;
}

void GameState::updateKeyBindes(const float& deltaTime)
{
    static float timer=0.f;
    timer+=deltaTime;
    this->paused=false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("CLOSE")))
        && timer>=0.1f)
    {
        timer=0.f;
        this->paused=true;
    }

    if(!this->isPaused())
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!this->player->isShooting())
        {
            float deltaX=mousePosCamera.x-this->player->getPosition().x;
            float deltaY=mousePosCamera.y-this->player->getPosition().y;
            sf::Vector2f direction(deltaX,deltaY);
            this->player->shoot(deltaTime,direction);
        }   
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_UP"))))
        {
            this->player->move(deltaTime,0.f,-1.f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_DOWN"))))
        {
            this->player->move(deltaTime,0.f,1.f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_LEFT"))))
        {
            this->player->move(deltaTime,-1.f,0.f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->s_keyBindes.at("MOVE_RIGHT"))))
        {
            this->player->move(deltaTime,1.f,0.f);
        }
    }
}

void GameState::updateState(const float& deltaTime)
{
    this->updateMousePositions();
    this->updateKeyBindes(deltaTime);
    if(!this->isPaused())
    {
        if(this->player){this->player->update(deltaTime);}
    }
    else
    {
        this->updatePauseState(deltaTime);
    }     
}

void GameState::updatePauseState(const float &deltaTime)
{
    this->pauseMenu->update(deltaTime);
}

void GameState::drawState(sf::RenderTarget* target)
{
    if(!this->isPaused())
    {
        if(this->player)
        {
            this->player->drawEntity(target);
            this->player->drawArrows(*target);
        }
    }
    else
    {
        if(this->pauseMenu)
        {
            this->pauseMenu->draw(*target);
        }
    }       
}
    
void GameState::endState()
{
    this->quit=true;
}
