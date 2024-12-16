#include "MouseTile.h"
#include <iostream>

int MouseTile::indexTextures = 0;

// Constructor for initializing MouseTile with grid size, offset, and tile properties
MouseTile::MouseTile(const sf::Vector2i& totalCells, const sf::Vector2f& offset, const sf::Vector2i& tileSize,
                     const sf::Vector2i& tileIndex, sf::Vector2i& scale)
    : m_cellSize(tileSize), m_scale(scale), m_offset(offset), OnGrid(false), m_tileID(0)
{
    m_numberOfTextures = 6;  // Number of textures used for different tile types
    files = {"Dungeon_tileset", "door", "floor", "wall", "exit", "morestaff"};  // File names for textures
    m_t.resize(m_numberOfTextures * sizeof(Tile_E));  // Resize vector to hold tile data

    std::string basePath = "/Users/tomerantebi/Documents/rpgGame/game/Assets/Map/";  // Base path for textures

    // Loop through the textures and load them
    for (int i = 0; i < m_numberOfTextures; i++) {
        m_t[i].name = files[i];

        // Set tile properties based on the name
        if (m_t[i].name == "door") {
            m_t[i].isExit = true; m_t[i].isWall = true; m_t[i].ispassable = true;
        } else if (m_t[i].name == "exit") {
            m_t[i].isExit = true; m_t[i].isWall = false; m_t[i].ispassable = true;
        } else if (m_t[i].name == "wall") {
            m_t[i].isExit = false; m_t[i].isWall = true; m_t[i].ispassable = false;
        } else if (m_t[i].name == "floor") {
            m_t[i].isExit = false; m_t[i].isWall = false; m_t[i].ispassable = true;
        } else if (m_t[i].name == "morestaff") {
            m_t[i].isExit = false; m_t[i].isWall = true; m_t[i].ispassable = false;
        }

        // Load the texture from the file
        std::string fullPath = basePath + files[i] + ".png"; 
        if (!m_t[i].texture.loadFromFile(fullPath)) {
            std::cerr << "Failed to load texture from: " << fullPath << std::endl;
        } else {
            std::cout << "Loaded texture from: " << fullPath << std::endl;
        }
    }

    // Set the scale for the tile sprite
    m_tile.setScale(scale.x, scale.y);
    m_gridBounds = m_offset + sf::Vector2f(m_cellSize.x * m_scale.x * totalCells.x, m_cellSize.y * m_scale.y * totalCells.y);
}

// Function to draw the tile on the window
void MouseTile::draw(sf::RenderWindow &window)
{
    window.draw(m_tile);
}

// Function to update the tile state based on keyboard and mouse input
void MouseTile::update(sf::RenderWindow& window, float deltaTime)
{
    bool isUPpressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);  // Check if the UP key is pressed
    bool isDOWNpressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);  // Check if the DOWN key is pressed

    // Get the texture size relative to the cell size
    sf::Vector2f TextureSIZE(m_t[indexTextures].texture.getSize().x / m_cellSize.x, m_t[indexTextures].texture.getSize().y / m_cellSize.y);
    m_textureSize = TextureSIZE;
    m_tile.setTexture(m_t[indexTextures].texture);  // Set the texture for the tile sprite

    // Get the mouse position
    sf::Vector2f mouseposition = sf::Vector2f(sf::Mouse::getPosition(window));

    static float timer = 0.f;  // Timer for handling input delay
    timer += deltaTime;  // Increment the timer based on deltaTime

    // Handle the A key for moving to the next texture in the X direction
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && timer >= 60.f)
    {
        timer = 0.f;
        m_index.x++;  // Move to the next tile in the X direction
        if (m_index.x >= TextureSIZE.x)
        {
            m_index.x = 0;
            m_index.y++;  // Move to the next row of tiles
        }
        if (m_index.y >= TextureSIZE.y) { m_index.y = 0; }
        m_tile.setTextureRect(sf::IntRect(m_cellSize.x * m_index.x, m_cellSize.y * m_index.y, m_cellSize.x, m_cellSize.y));
    }

    // Handle the UP and DOWN arrow keys to change the texture index
    if ((isUPpressed || isDOWNpressed) && timer >= 60.f)
    {
        timer = 0.f;
        if (isUPpressed) { indexTextures++; }  // Increase texture index if UP is pressed
        else if (isDOWNpressed) { indexTextures--; }  // Decrease texture index if DOWN is pressed

        if (indexTextures >= m_numberOfTextures)
        {
            indexTextures = 0;  // Reset to first texture if out of bounds
        }
        if (indexTextures < 0) { m_index.y = m_numberOfTextures; }
        m_tile.setTextureRect(sf::IntRect(m_cellSize.x * m_index.x, m_cellSize.y * m_index.y, m_cellSize.x, m_cellSize.y));
    }

    // Handle the D key for moving to the previous texture in the X direction
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && timer >= 60.f)
    {
        timer = 0.f;
        m_index.x--;  // Move to the previous tile in the X direction
        if (m_index.x < 0)
        {
            m_index.x = TextureSIZE.x - 1;
            m_index.y--;  // Move to the previous row of tiles
        }
        if (m_index.y < 0) { m_index.y = TextureSIZE.y; }
        m_tile.setTextureRect(sf::IntRect(m_cellSize.x * m_index.x, m_cellSize.y * m_index.y, m_cellSize.x, m_cellSize.y));
    }

    // Check if the mouse is within the grid bounds
    if (mouseposition.x >= m_offset.x && mouseposition.x <= m_gridBounds.x &&
        mouseposition.y >= m_offset.y && mouseposition.y <= m_gridBounds.y)
    {
        m_tileGridPosition.x = (mouseposition.x - m_offset.x) / (m_cellSize.x * m_scale.x);  // Calculate the grid X position
        m_tilePosition.x = m_tileGridPosition.x * (m_cellSize.x * m_scale.x) + m_offset.x;  // Calculate the world X position

        m_tileGridPosition.y = (mouseposition.y - m_offset.y) / (m_cellSize.y * m_scale.y);  // Calculate the grid Y position
        m_tilePosition.y = m_tileGridPosition.y * (m_cellSize.y * m_scale.y) + m_offset.y;  // Calculate the world Y position

        m_tile.setPosition(m_tilePosition.x, m_tilePosition.y);  // Update the position of the tile sprite

        OnGrid = true;  // Tile is within the grid bounds
    }
    else { OnGrid = false; }  // Tile is outside the grid bounds
}

// Function to check if a mouse click is on a tile
bool MouseTile::IsMouseClickOnTile(sf::Vector2i& gridPosition, sf::Vector2f& tilePosition)
{
    // If the tile is on the grid and the left mouse button is pressed
    if (OnGrid && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        tilePosition = m_tilePosition;  // Set the clicked tile position
        gridPosition = m_tileGridPosition;  // Set the clicked grid position
        m_tileID = m_index.x + m_index.y * m_textureSize.x;  // Calculate the tile ID based on texture index

        m_t[indexTextures].position_Tile_E.push_back(tilePosition);  // Add the tile position to the list
        return true;  // Return true, indicating a successful click
    }
    return false;  // Return false if no tile was clicked
}
