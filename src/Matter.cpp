#include "Matter.h"

void Matter::update()
{
    vel += acc;
    pos += vel;
}

sf::Vector2f Matter::getPos()
{
    return pos;
}

sf::Vector2f Matter::getVel()
{
    return vel;
}

sf::Vector2f Matter::getAcc()
{
    return acc;
}

void Matter::setPos(sf::Vector2f pos)
{
    this->pos = pos;
}

void Matter::setVel(sf::Vector2f vel)
{
    this->vel = vel;
}

void Matter::setAcc(sf::Vector2f acc)
{
    this->acc = acc;
}
