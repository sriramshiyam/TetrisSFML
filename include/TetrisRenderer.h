#ifndef TETRIS_RENDERER_H
#define TETRIS_RENDERER_H
#include <SFML/Graphics.hpp>

class TetrisRenderer
{
public:
    TetrisRenderer(sf::RenderWindow *window);
    ~TetrisRenderer();
    void render(char **gridData);

private:
    void drawGrid();
    void drawBlocks(char **gridData);
    sf::RenderWindow *window;
};

#endif