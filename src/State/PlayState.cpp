#include "PlayState.h"

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

void PlayState::tick(KeyManager &keyManager, MouseManager &mouseManager)
{
	/*if(keyManager.isDown(sf::Keyboard::W))
	{
		particles.push_back(new Particle(sf::Vector2f(sf::Mouse::getPosition(*window))));
	}*/
	if(mouseManager.isDown(sf::Mouse::Button::Left))
	{
		particles.push_back(new Particle(sf::Vector2f(sf::Mouse::getPosition(*window))));
	}
	if(keyManager.isPressed(sf::Keyboard::R))
	{
		init(*window);
	}
}

void PlayState::update()
{
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
