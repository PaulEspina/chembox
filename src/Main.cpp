#include <SFML/Graphics.hpp>

#include "PlayState.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ChemBox");

	State *state = nullptr;
	PlayState playState;
	state->init();

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
		state->render(window);
	}

	return 0;
}