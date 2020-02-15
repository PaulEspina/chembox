#include "GameState.h"

void GameState::Init(sf::RenderWindow& window)
{
	this->window = &window;
}

void GameState::Update()
{
	sf::Event event;
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window->close();
	}
}

void GameState::Render()
{
	window->clear();

	window->display();
}

void GameState::CleanUp()
{
}
