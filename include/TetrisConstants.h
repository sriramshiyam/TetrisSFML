#ifndef TETRIS_CONSTANTS_H
#define TETRIS_CONSTANTS_H
#include <SFML/Graphics.hpp>

namespace TetrisConstants
{
    const int TETRIS_DIMENSION = 50;
    const int TETRIS_COLUMN = 10;
    const int TETRIS_ROW = 20;
    const int TETRIS_WIDTH = TETRIS_COLUMN * TETRIS_DIMENSION;
    const int TETRIS_HEIGHT = TETRIS_ROW * TETRIS_DIMENSION;
    const int TETRIS_GRID_COLOR = 0xffffff;
    const sf::Color GRID_COLOR{128, 128, 128, 255};
} // namespace TetrisConstants

#endif