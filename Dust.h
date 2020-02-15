#pragma once
#include "Particle.h"
class Dust : public Particle
{
public:
	Dust();
	Dust(Vec2 pos);
	void Update();
	void Render(sf::RenderWindow& window);
};

