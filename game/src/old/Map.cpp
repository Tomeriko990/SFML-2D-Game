#include "Map.h"
#include <iostream>

Map::Map(): TotalTilesX(0),TotalTilesY(0),TotalTiles(0),m_mapData(),m_mapLoader("/Users/tomerantebi/Documents/rpgGame/Map_Level_1.txt",m_mapData),
m_table(nullptr),m_mapSprites(nullptr)
{
    if(m_tileSheetTexture.loadFromFile(m_mapData.tileSheet)&& m_mapData.dataNumber>0)
    {
        std::cout<<"Loaded Succesfaully"<<std::endl;

        TotalTilesX=m_tileSheetTexture.getSize().x/m_mapData.cellSizeX;
        TotalTilesY=m_tileSheetTexture.getSize().y/m_mapData.cellSizeY;

        m_mapLenght.x=m_mapData.mapWidth;
        m_mapLenght.y=m_mapData.mapHeight;
        m_mapPos.x=m_mapData.mapPositionX;
        m_mapPos.y=m_mapData.mapPositionY;
        m_mapSize.x=TotalTilesX;
        m_mapSize.y=TotalTilesY;
        m_tileSize.x=m_mapData.cellSizeX*m_mapData.mapScaleX;
        m_tileSize.y=m_mapData.cellSizeY*m_mapData.mapScaleY;

        m_table=new Tile[TotalTilesX*TotalTilesY];
        m_mapSprites=new sf::Sprite[m_mapData.dataNumber];

        for (int y=0;y<TotalTilesY;y++)
        {
            for(int x=0;x<TotalTilesX;x++)
            {
                int index=x+y*TotalTilesX;
                m_table[index].id=index;
                m_table[index].position.x=m_mapData.cellSizeX*x;
                m_table[index].position.y=m_mapData.cellSizeY*y;
            }
        }

        for (int y=0;y<m_mapData.totalCellsY;y++)
        {
            for(int x=0;x<m_mapData.totalCellsX;x++)
            {
                int index=x+y*m_mapData.totalCellsX;
                int i=m_mapData.data[index];
                std::cout<<"i= "<<i<<std::endl;
                m_mapSprites[index].setTexture(m_tileSheetTexture);
                m_mapSprites[index].setTextureRect(sf::IntRect(m_table[i].position.x,m_table[i].position.y,m_mapData.cellSizeX,m_mapData.cellSizeY));
                m_mapSprites[index].setScale(m_mapData.mapScaleX,m_mapData.mapScaleY);
                m_mapSprites[index].setPosition(m_mapPos+sf::Vector2f(x*m_mapData.cellSizeX*m_mapData.mapScaleX,y*m_mapData.cellSizeY*m_mapData.mapScaleY));
            }
        }
    }
    else if(!m_tileSheetTexture.loadFromFile(m_mapData.tileSheet)) {
    std::cout << "Failed to load texture from: " << m_mapData.tileSheet << std::endl;
    }
   
}

Map::~Map()
{
    delete[] m_mapSprites;
    m_mapSprites = nullptr;
    delete[] m_table;
    m_table = nullptr;
    delete[] m_mapData.data;
    m_mapData.data = nullptr;

}


void Map::draw(sf::RenderWindow &window)
{
    for(int i=0;i<m_mapData.dataNumber;i++)
    {
        window.draw(m_mapSprites[i]);
    }
}

void Map::update(float data_time)
{

}
