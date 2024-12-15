#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Grid.h"
#include <vector>


class Map_E
{
private:

    Grid& m_grid;
    MouseTile& m_mouseTile;
    sf::Sprite* m_mapSprites;
    std::vector<Tile_E> m_tiles;

    int* m_mapID;
    int m_mapSize;

public:
    Map_E(Grid& Grid,MouseTile& mouseTile);
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window,float deltaTime);
    void sortTiles(std::vector<Tile_E>& tiles, std::vector<sf::Vector2f>& exit,std::vector<sf::Vector2f>& door
    ,std::vector<sf::Vector2f>& wall,std::vector<sf::Vector2f>& floor);
    ~Map_E();
};


