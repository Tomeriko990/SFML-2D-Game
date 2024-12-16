#include "Map_E.h"
#include "mapData.h"
#include "mapSaver.h"

// Constructor initializes the map size and allocates memory for map sprites and IDs
Map_E::Map_E(Grid& Grid, MouseTile& mouseTile)
    : m_grid(Grid), m_mouseTile(mouseTile)
{
    m_mapSize = m_grid.m_totalCells.x * m_grid.m_totalCells.y; // Calculate total map size
    m_mapSprites.resize(m_mapSize);  // Resize the sprite vector
    m_mapID.resize(m_mapSize, 0);    // Resize and initialize map IDs to 0
    m_tiles.resize(m_mapSize);       // Resize the tiles vector
}

// Draws the tiles on the window
void Map_E::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < m_mapSize; i++)
    {
        window.draw(m_tiles[i].sprite); // Draw each tile's sprite
    }
}

// Updates the map based on user input and tile interactions
void Map_E::update(sf::RenderWindow& window, float deltaTime)
{
    static float timer = 0.f;
    timer += deltaTime; // Increment the timer by deltaTime

    sf::Vector2f tilePosition;
    sf::Vector2i gridPosition;
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

    if (m_mouseTile.IsMouseClickOnTile(gridPosition, tilePosition))
    {
        int index = gridPosition.x + gridPosition.y * m_grid.m_totalCells.x;
        m_tiles[index].sprite = m_mouseTile.GetSprite(); // Update the tile sprite
        m_tiles[index].position_Tile_E.push_back(tilePosition); // Store the tile's position
    }

    // When Enter is pressed, save the map after sorting the tiles
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timer >= 100.f)
    {
        timer = 0.f;
        std::vector<sf::Vector2f> exit, door, wall, floor;
        sortTiles(m_tiles, exit, door, wall, floor);

        // Prepare map data to be saved
        MapData mapData;
        mapData.version = 1;
        mapData.tileSheet = "/Users/tomerantebi/Documents/rpgGame/game/Assets/Map/Dungeon_tileset.png";
        mapData.mapName = "Level 1";
        mapData.exit = exit;
        mapData.door = door;
        mapData.wall = wall;
        mapData.floor = floor;

        mapData.mapPositionX = m_grid.m_position.x;
        mapData.mapPositionY = m_grid.m_position.y;
        mapData.cellSizeX = m_grid.m_cellSize.x;
        mapData.cellSizeY = m_grid.m_cellSize.y;
        mapData.totalCellsX = m_grid.m_totalCells.x;
        mapData.totalCellsY = m_grid.m_totalCells.y;
        mapData.mapWidth = m_grid.m_size.x;
        mapData.mapHeight = m_grid.m_size.y;
        mapData.mapScaleX = m_grid.m_scale.x;
        mapData.mapScaleY = m_grid.m_scale.y;
        mapData.data = m_mapID;

        mapSaver save("Map_Level_1.txt", mapData); // Save the map data to a file
    }
}

// Sorts tiles by type and stores them in corresponding vectors
void Map_E::sortTiles(std::vector<Tile_E>& tiles, std::vector<sf::Vector2f>& exit,
    std::vector<sf::Vector2f>& door, std::vector<sf::Vector2f>& wall, std::vector<sf::Vector2f>& floor)
{
    for (auto& tile : tiles)
    {
        if (tile.name == "exit") exit = tile.position_Tile_E;
        else if (tile.name == "door") door = tile.position_Tile_E;
        else if (tile.name == "wall") wall = tile.position_Tile_E;
        else if (tile.name == "floor") floor = tile.position_Tile_E;
    }
}

// Destructor cleans up memory for map sprites and IDs
Map_E::~Map_E()
{
    // No need to manually delete m_mapSprites and m_mapID if using std::vector
    // std::vector will automatically manage memory cleanup.
}
