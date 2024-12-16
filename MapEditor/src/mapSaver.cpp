#include "mapSaver.h"
#include <fstream>
#include <iostream>

mapSaver::mapSaver(std::string fileName, MapData &mapData)
{
    std::ofstream file;
    file.open(fileName);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    // Write map data
    file << "[Map]" << std::endl;
    file << "tile-sheet=" << mapData.tileSheet << std::endl;
    file << "name=" << mapData.mapName << std::endl;
    file << "version=" << mapData.version << std::endl;
    file << "mapPositionX=" << mapData.mapPositionX << std::endl;
    file << "mapPositionY=" << mapData.mapPositionY << std::endl;
    file << "mapWidth=" << mapData.mapWidth << std::endl;
    file << "mapHeight=" << mapData.mapHeight << std::endl;
    file << "cellSizeX=" << mapData.cellSizeX << std::endl;
    file << "cellSizeY=" << mapData.cellSizeY << std::endl;
    file << "mapScaleX=" << mapData.mapScaleX << std::endl;
    file << "mapScaleY=" << mapData.mapScaleY << std::endl;
    file << "rows=" << mapData.totalCellsX << std::endl;
    file << "cols=" << mapData.totalCellsY << std::endl;

    // Write exit tiles
    file << "exit_tiles_number=" << mapData.exit.size() << std::endl;
    writeTilePositions(file, mapData.exit, mapData.totalCellsX);

    // Write door tiles
    file << "door_tiles_number=" << mapData.door.size() << std::endl;
    writeTilePositions(file, mapData.door, mapData.totalCellsX);

    // Write wall tiles
    file << "wall_tiles_number=" << mapData.wall.size() << std::endl;
    writeTilePositions(file, mapData.wall, mapData.totalCellsX);

    // Write floor tiles
    file << "floor_tiles_number=" << mapData.floor.size() << std::endl;
    writeTilePositions(file, mapData.floor, mapData.totalCellsX);

    // Close the file
    file.close();
}

mapSaver::~mapSaver()
{
    // Destructor doesn't need to do anything for now
}

// Helper function to write tile positions in a formatted way
void mapSaver::writeTilePositions(std::ofstream& file, const std::vector<sf::Vector2i>& tiles, int totalCellsX)
{
    int size = tiles.size();
    file << "tiles=";
    int count = 0;

    for (int i = 0; i < size; i++) {
        count++;
        if (count == totalCellsX) {
            count = 0;
            file << std::endl;
        }
        if (i == size - 1) {
            file << "  " << tiles[i].x << "," << tiles[i].y << ";";
        }
        else {
            file << "  " << tiles[i].x << "," << tiles[i].y;
        }
    }
}
