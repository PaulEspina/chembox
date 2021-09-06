#pragma once

#include <SFML/Graphics.hpp>

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
    // Setters
    void setTargetWindow(sf::RenderWindow &window);
    // Getters
    sf::Vector2i getPos();
private:
    sf::RenderWindow *window;
    sf::Vector2i pos;
    std::vector<bool> mousePressed;
    std::vector<bool> mouseDown;
    std::vector<bool> mouseReleased;
};