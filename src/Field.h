#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <algorithm>

class Field
{
public:
    Field();
    Field(sf::Vector2f pos, sf::Vector2f rectSize, sf::Vector2f cellSize);
    void init();
    void update();
    void render(sf::RenderWindow &window);
private:
    void create(sf::Vector2f pos, sf::Vector2f rectSize, sf::Vector2f cellSize);
    
    sf::Vector2f pos;
    sf::Vector2f rectSize;
    sf::Vector2u dimension;
    sf::Vector2f cellSize;
    std::vector<std::vector<char>> particleField;
    sf::RectangleShape rect;
    std::vector<sf::RectangleShape> cellRects;
};

