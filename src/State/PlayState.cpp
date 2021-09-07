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
	field->init(particles);
	particles.clear();
}

void PlayState::tick(KeyManager &keyManager, MouseManager &mouseManager)
{
	if(mouseManager.isDown(sf::Mouse::Button::Left))
	{
		sf::Vector2f pos(mouseManager.getPos().x / field->getCellSize().x, mouseManager.getPos().y / field->getCellSize().y);
		Particle *particle = new Particle(pos);
		particles.push_back(particle);
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
}
