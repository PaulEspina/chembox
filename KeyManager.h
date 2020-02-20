#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class KeyManager
{
public:
	KeyManager()
	{
		for(unsigned int i = 0; i < 256; i++)
			keys.push_back(false);
	}
	void Update(sf::Event event)
	{
		if(event.type == sf::Event::KeyPressed)
			keys[event.key.code] = true;
		if(event.type == sf::Event::KeyReleased)
			keys[event.key.code] = false;
	}
	bool KeyDown(sf::Keyboard::Key key)
	{
		return keys[key];	
	}
private:
	std::vector<bool> keys;
};

