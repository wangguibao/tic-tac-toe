#ifndef NEARLYTHREAT_H
#define NEARLYTHREAT_H
#include "Chess.h"

struct NearlyThreat
{
    NearlyThreat(const Chess &chess_, const Chess &missing1_,
                 const Chess &missing2_);
    Chess chess;       // This is what we have on board
    Chess missing1;    // If we had these two missing chesses on board, we
    Chess missing2;    // will win
};

#endif // NEARLYTHREAT_H
