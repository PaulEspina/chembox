#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"

class PlayState : public State
{
public:
	PlayState();
	~PlayState();
	void init() override;
	void tick(sf::Event &event) override;
	void update() override;
	void render(sf::RenderWindow &window) override;
private:
};
