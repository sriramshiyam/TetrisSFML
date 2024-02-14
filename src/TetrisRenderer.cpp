#include <TetrisRenderer.h>
#include <TetrisConstants.h>

using namespace TetrisConstants;

TetrisRenderer::TetrisRenderer(sf::RenderWindow *window) : window(window)
{
}

TetrisRenderer::~TetrisRenderer()
{
}

void TetrisRenderer::render()
{
    drawGrid();
}

void TetrisRenderer::drawGrid()
{
    sf::RectangleShape verticalLine(sf::Vector2f(1.0f, TETRIS_HEIGHT));
    verticalLine.setFillColor(GRID_COLOR);

    sf::RectangleShape horizontalLine(sf::Vector2f(TETRIS_WIDTH, 1.0f));
    horizontalLine.setFillColor(GRID_COLOR);

    for (int i = 0; i < TETRIS_ROW + 1; i++)
    {
        horizontalLine.setPosition(sf::Vector2f(0, i * TETRIS_DIMENSION));
        window->draw(horizontalLine);
    }

    for (int i = 0; i < TETRIS_COLUMN + 1; i++)
    {
        verticalLine.setPosition(sf::Vector2f(i * TETRIS_DIMENSION, 0));
        window->draw(verticalLine);
    }
}
