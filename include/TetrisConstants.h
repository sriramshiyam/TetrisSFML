#ifndef TETRIS_CONSTANTS_H
#define TETRIS_CONSTANTS_H
#include <SFML/Graphics.hpp>

namespace TetrisConstants
{
    const int HEIGHT_PERCENT = 80;
    const int TETRIS_COLUMN = 10;
    const int TETRIS_ROW = 20;
    const int TETRIS_BLOCK_DIMENSION = sf::VideoMode::getDesktopMode().height * HEIGHT_PERCENT / 100 / TETRIS_ROW; // window height is of 80 percent of a screen height
    const int TETRIS_WIDTH = TETRIS_COLUMN * TETRIS_BLOCK_DIMENSION;
    const int TETRIS_HEIGHT = TETRIS_ROW * TETRIS_BLOCK_DIMENSION;
    const int TETRIS_GRID_COLOR = 0xffffff;
    const sf::Color GRID_COLOR{128, 128, 128, 255};
    const sf::Color BLUE_COLOR{0, 0, 255, 255};
    const sf::Color LIGHTBLUE_COLOR{102, 204, 255, 255};
    const sf::Color RED_COLOR{255, 0, 0, 255};
    const sf::Color YELLOW_COLOR{255, 255, 0, 255};
    const sf::Color GREEN_COLOR{0, 255, 0, 255};
    const sf::Color PURPLE_COLOR{203, 0, 255, 255};
    const sf::Color ORANGE_COLOR{255, 106, 0, 255};
} // namespace TetrisConstants

enum Colors
{
    BLUE = 'B',
    LIGHTBLUE = 'L',
    RED = 'R',
    YELLOW = 'Y',
    GREEN = 'G',
    PURPLE = 'P',
    ORANGE = 'O'
};

enum TetrisShape
{
    O,
    I,
    L,
    S,
    Z,
    J,
    T
};

#endif