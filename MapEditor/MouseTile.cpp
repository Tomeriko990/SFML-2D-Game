#include "MouseTile.h"
#include <iostream>


int MouseTile::indexTextures=0;

MouseTile::MouseTile(const sf::Vector2i& totalCells,const sf::Vector2f& offset,const sf::Vector2i& tileSize,
const sf::Vector2i& tileIndex,sf::Vector2i& scale)
:m_cellSize(tileSize),m_scale(scale),m_offset(offset),OnGrid(false),m_tileID(0)
{
    m_numberOfTextures=6;
    files={"Dungeon_tileset","door","floor","wall","exit","morestaff"};
    m_t.resize(m_numberOfTextures*sizeof(Tile_E));

    std::string basePath = "/Users/tomerantebi/Documents/rpgGame/game/Assets/Map/";
    
    for (int i = 0; i < m_numberOfTextures; i++) {

        m_t[i].name=files[i];

        if(m_t[i].name=="door"){m_t[i].isExit=true;m_t[i].isWall=true;m_t[i].ispassable=true;}
        else if(m_t[i].name=="exit"){m_t[i].isExit=true;m_t[i].isWall=false;m_t[i].ispassable=true;}
        else if(m_t[i].name=="wall"){m_t[i].isExit=false;m_t[i].isWall=true;m_t[i].ispassable=false;}
        else if(m_t[i].name=="floor"){m_t[i].isExit=false;m_t[i].isWall=false;m_t[i].ispassable=true;}
        else if(m_t[i].name=="morestaff"){m_t[i].isExit=false;m_t[i].isWall=true;m_t[i].ispassable=false;}

        std::string fullPath = basePath + files[i]+ ".png"; 
        if (!m_t[i].texture.loadFromFile(fullPath)) {
            std::cerr << "Failed to load texture from: " << fullPath << std::endl;
        } else {
            std::cout << "Loaded texture from: " << fullPath << std::endl;
        }
    }

    m_tile.setScale(scale.x,scale.y);
    m_gridBounds=m_offset+sf::Vector2f(m_cellSize.x*m_scale.x*totalCells.x,m_cellSize.y*m_scale.y*totalCells.y);
}

void MouseTile::draw(sf::RenderWindow &window)
{
    window.draw(m_tile);
}

void MouseTile::update(sf::RenderWindow& window,float deltaTime)
{
    bool isUPpressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool isDOWNpressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    sf::Vector2f TextureSIZE(m_t[indexTextures].texture.getSize().x/m_cellSize.x,
    m_t[indexTextures].texture.getSize().y/m_cellSize.y);
    m_textureSize=TextureSIZE;
    m_tile.setTexture(m_t[indexTextures].texture);
    
    sf::Vector2f mouseposition=sf::Vector2f(sf::Mouse::getPosition(window));
    static float timer=0.f;
    timer+=deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&timer>=60.f)
    {
        timer=0.f;
        m_index.x++;
        if(m_index.x>=TextureSIZE.x)
        {
            m_index.x=0;
            m_index.y++;
        }
        if(m_index.y>=TextureSIZE.y){m_index.y=0;}
        m_tile.setTextureRect(sf::IntRect(m_cellSize.x*m_index.x,m_cellSize.y*m_index.y,m_cellSize.x,m_cellSize.y));
    }

    if((isUPpressed||isDOWNpressed) && timer>=60.f)
    {
        timer=0.f;
        if(isUPpressed){indexTextures++;}
        else if(isDOWNpressed){indexTextures--;}

        if(indexTextures>=m_numberOfTextures)
        {
            indexTextures=0;
        }
        if(indexTextures<0){m_index.y=m_numberOfTextures;}
        m_tile.setTextureRect(sf::IntRect(m_cellSize.x*m_index.x,m_cellSize.y*m_index.y,m_cellSize.x,m_cellSize.y));
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&timer>=60.f)
    {
        timer=0.f;
        m_index.x--;
        if(m_index.x<0)
        {
            m_index.x=TextureSIZE.x-1;
            m_index.y--;
        }
        if(m_index.y<0){m_index.y=TextureSIZE.y;}
        m_tile.setTextureRect(sf::IntRect(m_cellSize.x*m_index.x,m_cellSize.y*m_index.y,m_cellSize.x,m_cellSize.y));
    }

    if(mouseposition.x>=m_offset.x&&mouseposition.x<=m_gridBounds.x&&
       mouseposition.y>=m_offset.y&&mouseposition.y<=m_gridBounds.y)
    {
        m_tileGridPosition.x=(mouseposition.x-m_offset.x)/(m_cellSize.x*m_scale.x);
        m_tilePosition.x=m_tileGridPosition.x*(m_cellSize.x* m_scale.x)+m_offset.x;

        m_tileGridPosition.y=(mouseposition.y-m_offset.y)/(m_cellSize.y*m_scale.y);
        m_tilePosition.y=m_tileGridPosition.y*(m_cellSize.y* m_scale.y)+m_offset.y;
        m_tile.setPosition(m_tilePosition.x,m_tilePosition.y);

        OnGrid=true;
    }
    else{OnGrid=false;}
}

bool MouseTile::IsMouseClickOnTile(sf::Vector2i& gridPosition,sf::Vector2f& tilePosition)
{

    if(OnGrid&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        tilePosition=m_tilePosition;
        gridPosition=m_tileGridPosition;
        m_tileID=m_index.x+m_index.y*m_textureSize.x;
        m_t[indexTextures].position_Tile_E.push_back(tilePosition);
        return true;
    }
    return false;
}
