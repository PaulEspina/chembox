#include "PlayState.h"

PlayState::PlayState()
{
	field = new Field(sf::Vector2f(0, 0), sf::Vector2f(800, 600), sf::Vector2f(2, 2));
}

PlayState::~PlayState()
{
	delete field;
	for(Particle *particle : particles)
	{
		delete particle;
	}
}

void PlayState::init()
{
	field->init();
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
	field->update();
	for(Particle *particle : particles)
	{
		particle->update();
	}
}

void PlayState::render(sf::RenderWindow &window)
{
	field->render(window);
	for(Particle *particle : particles)
	{
		particle->render(window);
	}
}
