#include "MouseManager.h"

MouseManager::MouseManager()
{
    for(int i = 0; i < 256; i++)
    {
        mousePressed.push_back(false);
        mouseDown.push_back(false);
        mouseReleased.push_back(false);
    }
}

void MouseManager::init()
{
    std::fill(mousePressed.begin(), mousePressed.end(), false);
    std::fill(mouseDown.begin(), mouseDown.end(), false);
    std::fill(mouseReleased.begin(), mouseReleased.end(), false);
}

void MouseManager::tick(sf::Event event)
{
    std::fill(mousePressed.begin(), mousePressed.end(), false);
    std::fill(mouseReleased.begin(), mouseReleased.end(), false);
    if(event.type == sf::Event::MouseButtonPressed)
    {
        mousePressed[event.mouseButton.button] = true;
        mouseDown[event.mouseButton.button] = true;
    }
    if(event.type == sf::Event::MouseButtonReleased)
    {
        mouseReleased[event.mouseButton.button] = true;
        mouseDown[event.mouseButton.button] = false;
    }
}

bool MouseManager::isPressed(sf::Mouse::Button mouseButton)
{
    return mousePressed[mouseButton];
}

bool MouseManager::isDown(sf::Mouse::Button mouseButton)
{
    return mouseDown[mouseButton];
}

bool MouseManager::isReleased(sf::Mouse::Button mouseButton)
{
    return mouseReleased[mouseButton];
}
