#pragma once

#include <SFML/Window.hpp>

class State
{
public:
	virtual void init(sf::Window &window) = 0;
	virtual void tick(sf::Event&) = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow&) = 0;
private:
};