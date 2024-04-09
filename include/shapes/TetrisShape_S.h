#ifndef TETRIS_SHAPE_S_H
#define TETRIS_SHAPE_S_H

#include <TetrisConstants.h>
#include <TetrisEngine.h>
#include <SFML/System.hpp>

class TetrisShape_S
{

private:
    TetrisEngine *engine;
    char color;
    int startX;
    int startY;
    void placeNewBlocks(int startX, int startY);
    void initializeStartIndexes();

public:
    TetrisShape_S(TetrisEngine *engine, Colors color);
    void placeInitialShape();
    void updateShapeData();
    void moveShapeRight();
    void moveShapeLeft();
    void moveShapeDown();
    void moveShapeToBottom();
};

#endif