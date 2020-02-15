#pragma once
#include "State.h"
class GameState : public State
{
public:
	void Init(sf::RenderWindow& window);
	void Update();
	void Render();
	void CleanUp();
private:
	sf::RenderWindow& window;
};

