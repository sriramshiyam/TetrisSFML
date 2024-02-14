#ifndef TETRIS_H
#define TETRIS_H

#include <SFML/Graphics.hpp>
#include <TetrisRenderer.h>


class Tetris
{
public:
    Tetris(sf::RenderWindow *window);
    ~Tetris();
    void update();

private:
    TetrisRenderer renderer;
};

#endif // TETRIS_H