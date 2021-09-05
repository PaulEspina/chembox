#pragma once

#include <SFML/Graphics.hpp>

class Particle
{
public:
	Particle();
	Particle(sf::Vector2f pos, sf::Vector2f vel = sf::Vector2f(0, 0), sf::Vector2f acc = sf::Vector2f(0, 0));
	virtual ~Particle();
	virtual void init();
	virtual void update();
	virtual void render(sf::RenderWindow &window);
private:
	static const unsigned int size = 2;
	const char *label;

	sf::RectangleShape rect;
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;
};

