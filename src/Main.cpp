#include <SFML/Graphics.hpp>

#include "State/State.h"
#include "State/PlayState.h"
#include "Particle/Particle.h"
#include "KeyManager.h"
#include "MouseManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ChemBox");
	KeyManager keyManager;
	MouseManager mouseManager;

	PlayState playState;
	State *state = &playState;
	state->init(window);


	keyManager.init();
	mouseManager.init();
	while(window.isOpen())
	{
		sf::Event event;
		if(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			keyManager.tick(event);
			mouseManager.tick(event);
			state->tick(keyManager, mouseManager);
		}
		state->update();

		window.clear();
		state->render(window);
		window.display();
	}

	return 0;
}