#include "mapSaver.h"
#include <fstream>

mapSaver::mapSaver(std::string fileName, MapData &mapData)
{
    std::ofstream file;
    file.open(fileName);

    file<<"[Map]"<<std::endl;
    file<<"tile-sheet="<<mapData.tileSheet<<std::endl;
    file<<"name="<<mapData.mapName<<std::endl;

    

    file<<"version="<<mapData.version<<std::endl;

    file<<"mapPositionX="<<mapData.mapPositionX<<std::endl;
    file<<"mapPositionY="<<mapData.mapPositionY<<std::endl;

    file<<"mapWidth="<<mapData.mapWidth<<std::endl;
    file<<"mapHeight="<<mapData.mapHeight<<std::endl;

    file<<"cellSizeX="<<mapData.cellSizeX<<std::endl;
    file<<"cellSizeY="<<mapData.cellSizeY<<std::endl;

    file<<"mapScaleX="<<mapData.mapScaleX<<std::endl;
    file<<"mapScaleY="<<mapData.mapScaleY<<std::endl;

    file<<"rows="<<mapData.totalCellsX<<std::endl;
    file<<"cols="<<mapData.totalCellsY<<std::endl;

    file<<"exit_tiles_number="<<mapData.exit.size()<<std::endl;
    int size=mapData.exit.size();

    file<<"exit_tiles=";
    int count=0;
    for(int i=0;i<size;i++)
    {   
        count++;
        
        if(count==mapData.totalCellsX)
        {
            count=0;
            file<<std::endl;
        }

        if(i==size-1){file<<"  "<<mapData.exit[i].x<<","<<mapData.exit[i].y<<";";}

        else{file<<"  "<<mapData.exit[i].x<<","<<mapData.exit[i].y; }  
    }

    file<<"door_tiles_number="<<mapData.door.size()<<std::endl;
    size=mapData.exit.size();

    file<<"door_tiles=";
    count=0;
    for(int i=0;i<size;i++)
    {   
        count++;
        
        if(count==mapData.totalCellsX)
        {
            count=0;
            file<<std::endl;
        }

        if(i==size-1){file<<"  "<<mapData.door[i].x<<","<<mapData.door[i].y<<";";}

        else{file<<"  "<<mapData.door[i].x<<","<<mapData.door[i].y; }  
    }


    file<<"wall_tiles_number="<<mapData.exit.size()<<std::endl;
    size=mapData.wall.size();

    file<<"wall_tiles=";
    count=0;
    for(int i=0;i<size;i++)
    {   
        count++;
        
        if(count==mapData.totalCellsX)
        {
            count=0;
            file<<std::endl;
        }

        if(i==size-1){file<<"  "<<mapData.wall[i].x<<","<<mapData.wall[i].y<<";";}

        else{file<<"  "<<mapData.wall[i].x<<","<<mapData.wall[i].y; }  
    }


    file<<"floor_tiles_number="<<mapData.floor.size()<<std::endl;
    size=mapData.exit.size();

    file<<"floor_tiles=";
    count=0;
    for(int i=0;i<size;i++)
    {   
        count++;
        
        if(count==mapData.totalCellsX)
        {
            count=0;
            file<<std::endl;
        }

        if(i==size-1){file<<"  "<<mapData.floor[i].x<<","<<mapData.floor[i].y<<";";}

        else{file<<"  "<<mapData.floor[i].x<<","<<mapData.floor[i].y; }  
    }



    file.close();
}

mapSaver::~mapSaver()
{
}
