#ifndef TETRIS_RENDERER_H
#define TETRIS_RENDERER_H
#include <SFML/Graphics.hpp>

class TetrisRenderer
{
public:
    TetrisRenderer(sf::RenderWindow *window);
    ~TetrisRenderer();
    void render();
    void drawGrid();

private:
    sf::RenderWindow *window;
};

#endif