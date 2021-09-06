#pragma once

#include <SFML/Window/Event.hpp>

#include <vector>
#include <algorithm>

class KeyManager
{
public:
    KeyManager();
    void init();
    void tick(sf::Event event);
    bool isPressed(sf::Keyboard::Key key);
    bool isDown(sf::Keyboard::Key key);
    bool isReleased(sf::Keyboard::Key key);
private:
    std::vector<bool> keyPressed;
    std::vector<bool> keyDown;
    std::vector<bool> keyReleased;
};

