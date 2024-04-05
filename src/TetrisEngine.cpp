#include <TetrisEngine.h>
#include <iostream>
#include <shapes/TetrisShape_O.h>
#include <shapes/TetrisShape_I.h>
#include <shapes/TetrisShape_T.h>
#include <shapes/TetrisShape_L.h>

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
    if (moveTimer.getElapsedTime().asSeconds() >= 0.19f)
    {
        switch (currentShape)
        {
        case TetrisShape::O:
            TetrisShape_O(this, currentColor).moveShapeRight();
            break;
        case TetrisShape::I:
            TetrisShape_I(this, currentColor).moveShapeRight();
            break;
        case TetrisShape::T:
            TetrisShape_T(this, currentColor).moveShapeRight();
            break;
        case TetrisShape::L:
            TetrisShape_L(this, currentColor).moveShapeRight();
            break;
        default:
            break;
        }
        moveTimer.restart();
    }
}

void TetrisEngine::moveBlocksLeft()
{
    if (moveTimer.getElapsedTime().asSeconds() >= 0.19f)
    {
        switch (currentShape)
        {
        case TetrisShape::O:
            TetrisShape_O(this, currentColor).moveShapeLeft();
            break;
        case TetrisShape::I:
            TetrisShape_I(this, currentColor).moveShapeLeft();
            break;
        case TetrisShape::T:
            TetrisShape_T(this, currentColor).moveShapeLeft();
            break;
        case TetrisShape::L:
            TetrisShape_L(this, currentColor).moveShapeLeft();
            break;
        default:
            break;
        }
        moveTimer.restart();
    }
}

void TetrisEngine::moveBlocksDown()
{
    if (moveTimer.getElapsedTime().asSeconds() >= 0.19f)
    {
        switch (currentShape)
        {
        case TetrisShape::O:
            TetrisShape_O(this, currentColor).moveShapeDown();
            break;
        case TetrisShape::I:
            TetrisShape_I(this, currentColor).moveShapeDown();
            break;
        case TetrisShape::T:
            TetrisShape_T(this, currentColor).moveShapeDown();
            break;
        case TetrisShape::L:
            TetrisShape_L(this, currentColor).moveShapeDown();
            break;
        default:
            break;
        }
        moveTimer.restart();
    }
}

void TetrisEngine::updateGridData()
{
    if (timer.getElapsedTime().asSeconds() >= 0.5f || first)
    {
        if (first)
            first = false;

        if (spawnNewBlock)
        {
            spawnNewBlock = false;
            spawned = true;

            srand(time(NULL));

            int colors[] = {BLUE, LIGHTBLUE, RED, YELLOW, GREEN, PURPLE, ORANGE};
            int colorIndex = rand() % 7;
            // currentShape = TetrisShape(rand() % 8);
            currentShape = TetrisShape::L;
            currentColor = (Colors)colors[colorIndex];
            placeInitialBlocks();
        }
        bool allBlocksMoved = false;

        if (!spawned)
        {
            switch (currentShape)
            {
            case TetrisShape::O:
                TetrisShape_O(this, currentColor).updateShapeData();
                break;
            case TetrisShape::I:
                TetrisShape_I(this, currentColor).updateShapeData();
                break;
            case TetrisShape::T:
                TetrisShape_T(this, currentColor).updateShapeData();
                break;
            case TetrisShape::L:
                TetrisShape_L(this, currentColor).updateShapeData();
                break;
            default:
                break;
            }
        }
        else
        {
            spawned = false;
        }
        timer.restart();
    }
}

void TetrisEngine::logGridData()
{
    system("clear");
    for (int i = 0; i < TetrisConstants::TETRIS_ROW; i++)
    {
        for (int j = 0; j < TetrisConstants::TETRIS_COLUMN; j++)
        {
            std::cout << gridData[i][j];
        }
        std::cout << std::endl;
    }
}

char **TetrisEngine::getGridData()
{
    return gridData;
}

void TetrisEngine::setSpawnNewBlock(bool newSpawnNewBlock)
{
    spawnNewBlock = newSpawnNewBlock;
    timer.restart();
}

bool TetrisEngine::getSpawnNewBlock()
{
    return spawnNewBlock;
}

void TetrisEngine::setMovingHorizontally(bool movingHorizontally)
{
    this->movingHorizontally = movingHorizontally;
}

bool TetrisEngine::getMovingHorizontally()
{
    return movingHorizontally;
}

void TetrisEngine::moveBlockToBottom()
{
    if (moveTimer.getElapsedTime().asSeconds() >= 0.19f)
    {

        switch (currentShape)
        {
        case TetrisShape::O:
            TetrisShape_O(this, currentColor).moveShapeToBottom();
            break;
        case TetrisShape::I:
            TetrisShape_I(this, currentColor).moveShapeToBottom();
            break;
        case TetrisShape::T:
            TetrisShape_T(this, currentColor).moveShapeToBottom();
            break;
        case TetrisShape::L:
            TetrisShape_L(this, currentColor).moveShapeToBottom();
            break;
        default:
            break;
        }
        moveTimer.restart();
        timer.restart();
    }
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

void TetrisEngine::placeInitialBlocks()
{
    switch (currentShape)
    {
    case TetrisShape::O:
        TetrisShape_O(this, currentColor).placeInitialShape();
        break;
    case TetrisShape::I:
        TetrisShape_I(this, currentColor).placeInitialShape();
        break;
    case TetrisShape::T:
        TetrisShape_T(this, currentColor).placeInitialShape();
        break;
    case TetrisShape::L:
        TetrisShape_L(this, currentColor).placeInitialShape();
        break;
    default:
        break;
    }
}