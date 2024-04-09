#ifndef TETRIS_SHAPE_Z_H
#define TETRIS_SHAPE_Z_H

#include <TetrisConstants.h>
#include <TetrisEngine.h>
#include <SFML/System.hpp>

class TetrisShape_Z
{

private:
    TetrisEngine *engine;
    char color;
    int startX;
    int startY;
    void placeNewBlocks(int startX, int startY);
    void initializeStartIndexes();

public:
    TetrisShape_Z(TetrisEngine *engine, Colors color);
    void placeInitialShape();
    void updateShapeData();
    void moveShapeRight();
    void moveShapeLeft();
    void moveShapeDown();
    void moveShapeToBottom();
};

#endif