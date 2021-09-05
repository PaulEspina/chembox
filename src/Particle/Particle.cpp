#include "Particle.h"

Particle::Particle()
{
	init(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(0, 0));
}

Particle::Particle(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc)
{
	init(pos, vel, acc);
}

Particle::~Particle()
{
}

void Particle::init(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc)
{
	label = "PARTICLE";
	this->pos = pos;
	this->vel = vel;
	this->acc = acc;
	rect.setSize(sf::Vector2f(size, size));
	rect.setPosition(pos);
	rect.setFillColor(sf::Color::White);
}

void Particle::update()
{
	vel += acc;
	pos += vel;
}

void Particle::render(sf::RenderWindow &window)
{
	window.draw(rect);
}

