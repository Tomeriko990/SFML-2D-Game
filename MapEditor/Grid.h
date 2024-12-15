#pragma once
#include <SFML/Graphics.hpp>
class Grid  
{
private:
    sf::RectangleShape* vline;
    sf::RectangleShape* hline;
   
    sf::Vector2f m_size;
    sf::Vector2f m_position;
    sf::Vector2f m_cellSize;
    sf::Vector2i m_totalCells;
    sf::Vector2i m_totalLines;
    sf::Vector2i m_scale;
    sf::Color m_color;

    int m_LineThickness;

public:
    friend class Map_E;

    Grid(const sf::Vector2f& offset,const sf::Vector2i& totalCells,const sf::Vector2i& cellSize,int Thickness,
    const sf::Vector2i& scale,const sf::Color& color);
    void draw(sf::RenderWindow& window);
    void update();

    inline sf::Vector2i& GetTotalCells(){return m_totalCells;}
    inline sf::Vector2f& GetPosition(){return m_position;}
    inline sf::Vector2f GetSize(){return m_size;}
    ~Grid();
};


