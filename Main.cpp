#include <SFML\Graphics.hpp>

#include "GameState.h"

State* state;
GameState game;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "ChemBox");
    state = &game;
    state->Init(window);
    while(window.isOpen())
    {
        state->Update();
        state->Render();
    }
    state->CleanUp();
    return EXIT_SUCCESS;
}