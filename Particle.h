#pragma once

#include "ChemBox.h"

class Particle
{
public:
	// FUNCTIONS
	Particle();
	~Particle();
	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
	void ApplyForce(Vec2 force);
	void ApplyGravity(Vec2 constant);
	void ApplyFriction(float constant);
	void ApplyDrag(float constant);
	// Getters
	bool IsOutside() { return outside; }
	// Setters
	void SetOutside(bool value) { outside = value; }
	// VARIABLES
	static unsigned int particle_count;
	Vec2 pos, vel, accel;
protected:
	// VARIABLES
	sf::RectangleShape particle;
	float mass;
	bool outside;
};

