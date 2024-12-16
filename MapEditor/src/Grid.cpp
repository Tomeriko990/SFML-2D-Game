#include "Grid.h"

/**
 * @class Grid
 * @brief Represents a 2D grid for rendering and managing tiles.
 */
Grid::Grid(const sf::Vector2f& offset, const sf::Vector2i& totalCells, const sf::Vector2i& cellSize,
           int Thickness, const sf::Vector2i& scale, const sf::Color& color)
    : m_totalCells(totalCells), m_cellSize(cellSize), m_LineThickness(Thickness), m_scale(scale),
      m_color(color), m_position(offset) {
    m_totalLines.x = m_totalCells.x + 1;
    m_totalLines.y = m_totalCells.y + 1;

    m_size.x = m_cellSize.x * m_scale.x * m_totalCells.x + m_LineThickness;
    m_size.y = m_cellSize.y * m_scale.y * m_totalCells.y;

    int horizontalLineLength = m_cellSize.x * m_scale.x * m_totalCells.x + m_LineThickness;
    int verticalLineLength = m_cellSize.y * m_scale.y * m_totalCells.y;

    hline = new sf::RectangleShape[m_totalLines.y];
    vline = new sf::RectangleShape[m_totalLines.x];

    for (int i = 0; i < m_totalLines.y; i++) {
        hline[i].setSize(sf::Vector2f(horizontalLineLength, m_LineThickness));
        hline[i].setPosition(m_position + sf::Vector2f(0, i * m_cellSize.y * m_scale.y));
        hline[i].setFillColor(m_color);
    }
    for (int i = 0; i < m_totalLines.x; i++) {
        vline[i].setSize(sf::Vector2f(m_LineThickness, verticalLineLength));
        vline[i].setPosition(m_position + sf::Vector2f(i * m_cellSize.x * m_scale.x, 0));
        vline[i].setFillColor(m_color);
    }
}

/**
 * @brief Draws the grid on the given window.
 */
void Grid::draw(sf::RenderWindow& window) {
    for (int i = 0; i < m_totalLines.y; i++) {
        window.draw(hline[i]);
    }
    for (int i = 0; i < m_totalLines.x; i++) {
        window.draw(vline[i]);
    }
}

/**
 * @brief Destructor for Grid class. Cleans up allocated resources.
 */
Grid::~Grid() {
    delete[] hline;
    delete[] vline;
}
























