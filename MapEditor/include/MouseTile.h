#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "mapData.h"

// MouseTile class represents a tile selected by the mouse on the grid
class MouseTile
{
private:
    sf::Texture m_tileSheet; // Texture for the tile sheet

    std::vector<Tile_E> m_t; // Vector storing tile data
    std::vector<sf::Texture> m_textures; // Vector holding textures for each tile
    std::vector<std::string> files; // List of file paths for tile textures

    int m_numberOfTextures; // Number of textures available

    sf::Sprite m_tile; // The sprite representing the tile
    sf::Vector2i m_index; // The index of the selected tile on the tile sheet
    sf::Vector2f m_tileSheetSize; // Size of the entire tile sheet
    sf::Vector2i m_cellSize; // Size of each individual tile
    sf::Vector2i m_scale; // Scaling factor for the tile
    sf::Vector2f m_offset; // Offset for positioning the tile
    sf::Vector2f m_textureSize; // Size of the individual tile texture

    sf::Vector2i m_tileGridPosition; // Position of the tile in the grid
    sf::Vector2f m_tilePosition; // Position of the tile in world space
    sf::Vector2f m_gridBounds; // Bounds of the grid

    int m_tileID; // ID for the tile type

    bool OnGrid; // Whether the tile is currently on the grid or not

public:
    friend class Map_E; // Granting Map_E access to private members of MouseTile
    static int indexTextures; // Static variable to keep track of the texture index

    // Constructor to initialize the MouseTile with grid size, offset, and tile properties
    MouseTile(const sf::Vector2i& totalCells, const sf::Vector2f& offset, const sf::Vector2i& tileSize,
              const sf::Vector2i& tileIndex, sf::Vector2i& scale);

    // Function to draw the tile on the window
    void draw(sf::RenderWindow& window);

    // Function to update the tile logic, e.g., handling mouse movement and selection
    void update(sf::RenderWindow& window, float deltaTime);

    // Checks if the mouse click is on a tile, updating the grid position and tile position
    bool IsMouseClickOnTile(sf::Vector2i& gridPosition, sf::Vector2f& tilePosition);

    // Getter function for the tile sprite
    inline sf::Sprite& GetSprite() { return m_tile; }
};