#pragma once

#include "ChemBox.h"

class Particle
{
public:
	Particle();
	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow&) = 0;
	void ApplyForce(Vec2 force);
	void ApplyGravity(Vec2 constant);
	void ApplyFriction(float constant);
	void ApplyDrag(float constant);
	static unsigned int particle_count;
protected:
	sf::RectangleShape particle;
	Vec2 pos, vel, accel;
	float mass;
};

