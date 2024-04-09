#include "TetrisShape_Z.h"
#include <iostream>

void TetrisShape_Z::placeNewBlocks(int startX, int startY)
{
    engine->getGridData()[startY][startX] = color;
    engine->getGridData()[startY][startX + 1] = color;
    engine->getGridData()[startY + 1][startX + 1] = color;
    engine->getGridData()[startY + 1][startX + 2] = color;
}

void TetrisShape_Z::initializeStartIndexes()
{
    for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
    {
        for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
        {
            if (engine->getGridData()[i][j] >= 65 && engine->getGridData()[i][j] <= 90)
            {
                startY = i;
                startX = j;
                std::cout << "startX: " << startX << " ,startY: " << startY << std::endl;
                i = TetrisConstants::TETRIS_ROW;
                break;
            }
        }
    }
}

TetrisShape_Z::TetrisShape_Z(TetrisEngine *engine, Colors color) : engine(engine), color(color)
{
}

void TetrisShape_Z::placeInitialShape()
{
    int startIndex = TetrisConstants::TETRIS_COLUMN / 2 - 1;
    engine->getGridData()[0][startIndex] = color;
    engine->getGridData()[0][startIndex + 1] = color;
    engine->getGridData()[1][startIndex + 1] = color;
    engine->getGridData()[1][startIndex + 2] = color;
}

void TetrisShape_Z::updateShapeData()
{
    initializeStartIndexes();

    if (startY + 1 < TetrisConstants::TETRIS_ROW - 1 &&
        (engine->getGridData()[startY + 1][startX] == '0' && engine->getGridData()[startY + 2][startX + 1] == '0' && engine->getGridData()[startY + 2][startX + 2] == '0'))
    {
        engine->getGridData()[startY][startX] = '0';
        engine->getGridData()[startY][startX + 1] = '0';
        engine->getGridData()[startY + 1][startX + 1] = '0';
        engine->getGridData()[startY + 1][startX + 2] = '0';

        startY++;
        if (startY + 1 == TetrisConstants::TETRIS_ROW - 1 && !engine->getMovingHorizontally())
        {
            color += 32;
            placeNewBlocks(startX, startY);
            engine->setSpawnNewBlock(true);
        }
        else
        {
            placeNewBlocks(startX, startY);
        }
    }
    else if (!engine->getMovingHorizontally())
    {
        color += 32;
        placeNewBlocks(startX, startY);
        engine->setSpawnNewBlock(true);
    }
}

void TetrisShape_Z::moveShapeRight()
{
    initializeStartIndexes();

    if (startX + 1 < TetrisConstants::TETRIS_COLUMN - 1 && engine->getGridData()[startY][startX + 2] == '0' && engine->getGridData()[startY + 1][startX + 3] == '0')
    {
        engine->getGridData()[startY][startX] = '0';
        engine->getGridData()[startY][startX + 1] = '0';
        engine->getGridData()[startY + 1][startX + 1] = '0';
        engine->getGridData()[startY + 1][startX + 2] = '0';

        startX++;
        placeNewBlocks(startX, startY);
    }
}

void TetrisShape_Z::moveShapeLeft()
{
    initializeStartIndexes();

    if (startX > 0 && engine->getGridData()[startY][startX - 1] == '0' && engine->getGridData()[startY + 1][startX] == '0')
    {
        engine->getGridData()[startY][startX] = '0';
        engine->getGridData()[startY][startX + 1] = '0';
        engine->getGridData()[startY + 1][startX + 1] = '0';
        engine->getGridData()[startY + 1][startX + 2] = '0';

        startX--;
        placeNewBlocks(startX, startY);
    }
}

void TetrisShape_Z::moveShapeDown()
{
    updateShapeData();
}

void TetrisShape_Z::moveShapeToBottom()
{
    std::cout << "TetrisShape_Z::moveShapeToBottom" << std::endl;
    initializeStartIndexes();

    char tempColor = color;

    color = '0';
    placeNewBlocks(startX, startY);

    while (startY + 1 < TetrisConstants::TETRIS_ROW - 1 && engine->getGridData()[startY + 1][startX] == '0' && engine->getGridData()[startY + 2][startX + 1] == '0' && engine->getGridData()[startY + 2][startX + 2] == '0')
    {
        startY++;
    }

    color = tempColor + 32;

    placeNewBlocks(startX, startY);
    engine->setSpawnNewBlock(true);
}
