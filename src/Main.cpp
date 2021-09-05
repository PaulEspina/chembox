#include <SFML/Graphics.hpp>

#include "State/PlayState.h"
#include "Particle/Particle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ChemBox");

	PlayState playState;
	State *state = &playState;
	state->init(window);

	while(window.isOpen())
	{
		sf::Event event;
		if(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			state->tick(event);
		}
		state->update();

		window.clear();
		state->render(window);
		window.display();
	}

	return 0;
}