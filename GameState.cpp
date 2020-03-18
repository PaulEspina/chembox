#include "GameState.h"

void GameState::Init(sf::RenderWindow& window)
{
	this->window = &window;
	mouse_man = MouseManager();
	key_man = KeyManager();
}

void GameState::Update()
{
	sf::Event event;
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window->close();
		mouse = mouse_man.Update(event);
		key_man.Update(event);
	}
	if(mouse_man.ButtonDown(sf::Mouse::Left))
	{
		particles.push_back(new Dust(mouse, *window));
		/*Particle *particle = new Wood(mouse, *window);
		Particle **temp = new Particle*[Particle::particle_count];
		for(unsigned int i = 0; i < Particle::particle_count - 1; i++)
		{
			temp[i] = particles[i];
		}
		temp[Particle::particle_count - 1] = particle;
		delete[] particles;
		particles = temp;*/
	}
	if(mouse_man.ButtonDown(sf::Mouse::Right))
	{
		
	}
	if(!particles.empty())
	{
		for(auto i = 0; (unsigned int) i < particles.size(); i++)
		{
			if(particles[i]->IsOutside())
			{
				particles.erase(particles.begin() + i);
				i--;
				continue;
			}
			particles[i]->ApplyGravity(Vec2(0, 1));
			particles[i]->ApplyDrag(1);
			particles[i]->Update();
		}
	}
	CheckBounds();
}

void GameState::Render()
{
	window->clear();
	
	if(!particles.empty())
	{
		for(unsigned int i = 0, size = particles.size(); i < size; i++)
		{
			if(particles[i]->pos.x < window->getSize().x && particles[i]->pos.x > 0 && particles[i]->pos.y < window->getSize().y && particles[i]->pos.y > 0)
			particles[i]->Render();
		}
	}
	window->display();
}

void GameState::CheckBounds()
{
	if(!particles.empty())
	{
		for(unsigned int i = 0, size = particles.size(); i < size; i++)
		{
			if(particles[i]->pos.x > window->getSize().x || particles[i]->pos.x < 0 ||
			   particles[i]->pos.y > window->getSize().y || particles[i]->pos.y < 0)
			{
				particles[i]->SetOutside(true);
			}
		}
	}
}
