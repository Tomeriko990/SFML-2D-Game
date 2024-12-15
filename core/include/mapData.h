#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


typedef struct Tile_E
{
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;

    std::vector<sf::Vector2f> position_Tile_E;
    bool isExit;
    bool isWall;
    bool ispassable;
}Tile;


typedef struct mapdata
{
    int version;

    std::string tileSheet;
    std::string mapName;

    std::vector<sf::Vector2f> door;
    std::vector<sf::Vector2f> wall;
    std::vector<sf::Vector2f> floor;
    std::vector<sf::Vector2f> exit;

    int mapPositionX;
    int mapPositionY;

    int cellSizeX;
    int cellSizeY;

    int totalCellsX;
    int totalCellsY;

    int mapWidth;
    int mapHeight;

    int mapScaleX;
    int mapScaleY;

    int dataNumber;
    int* data;
}MapData;