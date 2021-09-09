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
        std::vector<unsigned int> row;
        for(unsigned int j = 0; j < dimension.x; j++)
        {
            row.push_back(0);
            sf::RectangleShape cell(cellSize);
            cell.setPosition(pos + sf::Vector2f(j * cellSize.x, i * cellSize.y));
            cell.setFillColor(sf::Color(0, 0, 0, 0));
            cellRects.push_back(cell);
        }
        particleField.push_back(row);
    }
}

void Field::init(std::vector<Particle *> &particles)
{
    this->particles = &particles;
    for(unsigned int i = 0; i < dimension.y; i++)
    {
        std::fill(particleField[i].begin(), particleField[i].end(), 0);
    }
}

void Field::update()
{
    for(unsigned int i = 0; i < dimension.y; i++)
    {
        std::fill(particleField[i].begin(), particleField[i].end(), 0);
    }
    for(Particle *particle : *particles)
    {
        particleField[(int) particle->getPos().y][(int) particle->getPos().x] = particle->getID();
    }
    for(unsigned int i = 0; i < particleField.size(); i++)
    {
        for(unsigned int j = 0; j < particleField[i].size(); j++)
        {
            switch(particleField[i][j])
            {
            /*case 0:
                cellRects[i * particleField[i].size() + j].setFillColor(sf::Color(0, 0, 0, 0));*/
            case 1:
                cellRects[i * particleField[i].size() + j].setFillColor(sf::Color::White);
            }
        }
    }
}

void Field::render(sf::RenderWindow &window)
{
    window.draw(rect);
    for(Particle *particle : *particles)
    {
        window.draw(cellRects[(int) particle->getPos().y * dimension.x + (int) particle->getPos().x]);
    }
}

sf::Vector2f Field::getPos()
{
    return pos;
}

sf::Vector2f Field::getRectSize()
{
    return rectSize;
}

sf::Vector2u Field::getDimension()
{
    return dimension;
}

sf::Vector2f Field::getCellSize()
{
    return cellSize;
}

void Field::setPos(sf::Vector2f pos)
{
    this->pos = pos;
}

void Field::setRectSize(sf::Vector2f rectSize)
{
    this->rectSize = rectSize;
}

void Field::setDimension(sf::Vector2u dimension)
{
    this->dimension = dimension;
}

void Field::setCellSize(sf::Vector2f cellSize)
{
    this->cellSize = cellSize;
}
