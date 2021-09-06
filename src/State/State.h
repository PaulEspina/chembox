#pragma once

#include <SFML/Window.hpp>

#include "KeyManager.h"
#include "MouseManager.h"

class State
{
public:
	virtual void init() = 0;
	virtual void tick(KeyManager&, MouseManager&) = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow&) = 0;
private:
};