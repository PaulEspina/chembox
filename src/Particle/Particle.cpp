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

unsigned int Particle::getID()
{
	return id;
}

void Particle::init(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc)
{
	label = "PARTICLE";
	setPos(pos);
	setVel(vel);
	setAcc(acc);
}

void Particle::update()
{
	Matter::update();
}

