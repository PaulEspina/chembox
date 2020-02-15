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
		if(event.type == sf::Event::MouseMoved)
		{
			mouse.x = (float) event.mouseMove.x;
			mouse.y = (float) event.mouseMove.y;
		}
		if(event.type == sf::Event::MouseButtonPressed)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				particles.push_back(new Dust(mouse));
			}
		}
	}
	if(!particles.empty())
	{
		for(unsigned int i = 0; i < particles.size(); i++)
		{
			particles[i]->ApplyGravity(Vec2(0, 1));
			particles[i]->ApplyDrag(1);
			particles[i]->Update();
		}
	}
}

void GameState::Render()
{
	window->clear();
	if(!particles.empty())
	{
		for(unsigned int i = 0; i < particles.size(); i++)
		{
			particles[i]->Render(*window);
		}
	}
	window->display();
}

void GameState::CleanUp()
{
	if(!particles.empty())
	{
		for(unsigned int i = 0; i < particles.size(); i++)
		{
			delete particles[i];
		}
	}
}
