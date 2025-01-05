#include "interface.h"

interface::interface()
{
    window.create(sf::VideoMode({800, 800}), "Ultimate Tic-Tac-Toe");
    window.setFramerateLimit(60);
}