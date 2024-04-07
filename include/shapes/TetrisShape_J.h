#ifndef TETRIS_SHAPE_J_H
#define TETRIS_SHAPE_J_H

#include <TetrisConstants.h>
#include <TetrisEngine.h>
#include <SFML/System.hpp>

class TetrisShape_J
{

private:
    TetrisEngine *engine;
    char color;
    int startX;
    int startY;
    void placeNewBlocks(int startX, int startY);
    void initializeStartIndexes();

public:
    TetrisShape_J(TetrisEngine *engine, Colors color);
    void placeInitialShape();
    void updateShapeData();
    void moveShapeRight();
    void moveShapeLeft();
    void moveShapeDown();
    void moveShapeToBottom();
};

#endif