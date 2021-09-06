#include "KeyManager.h"

KeyManager::KeyManager()
{
    for(int i = 0; i < 256; i++)
    {
        keyPressed.push_back(false);
        keyDown.push_back(false);
        keyReleased.push_back(false);
    }
}

void KeyManager::init()
{
    std::fill(keyPressed.begin(), keyPressed.end(), false);
    std::fill(keyDown.begin(), keyDown.end(), false);
    std::fill(keyReleased.begin(), keyReleased.end(), false);
}

void KeyManager::tick(sf::Event event)
{
    std::fill(keyPressed.begin(), keyPressed.end(), false);
    std::fill(keyReleased.begin(), keyReleased.end(), false);
    if(event.type == sf::Event::KeyPressed)
    {
        keyPressed[event.key.code] = true;
        keyDown[event.key.code] = true;
    }
    if(event.type == sf::Event::KeyReleased)
    {
        keyReleased[event.key.code] = true;
        keyDown[event.key.code] = false;
    }
}

bool KeyManager::isPressed(sf::Keyboard::Key key)
{
    return keyPressed[key];
}

bool KeyManager::isDown(sf::Keyboard::Key key)
{
    return keyDown[key];
}

bool KeyManager::isReleased(sf::Keyboard::Key key)
{
    return keyReleased[key];
}
