#include "Dust.h"

Dust::Dust()
{
	mass = 1;
	particle.setFillColor(sf::Color(255, 221, 128, 255));
}

Dust::Dust(Vec2 pos)
	:
	Dust()
{
	this->pos = pos;
	particle.setPosition(pos.x, pos.y);
}

void Dust::Update()
{
	vel += accel;
	pos += vel;
	accel = Vec2(0, 0);
	if(vel.x * vel.x + vel.y * vel.y < 0.1f)
	{
		vel = Vec2(0, 0);
	}
	particle.setPosition(pos.x, pos.y);
}

void Dust::Render(sf::RenderWindow& window)
{
	window.draw(particle);
}
