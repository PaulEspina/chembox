#pragma once
#include "State.h"

#include <vector>

#include "Dust.h"

class GameState : public State
{
public:
	void Init(sf::RenderWindow& window);
	void Update();
	void Render();
	void CleanUp();
private:
	sf::RenderWindow* window = NULL;
	std::vector<Particle*> particles;
	Vec2 mouse;
};

