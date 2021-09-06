#pragma once

#include <SFML/Window/Event.hpp>

#include <vector>
#include <algorithm>

class MouseManager
{
public:
    MouseManager();
    void init();
    void tick(sf::Event event);
    bool isPressed(sf::Mouse::Button mouseButton);
    bool isDown(sf::Mouse::Button mouseButton);
    bool isReleased(sf::Mouse::Button mouseButton);
private:
    std::vector<bool> mousePressed;
    std::vector<bool> mouseDown;
    std::vector<bool> mouseReleased;
};