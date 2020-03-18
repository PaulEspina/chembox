#pragma once

#include "ChemBox.h"

class Particle
{
public:
	// FUNCTIONS
	Particle();
	virtual void Update() = 0;
	virtual void Render() = 0;
	void ApplyForce(Vec2 force);
	void ApplyGravity(Vec2 constant);
	void ApplyFriction(float constant);
	void ApplyDrag(float constant);
	// Getters
	bool IsOutside() { return outside; }
	// Setters
	void SetOutside(bool value) { outside = value; }
	// VARIABLES
	Vec2 pos, vel, accel;
protected:
	// VARIABLES
	sf::RectangleShape particle;
	float mass;
	bool outside;
	sf::RenderWindow *window;
};

