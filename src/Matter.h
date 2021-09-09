#pragma once

#include <SFML/System.hpp>

class Matter
{
public:
	void update();
	//Getters
	sf::Vector2f getPos();
	sf::Vector2f getVel();
	sf::Vector2f getAcc();
	// Setters
	void setPos(sf::Vector2f pos);
	void setVel(sf::Vector2f vel);
	void setAcc(sf::Vector2f acc);
private:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;
};

