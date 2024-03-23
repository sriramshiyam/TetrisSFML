#include <TetrisEngine.h>
#include <iostream>

TetrisEngine::TetrisEngine()
{
    initializeGridData();
}

TetrisEngine::~TetrisEngine()
{
    for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
    {
        delete[] gridData[i];
    }
    delete[] gridData;
}

void TetrisEngine::moveBlocksRight()
{
    if (moveTimer.getElapsedTime().asSeconds() >= 0.2f)
    {
        bool allBlocksMoved = false;

        for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
        {
            for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
            {
                if (gridData[i][j] >= 65 && gridData[i][j] <= 90)
                {
                    if (j < TetrisConstants::TETRIS_COLUMN - 1 && gridData[i][j + 1] == '0')
                    {
                        char temp = gridData[i][j];
                        gridData[i][j] = '0';
                        gridData[i][j + 1] = temp;
                        allBlocksMoved = true;
                        break;
                    }
                }
            }

            if (allBlocksMoved)
            {
                break;
            }
        }
        moveTimer.restart();
    }
}

void TetrisEngine::moveBlocksLeft()
{
    if (moveTimer.getElapsedTime().asSeconds() >= 0.2f)
    {
        bool allBlocksMoved = false;

        for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
        {
            for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
            {
                if (gridData[i][j] >= 65 && gridData[i][j] <= 90)
                {
                    if (j > 0 && gridData[i][j - 1] == '0')
                    {
                        char temp = gridData[i][j];
                        gridData[i][j] = '0';
                        gridData[i][j - 1] = temp;
                        allBlocksMoved = true;
                        break;
                    }
                }
            }

            if (allBlocksMoved)
            {
                break;
            }
        }
        moveTimer.restart();
    }
}

void TetrisEngine::moveBlocksDown()
{
    if (moveTimer.getElapsedTime().asSeconds() >= 0.2f)
    {
        bool allBlocksMoved = false;

        for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
        {
            for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
            {
                if (gridData[i][j] >= 65 && gridData[i][j] <= 90)
                {
                    if (i < TetrisConstants::TETRIS_ROW - 1 && gridData[i + 1][j] == '0')
                    {
                        char temp = gridData[i][j];
                        gridData[i][j] = '0';
                        if (i + 1 == TetrisConstants::TETRIS_ROW - 1)
                        {
                            gridData[i + 1][j] = temp + 32;
                            spawnNewBlock = true;
                        }
                        else
                        {
                            gridData[i + 1][j] = temp;
                        }
                        allBlocksMoved = true;
                        break;
                    }
                    else
                    {
                        spawnNewBlock = true;
                    }
                }
            }

            if (allBlocksMoved)
            {
                break;
            }
        }
        moveTimer.restart();
    }
}

void TetrisEngine::updateGridData()
{
    if (timer.getElapsedTime().asSeconds() >= 0.7f || first)
    {
        if (first)
            first = false;

        if (spawnNewBlock)
        {
            spawnNewBlock = false;
            spawned = true;
            srand(time(NULL));
            int index = rand() % TetrisConstants::TETRIS_COLUMN;

            int colors[] = {BLUE, LIGHTBLUE, RED, YELLOW, GREEN, PURPLE, ORANGE};
            int colorIndex = rand() % 7;
            gridData[0][index] = colors[colorIndex];
        }

        bool allBlocksMoved = false;
        if (!spawned)
        {
            for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
            {
                for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
                {
                    if (gridData[i][j] >= 65 && gridData[i][j] <= 90)
                    {
                        if (i < TetrisConstants::TETRIS_ROW - 1 && gridData[i + 1][j] == '0')
                        {
                            char temp = gridData[i][j];
                            gridData[i][j] = '0';
                            if (i + 1 == TetrisConstants::TETRIS_ROW - 1)
                            {
                                gridData[i + 1][j] = temp + 32;
                                spawnNewBlock = true;
                            }
                            else
                            {
                                gridData[i + 1][j] = temp;
                            }
                            allBlocksMoved = true;
                            break;
                        }
                        else
                        {
                            spawnNewBlock = true;
                        }
                    }
                }

                if (allBlocksMoved)
                {
                    break;
                }
            }
        }
        else
        {
            spawned = false;
        }
        timer.restart();
    }
}

char **TetrisEngine::getGridData()
{
    return gridData;
}

void TetrisEngine::initializeGridData()
{
    gridData = new char *[TetrisConstants::TETRIS_ROW];
    for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
    {
        gridData[i] = new char[TetrisConstants::TETRIS_COLUMN];
        for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
        {
            gridData[i][j] = '0';
        }
    }
}