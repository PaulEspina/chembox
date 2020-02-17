#pragma once
#include "State.h"

#include "MouseManager.h"
#include "Dust.h"

class GameState : public State
{
public:
	void Init(sf::RenderWindow &window);
	void Update();
	void Render();
	void CleanUp();
private:
	void CheckBounds();
	MouseManager mouse_man;
	sf::RenderWindow *window = NULL;
	Particle **particles;
	Vec2 mouse;
};

