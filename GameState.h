#pragma once
#include "State.h"

#include <vector>

#include "MouseManager.h"
#include "KeyManager.h"
#include "Dust.h"
#include "Wood.h"

class GameState : public State
{
public:
	void Init(sf::RenderWindow &window);
	void Update();
	void Render();
private:
	void CheckBounds();
	MouseManager mouse_man;
	KeyManager key_man;
	sf::RenderWindow *window = NULL;
	std::vector<Particle*> particles;
	//Particle **particles;
	Vec2 mouse;
};

