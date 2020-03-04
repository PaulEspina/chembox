#include "Wood.h"

Wood::Wood()
{
	mass = 1;
	particle.setFillColor(sf::Color(193, 154, 107, 255));
}

Wood::Wood(Vec2 pos, sf::RenderWindow &window)
	:
	Wood()
{
	this->pos = pos;
	this->window = &window;
	particle.setPosition(pos.x, pos.y);
}

void Wood::Update()
{
	particle.setPosition(pos.x, pos.y);
}

void Wood::Render()
{
	window->draw(particle);
}
