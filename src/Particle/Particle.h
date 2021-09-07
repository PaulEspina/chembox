#pragma once

#include <SFML/Graphics.hpp>

#include "Matter.h"

class Particle : public Matter
{
public:
	Particle();
	Particle(sf::Vector2f pos, sf::Vector2f vel = sf::Vector2f(0, 0), sf::Vector2f acc = sf::Vector2f(0, 0));
	virtual ~Particle();
	virtual void update();
	virtual void render(sf::RenderWindow &window);

private:
	virtual void init(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc);
	static const unsigned int size = 2;
	const char *label;

	sf::RectangleShape rect;
};

