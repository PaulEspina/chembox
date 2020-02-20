#pragma once
#include "State.h"

#include "MouseManager.h"
#include "KeyManager.h"
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
	KeyManager key_man;
	sf::RenderWindow *window = NULL;
	Particle **particles;
	Vec2 mouse;
};

