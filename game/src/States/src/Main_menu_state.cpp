// --- Main_menu_state.cpp ---
#include "Main_menu_state.h"

/**
 * @brief Initializes the background texture and sprite for the main menu.
 */
void Main_menu_state::initBackGround() {
    if (this->backGroundTexture.loadFromFile("/Users/tomerantebi/Documents/rpgGame/game/Assets/backGround_main_manu/background.png")) {
        this->backGround.setTexture(this->backGroundTexture);
    }

    this->backGround.setTextureRect(
        sf::IntRect(
            0.f,
            0.f,
            static_cast<float>(this->s_window->getSize().x),
            static_cast<float>(this->s_window->getSize().y)
        )
    );
}

/**
 * @brief Initializes essential variables for the main menu state.
 */
void Main_menu_state::initVariables() {
    this->font = new sf::Font();
    this->font->loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf");
}

/**
 * @brief Binds keys to actions for the main menu state by reading from a configuration file.
 */
void Main_menu_state::initKeyBindes() {
    std::ifstream file("/Users/tomerantebi/Documents/rpgGame/config/main_manu_state.txt");

    if (file.is_open()) {
        std::string key1 = "";
        std::string key2 = "";

        while (file >> key1 >> key2) {
            this->s_keyBindes[key1] = this->s_supportedKeys->at(key2);
        }
    } else {
        std::cerr << "ERROR::GAMESTATE::COULD NOT OPEN gameState_keybinds.txt" << std::endl;
    }
    file.close();
}

/**
 * @brief Creates buttons for the main menu (e.g., New Game, Quit).
 */
void Main_menu_state::initButtons() {
    sf::Vector2f pos(500, 200);
    sf::Vector2f size(100, 50);

    this->buttons["NEW_GAME"] = new Button(
        pos, size, this->font,
        "New game",
        sf::Color(200, 200, 200, 200),
        sf::Color(250, 250, 250, 250),
        sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );

    pos = sf::Vector2f(500, 500);

    this->buttons["QUIT_GAME"] = new Button(
        pos, size, this->font,
        "Quit game",
        sf::Color(200, 200, 200, 200),
        sf::Color(250, 250, 250, 250),
        sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );
}

/**
 * @brief Updates the main menu state.
 */
void Main_menu_state::updateState(const float &deltaTime) {
    this->updateMousePositions();
    this->updateKeyBindes(deltaTime);
    this->updateButtons(deltaTime);

    if (this->buttons["NEW_GAME"]->isPressed()) {
        this->states->push(new GameState(this->s_window, this->s_supportedKeys, this->states));
    }

    if (this->buttons["QUIT_GAME"]->isPressed()) {
        this->endState();
    }
}

//@brief Draws the main menu state.

//@brief Updates the buttons in the main menu.
void Main_menu_state::updateButtons(const float &deltaTime) {
    for (auto &it : this->buttons) {
        it.second->updateButton(this->mousePosCamera);
    }
}
/**
 * @brief Draws the buttons in the main menu.
 */
void Main_menu_state::drawButtons(sf::RenderTarget *target) {
    for (auto &it : this->buttons) {
        it.second->drawButton(target);
    }
}
/**
 * @brief Constructs the main menu state and initializes components.
 */
Main_menu_state::Main_menu_state(
    sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states) {
    this->initBackGround();
    this->initVariables();
    this->initKeyBindes();
    this->initButtons();
}

/**
 * @brief Ends the main menu state and marks it for cleanup.
 */
void Main_menu_state::endState() {
    this->quit = true;
}

/**
 * @brief Destroys the main menu state and releases allocated resources.
 */
Main_menu_state::~Main_menu_state() {
    for (auto &pair : this->buttons) {
        delete pair.second;
    }
    delete this->font;
}

























//end ddddd


#include "Main_menu_state.h"

void Main_menu_state::initBackGround()
{
    
    if(this->backGroundTexture.loadFromFile(
        "/Users/tomerantebi/Documents/rpgGame/game/Assets/backGround_main_manu/background.png")
    )
    {
        this->backGround.setTexture(this->backGroundTexture);
    }

    this->backGround.setTextureRect(
        sf::IntRect(
            0.f,
            0.f,
            static_cast<float>(this->s_window->getSize().x),
            static_cast<float>(this->s_window->getSize().y)
        )   
    );
        
}

void Main_menu_state::initVariables()
{
    
    this->font=new sf::Font();
    this->font->loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf");
}

void Main_menu_state::initKeyBindes()
{
   std::ifstream file("/Users/tomerantebi/Documents/rpgGame/config/main_manu_state.txt");

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

void Main_menu_state::initButtons()
{
    sf::Vector2f pos(500,200);
    sf::Vector2f size(100,50);

    this->buttons["NEW_GAME"]=(new Button
        (
        pos,size,this->font,
        "New game",
        sf::Color(200,200,200,200),
        sf::Color(250,250,250,250),
        sf::Color(20,20,20,50),
        sf::Color(70,70,70,0),
        sf::Color(150,150,150,0),
        sf::Color(20,20,20,0)
        ));

    pos=sf::Vector2f(500,500);

    this->buttons["QUIT_GAME"]=(new Button
        (
        pos,size,this->font,
        "Quit game",
        sf::Color(200,200,200,200),
        sf::Color(250,250,250,250),
        sf::Color(20,20,20,50),
        sf::Color(70,70,70,0),
        sf::Color(150,150,150,0),
        sf::Color(20,20,20,0)
        ));    

}


Main_menu_state::Main_menu_state(
    sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *>* states)
    :State(window, supportedKeys,states)
{
    this->initBackGround();
    this->initVariables();
    this->initKeyBindes();
    this->initButtons();
}

Main_menu_state::~Main_menu_state()
{
    for (auto &pair : this->buttons)
    {
        delete pair.second;
    }
    delete this->font;
    
}

void Main_menu_state::updateKeyBindes(const float &deltaTime)
{
    //
}

void Main_menu_state::updateState(const float &deltaTime)
{
    this->updateMousePositions();
    this->updateKeyBindes(deltaTime);
    this->updateButtons(deltaTime);

    if(this->buttons["NEW_GAME"]->isPressed())
    {
        this->states->push(new GameState(this->s_window,this->s_supportedKeys,this->states));
    }

    if(this->buttons["QUIT_GAME"]->isPressed())
    {
        this->endState();
    }
}

void Main_menu_state::updateButtons(const float &deltaTime)
{
    auto it=buttons.begin();

    for(it=this->buttons.begin();it!=this->buttons.end();++it)
    {
        it->second->updateButton(this->mousePosCamera);
    }
}

void Main_menu_state::drawState(sf::RenderTarget *target)
{
    if(!target)
    {
        target=this->s_window;
    }

    target->draw(this->backGround);
    this->drawButtons(target);

    
}

void Main_menu_state::drawButtons(sf::RenderTarget *target)
{
    auto it=buttons.begin();

    for(it=this->buttons.begin();it!=this->buttons.end();++it)
    {
        it->second->drawButton(target);
    }
}

void Main_menu_state::endState()
{
    this->quit=true;
}
