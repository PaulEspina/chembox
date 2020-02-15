#pragma once

#include "ChemBox.h"

class State
{
public:
	virtual void Init(sf::RenderWindow&) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void CleanUp() = 0;
};