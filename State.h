#pragma once

#include <SFML/Graphics.hpp>

class State
{
public:
	virtual void Init(sf::RenderWindow&) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void CleanUp() = 0;
};