#include "Field.h"


Field::Field()
{
    create(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(0, 0));
}

Field::Field(sf::Vector2f pos, sf::Vector2f rectSize, sf::Vector2f cellSize)
{
    create(pos, rectSize, cellSize);
}

void Field::create(sf::Vector2f pos, sf::Vector2f rectSize, sf::Vector2f cellSize)
{
    this->pos = pos;
    this->rectSize = rectSize;
    this->dimension = sf::Vector2u(rectSize.x / cellSize.x, rectSize.y / cellSize.y);
    this->cellSize = cellSize;
    rect.setPosition(pos);
    rect.setSize(rectSize);
    rect.setFillColor(sf::Color(0, 0, 0, 0));
    for(unsigned int i = 0; i < dimension.y; i++)
    {
        std::vector<char> row;
        for(unsigned int j = 0; j < dimension.x; j++)
        {
            row.push_back('0');
            sf::RectangleShape cell(cellSize);
            cell.setPosition(pos + sf::Vector2f(i * cellSize.x, j * cellSize.y));
            cell.setFillColor(sf::Color(0, 0, 0, 0));
            cellRects.push_back(cell);
        }
        particleField.push_back(row);
    }
}

void Field::init()
{
    for(unsigned int i = 0; i < dimension.y; i++)
    {
        std::fill(particleField[i].begin(), particleField[i].end(), '0');
    }
}

void Field::update()
{
}

void Field::render(sf::RenderWindow &window)
{
    window.draw(rect);
    for(unsigned int i = 0; i < cellRects.size(); i++)
    {
        if(particleField[i / dimension.x][i % dimension.x] != '0')
        {
            window.draw(cellRects[i]);
        }
    }
}
