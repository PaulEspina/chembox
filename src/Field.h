#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

#include "Particle/Particle.h"

class Field
{
public:
    Field();
    Field(sf::Vector2f pos, sf::Vector2f rectSize, sf::Vector2f cellSize);
    void init(std::vector<Particle*> &particles);
    void update();
    void render(sf::RenderWindow &window);
    
    // Getters
    sf::Vector2f getPos();
    sf::Vector2f getRectSize();
    sf::Vector2u getDimension();
    sf::Vector2f getCellSize();
    // Setters
    void setPos(sf::Vector2f pos);
    void setRectSize(sf::Vector2f rectSize);
    void setDimension(sf::Vector2u dimension);
    void setCellSize(sf::Vector2f cellSize);

private:
    void create(sf::Vector2f pos, sf::Vector2f rectSize, sf::Vector2f cellSize);
    
    sf::Vector2f pos;
    sf::Vector2f rectSize;
    sf::Vector2u dimension;
    sf::Vector2f cellSize;
    std::vector<std::vector<unsigned int>> particleField;
    sf::RectangleShape rect;
    std::vector<sf::RectangleShape> cellRects;
    std::vector<Particle*> *particles;
};

