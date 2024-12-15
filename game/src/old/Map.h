#pragma once
#include <SFML/Graphics.hpp>
#include "MapLoader.h"

typedef struct Tile
{
    sf::Vector2i position;
    sf::Sprite sprite;
    int id=-1;
    bool isExit;
    bool isWall;
}Tile;


class Map
{
private:
    sf::Texture m_tileSheetTexture;

    Tile* m_table;
    sf::Sprite* m_mapSprites;

    MapData m_mapData;
    MapLoader m_mapLoader;

    sf::Vector2f m_mapPos;
    sf::Vector2i m_mapSize;
    sf::Vector2i m_tileSize;
    sf::Vector2f m_mapLenght;
    

    int TotalTiles;
    int TotalTilesX;
    int TotalTilesY;

public:
    Map();
    ~Map();
    void draw(sf::RenderWindow &window);
    void update(float data_time);
    inline sf::Vector2f& GetMapPos(){return m_mapPos;}
    inline sf::Vector2i& GetMapSize(){return m_mapSize;}
    inline sf::Vector2i& GetTileSize(){return m_tileSize;}
    inline sf::Vector2f& GetMapLen(){return m_mapLenght;}
   
};


