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
    // sf::Keyboard::Space is not working in sf::Event::KeyPressed event
    if (event->type == sf::Event::KeyPressed && !engine.getSpawnNewBlock())
    {
        switch (event->key.code)
        {
        case sf::Keyboard::Down:
            engine.moveBlocksDown();
            break;
        case sf::Keyboard::Left:
            leftKeyPressed = true;
            engine.moveBlocksLeft();
            break;
        case sf::Keyboard::Right:
            rightKeyPressed = true;
            engine.moveBlocksRight();
            break;
        default:
            break;
        }
    }
    else if (event->type == sf::Event::KeyReleased)
    {
        if (event->key.code == sf::Keyboard::Left)
        {
            leftKeyPressed = false;
        }
        else if (event->key.code == sf::Keyboard::Right)
        {
            rightKeyPressed = false;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !engine.getSpawnNewBlock())
    {
        engine.moveBlockToBottom();
    }

    engine.setMovingHorizontally(leftKeyPressed || rightKeyPressed);
    engine.updateGridData();
    // engine.logGridData();
    renderer.render(engine.getGridData());
}