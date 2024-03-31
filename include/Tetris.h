#ifndef TETRIS_H
#define TETRIS_H

#include <SFML/Graphics.hpp>
#include <TetrisRenderer.h>
#include <TetrisEngine.h>

class Tetris
{
public:
    Tetris(sf::RenderWindow *window);
    ~Tetris();
    void update(sf::Event *event);

private:
    TetrisRenderer renderer;
    TetrisEngine engine;
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
};

#endif // TETRIS_H