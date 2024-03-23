#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include <SFML/Graphics.hpp>
#include <TetrisConstants.h>

class TetrisBlock : public sf::RenderTexture
{
public:
    TetrisBlock(char color);

private:
    void drawTetrisBlock(char color);
    float blockWidth;
    float blockHeight;
    float x1;
    float x2;
    float y1;
    float y2;
    float line1Length;
    float line2Length;
};

#endif