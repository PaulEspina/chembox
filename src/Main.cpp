#include <SFML/Graphics.hpp>

#include "State/PlayState.h"
#include "Particle/Particle.h"
#include "KeyManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ChemBox");
	KeyManager keyManager;

	PlayState playState;
	State *state = &playState;
	state->init(window);


	keyManager.init();
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
			state->tick(keyManager);
		}
		state->update();

		window.clear();
		state->render(window);
		window.display();
	}

	return 0;
}