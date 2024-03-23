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

public:
    TetrisEngine();
    ~TetrisEngine();
    void moveBlocksRight();
    void moveBlocksLeft();
    void moveBlocksDown();
    void updateGridData();
    void invalidateHorizontallyMovingBlock();
    char **getGridData();
};
#endif