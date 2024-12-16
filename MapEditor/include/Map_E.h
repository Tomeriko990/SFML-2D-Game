#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Grid.h"
#include <vector>
#include "Tile_E.h"  

class Map_E
{
private:
    Grid& m_grid;                          // Reference to Grid class
    MouseTile& m_mouseTile;                // Reference to MouseTile class
    std::vector<sf::Sprite> m_mapSprites;  // Vector of map sprites (adjusted from pointer to vector)
    std::vector<Tile_E> m_tiles;           // Vector of Tile_E objects for managing map tiles

    int m_mapSize;                         // Size of the map

public:
    // Constructor: Initializes the map with Grid and MouseTile
    Map_E(Grid& grid, MouseTile& mouseTile);
    
    // Update the map (e.g., mouse interactions, tile updates, etc.)
    void update(sf::RenderWindow& window, float deltaTime);
    
    // Draw the map to the window
    void draw(sf::RenderWindow& window);

    // Sorts tiles based on different types (exit, door, wall, floor)
    void sortTiles(std::vector<Tile_E>& tiles, 
                   std::vector<sf::Vector2f>& exit,
                   std::vector<sf::Vector2f>& door,
                   std::vector<sf::Vector2f>& wall,
                   std::vector<sf::Vector2f>& floor);

    // Destructor: Cleans up the map resources
    ~Map_E();
};