#include "GameState.h"

void GameState::Init(sf::RenderWindow& window)
{
	this->window = &window;
	mouse_man = MouseManager();
	key_man = KeyManager();
	particles = NULL;
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
		Particle *particle = new Wood(mouse, *window);
		Particle **temp = new Particle*[Particle::particle_count];
		for(unsigned int i = 0; i < Particle::particle_count - 1; i++)
		{
			temp[i] = particles[i];
		}
		temp[Particle::particle_count - 1] = particle;
		delete[] particles;
		particles = temp;
	}
	if(mouse_man.ButtonDown(sf::Mouse::Right))
	{
		
	}
	if(Particle::particle_count > 0)
	{
		for(unsigned int i = 0; i < Particle::particle_count; i++)
		{
			if(particles[i]->IsOutside())
			{
				delete particles[i];
				for(unsigned int j = i; j < Particle::particle_count; j++)
				{
					particles[j] = particles[j + 1];
				}
			}
		}
		Particle **temp = new Particle * [Particle::particle_count];
		for(unsigned int i = 0; i < Particle::particle_count; i++)
		{
			temp[i] = particles[i];
		}
		delete[] particles;
		particles = temp;
		if(Particle::particle_count > 0)
		{
			for(unsigned int i = 0; i < Particle::particle_count; i++)
			{
				particles[i]->ApplyGravity(Vec2(0, 1));
				particles[i]->ApplyDrag(1);
				particles[i]->Update();
			}
		}
	}
	CheckBounds();
}

void GameState::Render()
{
	window->clear();
	
	if(Particle::particle_count > 0)
	{
		for(unsigned int i = 0; i < Particle::particle_count; i++)
		{
			if(particles[i]->pos.x < window->getSize().x && particles[i]->pos.x > 0 && particles[i]->pos.y < window->getSize().y && particles[i]->pos.y > 0)
			particles[i]->Render();
		}
	}
	window->display();
}

void GameState::CleanUp()
{
	if(Particle::particle_count > 0)
	{
		for(unsigned int i = 0; i < Particle::particle_count; i++)
		{
			delete particles[i];
		}
	}
}

void GameState::CheckBounds()
{
	if(Particle::particle_count > 0)
	{
		for(unsigned int i = 0; i < Particle::particle_count; i++)
		{
			if(particles[i]->pos.x > window->getSize().x || particles[i]->pos.x < 0 ||
			   particles[i]->pos.y > window->getSize().y || particles[i]->pos.y < 0)
			{
				particles[i]->SetOutside(true);
			}
		}
	}
}
