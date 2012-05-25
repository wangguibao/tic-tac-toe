#ifndef ROBOT_H
#define ROBOT_H
#include "Board.h"

class Robot
{
public:
    Robot();
    ~Robot();

    int Move(const Board &board);
};

#endif // ROBOT_H
