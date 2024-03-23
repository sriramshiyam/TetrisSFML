#include <Tetris.h>
#include <TetrisConstants.h>
#include <iostream>

Tetris::Tetris(sf::RenderWindow *window) : renderer(window)
{
}

Tetris::~Tetris()
{
}

void Tetris::update(sf::Event *event)
{

    if (event->type == sf::Event::KeyPressed)
    {
        switch (event->key.code)
        {
        case sf::Keyboard::Down:
            engine.moveBlocksDown();
            break;
        case sf::Keyboard::Left:
            engine.moveBlocksLeft();
            break;
        case sf::Keyboard::Right:
            engine.moveBlocksRight();
            break;
        default:
            break;
        }
    }
    else if (event->type == sf::Event::KeyReleased)
    {
        if (event->key.code == sf::Keyboard::Left || event->key.code == sf::Keyboard::Right)
        {
            // engine.
        }
    }

    engine.updateGridData();
    renderer.render(engine.getGridData());
}