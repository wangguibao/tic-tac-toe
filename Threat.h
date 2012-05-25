#ifndef THREAT_H
#define THREAT_H
#include "Chess.h"

struct Threat
{
    Threat(const Chess &chess1_, const Chess &Chess2_, const Chess &missing_);
    Chess chess1;  // Chess1 and chess2 denote what we have on board
    Chess chess2;
    Chess missing; // If we had this missing chess on board, we'll win
};

#endif // THREAT_H
