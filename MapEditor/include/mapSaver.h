#pragma once
#include <SFML/Graphics.hpp>
#include "mapData.h"
#include <string>
#include <fstream>
#include <sstream>

class mapSaver
{
public:
    mapSaver(std::string fileName, MapData& mapData);
    ~mapSaver();

    // Method to save map data to a file
    void saveMapDataToFile();

private:
    std::string m_fileName;
    MapData& m_mapData;
};

mapSaver::mapSaver(std::string fileName, MapData& mapData)
    : m_fileName(fileName), m_mapData(mapData)
{
    // Constructor can be used to initialize data or log actions
    saveMapDataToFile();  // Example: Automatically save map data when the object is created
}

mapSaver::~mapSaver()
{
    // Destructor can be used to clean up or finalize actions
    // Here, no specific cleanup is necessary, but you could log that the object was destroyed.
}

void mapSaver::saveMapDataToFile()
{
    // Open the file stream in write mode
    std::ofstream outFile(m_fileName);

    // Check if file was opened successfully
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open file for saving map data!" << std::endl;
        return;
    }

    // Write map data to the file
    // Assuming MapData has relevant methods to extract the data
    outFile << "Tile Width: " << m_mapData.getTileWidth() << std::endl;
    outFile << "Tile Height: " << m_mapData.getTileHeight() << std::endl;
    outFile << "Rows: " << m_mapData.getRows() << std::endl;
    outFile << "Columns: " << m_mapData.getColumns() << std::endl;

    // Add more map data as needed, depending on what your MapData class contains

    // Close the file
    outFile.close();
}




