#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class MouseManager
{
public:
public:
	MouseManager()
	{
		for(unsigned int i = 0; i < 256; i++)
			buttons.push_back(false);
	}
	Vec2 Update(sf::Event event)
	{
		if(event.type == sf::Event::MouseButtonPressed)
			buttons[event.key.code] = true;
		if(event.type == sf::Event::MouseButtonReleased)
			buttons[event.key.code] = false;
		if(event.type == sf::Event::MouseMoved)
		{
			mouse.x = (float) event.mouseMove.x;
			mouse.y = (float) event.mouseMove.y;
		}
		return mouse;
	}
	bool ButtonDown(sf::Mouse::Button button)
	{
		return buttons[button];
	}
private:
	std::vector<bool> buttons;
	Vec2 mouse;
};

