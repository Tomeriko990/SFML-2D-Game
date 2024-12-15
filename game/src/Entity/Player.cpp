#include "Player.h"

/**
 * @class Player
 * @brief Manages the player entity, including movement, animations, and actions.
 */

/**
 * @brief Initializes player-specific variables.
 */
void Player::initVariables() {
    this->setSprite();
    this->quiver = new ArrowStack(*this->sprite, 50);
    this->isAttacking = false;
    this->isMoving = false;
}

/**
 * @brief Initializes textures for player animations.
 */
void Player::initTextures(std::map<std::string, sf::Texture*>* Textures) {
    std::string key;
    for (auto &pair : *Textures) {
        key = pair.first;

        // Add player-specific textures
        if (key.find("PLAYER") != std::string::npos) {
            this->textures[key] = pair.second;
            this->AnimationsC[key] = new AnimationComponent(*pair.second, *this->sprite);
        }
    }
}

/**
 * @brief Initializes player components such as hitbox and movement.
 */
void Player::initComponents() {
    this->createHitboxComponent(16.f * this->sprite->getScale().x, 8.f * this->sprite->getScale().y, 64.f, 92.f);
    this->createMoveMentComponent(100.f, 5.f, 4.f);
    this->sprite->setTexture(*this->textures["PLAYER_WALK"]);

    // Add animations
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_UP", 7.f, 0, 0, 8, 0, 64, 64);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_LEFT", 7.f, 0, 1, 8, 1, 64, 64);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_DOWN", 7.f, 0, 2, 8, 2, 64, 64);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_RIGHT", 7.f, 0, 3, 8, 3, 64, 64);

    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_UP", 6.f, 0, 0, 12, 0, 64, 64);
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_LEFT", 6.f, 0, 1, 12, 1, 64, 64);
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_DOWN", 6.f, 0, 2, 12, 2, 64, 64);
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_RIGHT", 6.f, 0, 3, 12, 3, 64, 64);
}

/**
 * @brief Player constructor.
 * @param position Initial position of the player.
 * @param Textures Pointer to a map of textures.
 */
Player::Player(const sf::Vector2f& position, std::map<std::string, sf::Texture*>* Textures)
: quiver(nullptr), shootingArrow(false) {
    this->initVariables();
    this->initTextures(Textures);
    this->sprite->setOrigin(16.f, 16.f);
    this->sprite->setScale(2, 2);
    this->setPosition(position);
    this->initComponents();
}

/**
 * @brief Player destructor.
 */
Player::~Player() {
    delete this->quiver;
}

/**
 * @brief Updates the player's state.
 */
void Player::update(const float &deltaTime) {
    if (this->moveMentComponent) {
        this->moveMentComponent->update(deltaTime);
    }
    if (this->hitboxComponent) {
        this->hitboxComponent->update();
    }

    this->updateArrows(deltaTime);
}

/**
 * @brief Handles the player's shooting logic.
 */
void Player::shoot(const float &deltaTime, sf::Vector2f &Direction) {
    this->isAttacking = true;
    this->isMoving = false;
    if (this->quiver->canShoot()) {
        // Determine shooting direction
        if (Direction.x > 0.f && Direction.y <= 200.f && Direction.y >= -200.f) { this->shootIndex = 3; }
        else if (Direction.x < 0.f && Direction.y <= 200.f && Direction.y >= -200.f) { this->shootIndex = 1; }
        else if (Direction.y > 0.f && Direction.x <= 200.f && Direction.x >= -200.f) { this->shootIndex = 2; }
        else if (Direction.y < 0.f && Direction.x <= 200.f && Direction.x >= -200.f) { this->shootIndex = 0; }

        this->quiver->shootArrow(Direction);
        this->shootingArrow = true;
    }
}

/**
 * @brief Updates the arrows in the player's quiver.
 */
void Player::updateArrows(const float &deltaTime) {
    this->quiver->update(deltaTime);
}

/**
 * @brief Draws the arrows on the screen.
 */
void Player::drawArrows(sf::RenderTarget &target) {
    this->quiver->draw(target);
}



















//endd









#include "Player.h"

void Player::initVariables()
{
    this->setSprite();
    this->quiver=new ArrowStack(*this->sprite,50);
    this->isAttacking=false;
    this->isMoving=false;
}

void Player::initTextures(std::map<std::string,sf::Texture*>*Textures)
{
    std::string key;
    for (auto &pair : *Textures)
    {
        key=pair.first;

        //Check if "PLAYER" is found in temp
        if(key.find("PLAYER")!=std::string::npos)
        {
            this->textures[key]=pair.second;
            this->AnimationsC[key]=new AnimationComponent(*pair.second,*this->sprite);
        }
    }
}

void Player::initComponents()
{
    this->createHitboxComponent(
        16.f*this->sprite->getScale().x,8.f*this->sprite->getScale().y,
        64.f,92.f
    );
    this->createMoveMentComponent(100.f,5.f,4.f);
    this->sprite->setTexture(*this->textures["PLAYER_WALK"]);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_UP",7.f,0,0,8,0,64,64);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_LEFT",7.f,0,1,8,1,64,64);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_DOWN",7.f,0,2,8,2,64,64);
    this->AnimationsC["PLAYER_WALK"]->addAnimation("PLAYER_WALK_RIGHT",7.f,0,3,8,3,64,64);
    
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_UP",6.f,0,0,12,0,64,64);
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_LEFT",6.f,0,1,12,1,64,64);
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_DOWN",6.f,0,2,12,2,64,64);
    this->AnimationsC["PLAYER_ATTACK_BOW"]->addAnimation("PLAYER_ATTACK_BOW_RIGHT",6.f,0,3,12,3,64,64);
}

Player::Player(const sf::Vector2f& position,std::map<std::string,sf::Texture*>*Textures):
quiver(nullptr),shootingArrow(false)
{
    this->initVariables();
    this->initTextures(Textures);
    this->sprite->setOrigin(
        16.f,
        16.f
    );
    this->sprite->setScale(2,2);
    this->setPosition(position);
    this->initComponents();
   
    
}

Player::~Player()
{
    delete this->quiver;
}

void Player::update(const float &deltaTime)
{
    
    if(this->moveMentComponent){this->moveMentComponent->update(deltaTime);}
    if(this->hitboxComponent){this->hitboxComponent->update();}
    sf::Vector2f modifyPercent(this->moveMentComponent->getVelocity()/this->moveMentComponent->getMaxVelocity());

    if(this->isAttacking&&this->quiver->canShoot())
    {
        this->sprite->setTexture(*this->textures["PLAYER_ATTACK_BOW"]);
        if(this->shootIndex==0)
        {
            if(this->AnimationsC["PLAYER_ATTACK_BOW"]->play("PLAYER_ATTACK_BOW_UP",deltaTime,1))
            {
                this->isAttacking=false;
                this->shootingArrow=false;
            }
        }
        else if(this->shootIndex==1)
        {
            if(this->AnimationsC["PLAYER_ATTACK_BOW"]->play("PLAYER_ATTACK_BOW_LEFT",deltaTime,1))
            {
                this->isAttacking=false;
                this->shootingArrow=false;
            }
        }
        else if(this->shootIndex==2)
        {
            if(this->AnimationsC["PLAYER_ATTACK_BOW"]->play("PLAYER_ATTACK_BOW_DOWN",deltaTime,1))
            {
                this->isAttacking=false;
                this->shootingArrow=false;
            }
        }
        else if(this->shootIndex==3)
        {
            if(this->AnimationsC["PLAYER_ATTACK_BOW"]->play("PLAYER_ATTACK_BOW_RIGHT",deltaTime,1))
            {
                this->isAttacking=false;
                this->shootingArrow=false;
            }
        }
    }
    else
    {
        this->sprite->setTexture(*this->textures["PLAYER_WALK"]);
        if(this->moveMentComponent->getMovementState(IDLE))
        {
            this->AnimationsC["PLAYER_WALK"]->play("PLAYER_WALK_RIGHT",deltaTime,0);
        }
        else if(this->moveMentComponent->getMovementState((UP)))
        {
            this->AnimationsC["PLAYER_WALK"]->play("PLAYER_WALK_UP",deltaTime,modifyPercent.y,0);
        }
        else if(this->moveMentComponent->getMovementState((LEFT)))
        {   
            this->AnimationsC["PLAYER_WALK"]->play("PLAYER_WALK_LEFT",deltaTime,modifyPercent.x,0);
        }
        else if(this->moveMentComponent->getMovementState((DOWN)))
        {
            this->AnimationsC["PLAYER_WALK"]->play("PLAYER_WALK_DOWN",deltaTime,modifyPercent.y,0);
        }
        else if(this->moveMentComponent->getMovementState((RIGHT)))
        {
            this->AnimationsC["PLAYER_WALK"]->play("PLAYER_WALK_RIGHT",deltaTime,modifyPercent.x,0);
        }  
    }
    this->updateArrows(deltaTime);
}

void Player::shoot(const float &deltaTime, sf::Vector2f &Direction)
{
    this->isAttacking=true;
    this->isMoving=false;
    if(this->quiver->canShoot())
    {
        if(Direction.x>0.f && Direction.y<=200.f&& Direction.y>=-200.f)//right
        { 
            this->shootIndex=3; 
        }
        else if(Direction.x<0.f && Direction.y<=200.f&& Direction.y>=-200.f)//left
        { 
            this->shootIndex=1; 
        }
        else if(Direction.y>0.f&& Direction.x<=200.f && Direction.x>=-200.f)//down
        { 
            this->shootIndex=2; 
        }
        else if(Direction.y<0.f && Direction.x<=200.f && Direction.x>=-200.f)//up
        { 
            this->shootIndex=0; 
        }
        this->quiver->shootArrow(Direction);
        this->shootingArrow=true;
    }
}

void Player::updateArrows(const float &deltaTime)
{
    this->quiver->update(deltaTime);
}

void Player::drawArrows(sf::RenderTarget &target)
{
    this->quiver->draw(target);
}

/* void Player::update(sf::Vector2f &playerPosMap, sf::Vector2i &mousePosMap, float deltaTime, Enemy &enemy)
{
    bool isWPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool isSPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool isDPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool isAPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    static float elapsedWTime = 0.f, elapsedSTime = 0.f, elapsedDTime = 0.f, elapsedATime = 0.f;

    elapsedTime += deltaTime;
    if (isWPressed) {
        //Sprite.setTexture(Textures::PlayerWalk); 
        static int frameWIndex = 0;
        elapsedWTime+=deltaTime; 
        if (elapsedWTime >= 0.1f) { 
            elapsedWTime = 0.f;
            frameWIndex++;
            if (frameWIndex > 8) {  
                frameWIndex=0;
            }
            //Sprite.setTextureRect(sf::IntRect(frameWIndex * size.x, 0 * size.y, size.x, size.y));
        }
            
            //Sprite.move(0, -moveSpeed * deltaTime); 
    }
    if (isSPressed) {
        //Sprite.setTexture(Textures::PlayerWalk); 
        static int frameSIndex = 0; 
        elapsedSTime+=deltaTime;
        if(elapsedSTime >= 0.1f) { 
            elapsedSTime = 0.f;
            frameSIndex++;
            if (frameSIndex > 8) { 
                frameSIndex=0;
            }
            Sprite.setTextureRect(sf::IntRect(frameSIndex * size.x, 2 * size.y, size.x, size.y));
        }
        Sprite.move(0, moveSpeed * deltaTime); 
    }
    if (isDPressed) {
        Sprite.setTexture(Textures::PlayerWalk); 
        static int frameDIndex = 0; 
        elapsedDTime+=deltaTime;
        if (elapsedDTime >= 0.1f) { 
            elapsedDTime = 0.f;
            frameDIndex++;
            if (frameDIndex > 8) { 
                frameDIndex = 0;
            }
            Sprite.setTextureRect(sf::IntRect(frameDIndex * size.x, 3 * size.y, size.x, size.y));
        }
        Sprite.move(moveSpeed * deltaTime, 0); 
    }
    if (isAPressed) {
        Sprite.setTexture(Textures::PlayerWalk);
        static int frameAIndex = 0; 
        elapsedATime+=deltaTime;
        if (elapsedATime >= 0.1f) { 
            elapsedATime=0.f;
            frameAIndex++;
            if (frameAIndex > 8) { 
                frameAIndex = 0;
            }
            Sprite.setTextureRect(sf::IntRect(frameAIndex * size.x, 1 * size.y, size.x, size.y));
        }
        Sprite.move(-moveSpeed * deltaTime, 0); 
    }
    //-------------------------------BulletSection-----------------------------------
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!isShooting){
        sf::Vector2f MousePosition = sf::Vector2f(mousePosMap);
        Sprite.setTexture(Textures::PlayerBow);
        Bullet bullet(MousePosition,Sprite.getPosition(),firerRate);
        bullets.push_back(bullet);

        float deltaX=MousePosition.x-Sprite.getPosition().x;
        float deltaY=MousePosition.y-Sprite.getPosition().y;
        if(deltaX>200 && deltaY<=200&& deltaY>=-200){ 
            shootIndex=3; 
        }
        else if(deltaX<-200 && deltaY<=200&& deltaY>=-200){ 
            shootIndex=1; 
        }
        else if(deltaY>200&& deltaX<=200 && deltaX>=-200){ 
            shootIndex=2; 
        }
        if(deltaY<-200 && deltaX<=200 && deltaX>=-200){ 
            shootIndex=0; 
        }
        isShooting = true;
    }    
        
        for (int i=0;i<bullets.size();i++) { 
            bullets[i].move(deltaTime);
            if(bullets[i].GetGlobalBounds().intersects(enemy.Sprite.getGlobalBounds())&& enemy.HealthPoint>0)
            {
                enemy.ChangeHP(10);
                bullets.erase(bullets.begin()+i);
            }
        } 
    //-------------------------------BulletSection-----------------------------------
}*/

/* void Player::draw(sf::RenderWindow& window,float deltaTime){
    for (int i=0;i<bullets.size();i++) {
            bullets[i].draw(window);
        } 
    if(isShooting){
        elapsedTime +=deltaTime;
        if(elapsedTime>=0.1f){
            elapsedTime=0.f;
            frameIndex++;
            if(frameIndex>12){
                frameIndex=0;
                isShooting=false;
            }
        }
        Sprite.setTextureRect(sf::IntRect(frameIndex * size.x, shootIndex * size.y, size.x, size.y));
    }
    window.draw(Sprite);
        
}*/

