#include "Particle.h"

Particle::Particle()
{
	label = "PARTICLE";
	pos = sf::Vector2f(0, 0);
	vel = sf::Vector2f(0, 0);
	acc = sf::Vector2f(0, 0);
}

Particle::Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc)
{
	label = "PARTICLE";
	this->pos = pos;
	this->vel = vel;
	this->acc = acc;
}

Particle::~Particle()
{
}

void Particle::init()
{
	rect.setSize(sf::Vector2f(size, size));
	rect.setPosition(pos);
	rect.setFillColor(sf::Color::White);
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	rect.setPosition(pos);
}

void Particle::render(sf::RenderWindow &window)
{
	window.draw(rect);
}
