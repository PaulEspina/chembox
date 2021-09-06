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

void PlayState::init()
{
	particles.clear();
}

void PlayState::tick(KeyManager &keyManager, MouseManager &mouseManager)
{
	if(mouseManager.isDown(sf::Mouse::Button::Left))
	{
		particles.push_back(new Particle(sf::Vector2f(mouseManager.getPos())));
	}
	if(keyManager.isPressed(sf::Keyboard::R))
	{
		init();
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
