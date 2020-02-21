#pragma once
#include "Particle.h"
class Dust : public Particle
{
public:
	Dust();
	Dust(Vec2 pos, sf::RenderWindow &window);
	void Update();
	void Render();
private:
};

