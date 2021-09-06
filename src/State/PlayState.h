#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Particle/Particle.h"

class PlayState : public State
{
public:
	PlayState();
	~PlayState();
	void init() override;
	void tick(KeyManager &keyManager, MouseManager &mouseManager) override;
	void update() override;
	void render(sf::RenderWindow &window) override;
private:
	std::vector<Particle*> particles;
};
