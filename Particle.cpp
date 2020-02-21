#include "Particle.h"

Particle::Particle()
{
	pos = Vec2(0, 0);
	vel = Vec2(0, 0);
	accel = Vec2(0, 0);
	mass = 1;
	particle_count++;
	particle.setSize(sf::Vector2f(1, 1));
	outside = false;
	window = NULL;
}

Particle::~Particle()
{
	particle_count--;
}

void Particle::ApplyForce(Vec2 force)
{
	force = Vec2(force.x / mass, force.y / mass);
	accel += force;
}

void Particle::ApplyGravity(Vec2 constant)
{
	ApplyForce(Vec2(constant.x * mass, constant.y * mass));
}

void Particle::ApplyFriction(float constant)
{
	if(vel != Vec2(0, 0))
	{
		float mag = sqrt(vel.x * vel.x + vel.y * vel.y);
		ApplyForce(Vec2(constant * -vel.x / mag,
								constant * -vel.y / mag));
	}
}

void Particle::ApplyDrag(float constant)
{
	if(vel != Vec2(0, 0))
	{
		float mag = sqrt(vel.x * vel.x + vel.y * vel.y);
		ApplyForce(Vec2(-constant * vel.x * mag,
								-constant * vel.y * mag));
	}
}

unsigned int Particle::particle_count = 0;