#include "PlayState.h"

#include <iostream>

PlayState::PlayState()
{
}

PlayState::~PlayState()
{
	for(Particle *particle : particles)
	{
		delete particle;
	}
}

void PlayState::init(sf::Window &window)
{
	this->window = &window;
	particles.clear();
}

void PlayState::tick(sf::Event &event)
{
	if(event.type == sf::Event::MouseButtonPressed)
	{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			particles.push_back(new Particle(sf::Vector2f(sf::Mouse::getPosition(*window))));
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			init(*window);
		}
	}
}

void PlayState::update()
{
	std::cout << particles.size() << std::endl;
	for(Particle *particle : particles)
	{
		particle->update();
	}
}

void PlayState::render(sf::RenderWindow &window)
{
	for(Particle *particle : particles)
	{
		particle->render(window);
	}
}
