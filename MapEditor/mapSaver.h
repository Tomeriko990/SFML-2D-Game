#pragma once
#include <SFML/Graphics.hpp>
#include "mapData.h"
#include <string>

class mapSaver
{
public:
    mapSaver(std::string fileName,MapData& mapData);
    ~mapSaver();
};


