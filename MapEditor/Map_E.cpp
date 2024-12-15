#include "Map_E.h"
#include "mapData.h"
#include "mapSaver.h"

Map_E::Map_E(Grid& Grid,MouseTile &mouseTile):
m_grid(Grid),m_mouseTile(mouseTile),m_mapID(nullptr)
{
    m_mapSize=m_grid.m_totalCells.x*m_grid.m_totalCells.y;
    m_mapSprites=new sf::Sprite[m_mapSize];
    m_mapID=new int[m_mapSize];
    m_tiles.resize(m_mapSize*sizeof(Tile_E));
    memset(m_mapID,0,sizeof(int)*m_mapSize);
    
}

void Map_E::draw(sf::RenderWindow &window)
{
    for(int i=0;i<m_mapSize;i++)
    {
        window.draw(m_tiles[i].sprite);
    }
}

void Map_E::update(sf::RenderWindow& window,float deltaTime){
    
    static float timer=0.f;
    timer+=deltaTime;

    sf::Vector2f tilePosition;
    sf::Vector2i gridPosition;
    sf::Vector2f mouseposition=sf::Vector2f(sf::Mouse::getPosition(window));
    

    if(m_mouseTile.IsMouseClickOnTile(gridPosition,tilePosition))
    {
        int index=gridPosition.x+gridPosition.y*m_grid.m_totalCells.x;
        //m_mapID[index]=m_mouseTile.m_tileID;
        m_tiles[index].sprite=m_mouseTile.GetSprite();
        m_tiles[index].position_Tile_E.push_back(tilePosition);
        //m_mapSprites[index]=m_mouseTile.GetSprite();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && timer>=100.f)
    {
        timer=0.f;
        std::vector<sf::Vector2f> exit;
        std::vector<sf::Vector2f> door;
        std::vector<sf::Vector2f> wall;
        std::vector<sf::Vector2f> floor;
        sortTiles(m_tiles,exit,door,wall,floor);


        MapData mapdata;

        mapdata.version=1;
        mapdata.tileSheet="/Users/tomerantebi/Documents/rpgGame/game/Assets/Map/Dungeon_tileset.png";
        mapdata.mapName="Level 1";
        
        mapdata.exit=exit;
        mapdata.door=door;
        mapdata.wall=wall;
        mapdata.floor=floor;

        mapdata.mapPositionX=m_grid.m_position.x;
        mapdata.mapPositionY=m_grid.m_position.y;
        mapdata.cellSizeX=m_grid.m_cellSize.x;
        mapdata.cellSizeY=m_grid.m_cellSize.y;
        mapdata.totalCellsX=m_grid.m_totalCells.x;
        mapdata.totalCellsY=m_grid.m_totalCells.y;
        mapdata.mapWidth=m_grid.m_size.x;
        mapdata.mapHeight=m_grid.m_size.y;
        mapdata.mapScaleX=m_grid.m_scale.x;
        mapdata.mapScaleY=m_grid.m_scale.y;
        //mapdata.dataNumber=m_mapSize;
        mapdata.data=m_mapID;


        
        mapSaver save(std::string("Map_Level_1.txt"),mapdata);
    }  
}

void Map_E::sortTiles(std::vector<Tile_E> &tiles, std::vector<sf::Vector2f> &exit, 
std::vector<sf::Vector2f> &door, std::vector<sf::Vector2f> &wall,std::vector<sf::Vector2f>& floor)
{   
    int size=tiles.size();

    for(int i=0;i<size;i++)
    {
        
        if(tiles[i].name=="exit")
        {
            exit=tiles[i].position_Tile_E;
        }

        else if(tiles[i].name=="door")
        {
            door=tiles[i].position_Tile_E;
        }

        else if(tiles[i].name=="wall")
        {
            wall=tiles[i].position_Tile_E;
        }

        else if(tiles[i].name=="floor")
        {
            floor=tiles[i].position_Tile_E;
        }
    }

}

Map_E::~Map_E()
{
    delete [] m_mapSprites;
}
