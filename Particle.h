#pragma once

#include "ChemBox.h"

class Particle
{
public:
	Particle();
	virtual void Update() = 0;
	virtual void Render() = 0;
	void ApplyForce(Vec2 force);
	void ApplyGravity(Vec2 constant);
	void ApplyFriction(float constant);
	void ApplyDrag(float constant);
	static unsigned int particle_count;
private:
	Vec2 pos, vel, accel;
	float mass;
};

