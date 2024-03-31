#ifndef TETRIS_SHAPE_O_H
#define TETRIS_SHAPE_O_H

#include <TetrisConstants.h>
#include <TetrisEngine.h>
#include <SFML/System.hpp>

class TetrisShape_O
{

private:
    TetrisEngine *engine;
    char color;
    int startX;
    int startY;
    void placeNewBlocks(int startX, int startY);
    void initializeStartIndexes();

public:
    TetrisShape_O(TetrisEngine *engine, Colors color);
    void placeInitialShape();
    void updateShapeData();
    void moveShapeRight();
    void moveShapeLeft();
    void moveShapeDown();
    void moveShapeToBottom();
};

#endif