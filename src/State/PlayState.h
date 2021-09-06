#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "KeyManager.h"
#include "Particle/Particle.h"

class PlayState : public State
{
public:
	PlayState();
	~PlayState();
	void init(sf::Window &window) override;
	void tick(KeyManager &keyManager) override;
	void update() override;
	void render(sf::RenderWindow &window) override;
private:
	sf::Window *window;
	std::vector<Particle*> particles;
};
