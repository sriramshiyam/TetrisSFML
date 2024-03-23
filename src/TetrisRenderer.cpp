#include <TetrisRenderer.h>
#include <TetrisConstants.h>
#include <TetrisBlock.h>
#include <iostream>

using namespace TetrisConstants;

TetrisRenderer::TetrisRenderer(sf::RenderWindow *window) : window(window)
{
}

TetrisRenderer::~TetrisRenderer()
{
}

void TetrisRenderer::render(char **gridData)
{
    drawGrid();
    drawBlocks(gridData);
}

void TetrisRenderer::drawGrid()
{
    sf::RectangleShape verticalLine(sf::Vector2f(1.0f, TETRIS_HEIGHT));
    verticalLine.setFillColor(GRID_COLOR);

    sf::RectangleShape horizontalLine(sf::Vector2f(TETRIS_WIDTH, 1.0f));
    horizontalLine.setFillColor(GRID_COLOR);

    for (int i = 0; i < TETRIS_ROW + 1; i++)
    {
        horizontalLine.setPosition(sf::Vector2f(0, i * TETRIS_BLOCK_DIMENSION));
        window->draw(horizontalLine);
    }

    for (int i = 0; i < TETRIS_COLUMN + 1; i++)
    {
        verticalLine.setPosition(sf::Vector2f(i * TETRIS_BLOCK_DIMENSION, 0));
        window->draw(verticalLine);
    }
}

void TetrisRenderer::drawBlocks(char **gridData)
{
    for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
    {
        for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
        {
            if (gridData[i][j] != '0')
            {
                TetrisBlock block(gridData[i][j] >= 97 ? gridData[i][j] - 32 : gridData[i][j]);

                sf::Sprite blockSprite(block.getTexture());
                blockSprite.setPosition(j * TetrisConstants::TETRIS_BLOCK_DIMENSION + 0.5f, i * TetrisConstants::TETRIS_BLOCK_DIMENSION + 0.5f);

                window->draw(blockSprite);
            }
        }
    }
}
