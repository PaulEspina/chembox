#pragma once

#include "Particle.h"

class Wood : public Particle
{
public:
	Wood();
	Wood(Vec2 pos, sf::RenderWindow &window);
	void Update();
	void Render();
private:
};

