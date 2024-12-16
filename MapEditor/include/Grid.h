#pragma once
#include <SFML/Graphics.hpp>

// Grid class for managing and rendering a grid of cells
class Grid  
{
private:
    sf::RectangleShape* vline;           // Pointer to vertical line shape
    sf::RectangleShape* hline;           // Pointer to horizontal line shape
   
    sf::Vector2f m_size;                // Size of the grid
    sf::Vector2f m_position;            // Position of the grid on the screen
    sf::Vector2f m_cellSize;            // Size of a single cell in the grid
    sf::Vector2i m_totalCells;          // Total number of cells in the grid (rows and columns)
    sf::Vector2i m_totalLines;          // Total number of lines (rows and columns)
    sf::Vector2i m_scale;               // Scaling factor for the grid
    sf::Color m_color;                  // Color of the grid lines

    int m_LineThickness;                // Line thickness for the grid lines

public:
    // Allow access to private members by the Map_E class
    friend class Map_E;

    // Constructor to initialize the grid with specific parameters
    Grid(const sf::Vector2f& offset, const sf::Vector2i& totalCells, const sf::Vector2i& cellSize, int Thickness,
         const sf::Vector2i& scale, const sf::Color& color);

    // Function to draw the grid on the window
    void draw(sf::RenderWindow& window);

    // Function to update the grid (e.g., for scaling or repositioning)
    void update();

    // Inline getter functions for grid properties
    inline sf::Vector2i& GetTotalCells() { return m_totalCells; }
    inline sf::Vector2f& GetPosition() { return m_position; }
    inline sf::Vector2f GetSize() { return m_size; }

    // Destructor to clean up dynamically allocated memory (if necessary)
    ~Grid();
};
