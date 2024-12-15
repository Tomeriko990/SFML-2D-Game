#include "State.h"
#include "GameState.h"
#include <map>



class Main_menu_state:

public State
{
    
private:

    sf::Texture backGroundTexture;
    sf::Sprite backGround;

    
    sf::Font* font;

//fuctions 

    void initBackGround();
    void initVariables();
    void initKeyBindes();
    void initButtons();

public:

    Main_menu_state(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys,std::stack<State*>* states);

    ~Main_menu_state();


    void updateKeyBindes(const float& deltaTime);

    void updateState(const float& deltaTime);

    void updateButtons(const float& deltaTime);

    void drawState(sf::RenderTarget* target=nullptr);

    void drawButtons(sf::RenderTarget* target=nullptr);

    void endState();
};




