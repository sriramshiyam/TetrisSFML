#include <Tetris.h>

Tetris::Tetris(sf::RenderWindow *window) : renderer(window)
{
    
}

Tetris::~Tetris()
{
}

void Tetris::update()
{
    renderer.render();
}