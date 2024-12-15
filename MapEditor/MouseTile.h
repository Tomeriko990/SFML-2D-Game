#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "mapData.h"



class MouseTile
{
private:
    

    sf::Texture m_tileSheet;
    
    std::vector<Tile_E> m_t;
    std::vector<sf::Texture> m_textures;
    std::vector<std::string> files;

    int m_numberOfTextures;

    sf::Sprite m_tile;
    sf::Vector2i m_index;
    sf::Vector2f m_tileSheetSize;
    sf::Vector2i m_cellSize;
    sf::Vector2i m_scale;
    sf::Vector2f m_offset;
    sf::Vector2f m_textureSize;

    sf::Vector2i m_tileGridPosition;
    sf::Vector2f m_tilePosition;
    sf::Vector2f m_gridBounds;

    int m_tileID;

    bool OnGrid;

public:
    friend class Map_E;
    static int indexTextures;
    
    MouseTile(const sf::Vector2i& totalCells,const sf::Vector2f& offset,const sf::Vector2i& tileSize,const sf::Vector2i& tileIndex,
    sf::Vector2i& scale);

    void draw(sf::RenderWindow& window);

    void update(sf::RenderWindow& window,float deltaTime);

    bool IsMouseClickOnTile(sf::Vector2i& gridPosition,sf::Vector2f& tilePosition);
    inline sf::Sprite& GetSprite(){return m_tile;}
    
};

