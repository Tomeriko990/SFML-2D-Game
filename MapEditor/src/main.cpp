#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "MouseTile.h"
#include "Map_E.h"
#include "mapData.h"

MapData md; // Consider removing if not used

int main() {
    //----------------------Initialization------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1800, 1600), "Map Editor", sf::Style::Default, settings);
    sf::Clock clock;

    // Grid and Tile Settings
    sf::Vector2f gridPosition(50, 25);
    sf::Vector2i gridScale(5, 5);
    sf::Vector2i totalCells(14, 10);
    sf::Vector2i tileSize(16, 16);

    // Initialize Grid, MouseTile, and Map
    Grid grid(gridPosition, totalCells, tileSize, 2, gridScale, sf::Color(255, 255, 255, 128));
    MouseTile mousetile(totalCells, gridPosition, tileSize, sf::Vector2i(11, 0), gridScale);
    Map_E map(grid, mousetile);
    //----------------------Initialization------------------------------
    
    //-------------------UPDATE-----------------------
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the MouseTile and Map
        mousetile.update(window, deltaTime.asMilliseconds());
        map.update(window, deltaTime.asMilliseconds());
        //-------------------UPDATE-----------------------
    
        // ------------------DRAW-------------------------
        window.clear(sf::Color::Black);  // Clear the window to black
        grid.draw(window);               // Draw the grid
        mousetile.draw(window);          // Draw the mouse tile
        map.draw(window);                // Draw the map
        window.display();                // Display the window
        // ------------------DRAW-------------------------
    }

    return 0;
}
