#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H

#include <TetrisConstants.h>
#include <SFML/System.hpp>

class TetrisEngine
{
private:
    char **gridData;
    void initializeGridData();
    sf::Clock timer;
    sf::Clock moveTimer;
    bool spawnNewBlock = true;
    bool spawned = false;
    bool first = true;
    bool movingHorizontally = false;
    TetrisShape currentShape;
    Colors currentColor;
    void placeInitialBlocks();

public:
    TetrisEngine();
    ~TetrisEngine();
    void moveBlocksRight();
    void moveBlocksLeft();
    void moveBlocksDown();
    void updateGridData();
    void logGridData();
    char **getGridData();
    void setSpawnNewBlock(bool newSpawnNewBlock);
    bool getSpawnNewBlock();
    void setMovingHorizontally(bool movingHorizontally);
    bool getMovingHorizontally();
    void moveBlockToBottom();
};
#endif