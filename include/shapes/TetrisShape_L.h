#ifndef TETRIS_SHAPE_L_H
#define TETRIS_SHAPE_L_H

#include <TetrisConstants.h>
#include <TetrisEngine.h>
#include <SFML/System.hpp>

class TetrisShape_L
{

private:
    TetrisEngine *engine;
    char color;
    int startX;
    int startY;
    void placeNewBlocks(int startX, int startY);
    void initializeStartIndexes();

public:
    TetrisShape_L(TetrisEngine *engine, Colors color);
    void placeInitialShape();
    void updateShapeData();
    void moveShapeRight();
    void moveShapeLeft();
    void moveShapeDown();
    void moveShapeToBottom();
};

#endif