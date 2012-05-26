#include <ctime>
#include <cstdlib>
#include "Robot.h"

Robot::Robot()
{
    //ctor
}

Robot::~Robot()
{
    //dtor
}

/**
 * Calculate next move for X chesses
 * @return the grid to place an X chess
 */
int Robot::Move(const Board &board)
{
    list<Threat>::iterator threatIter;
    list<Threat> xThreatList = board.GetXThreatList();
    list<Threat> oThreatList = board.GetOThreatList();
    /**
     * Check if there's any X side threats. If there is one, and the missing
     * chess grid is not occupied by any chess, then that is our chance to
     * win
     */
    for (threatIter = xThreatList.begin(); threatIter != xThreatList.end();
         threatIter++) {
        if (board.Empty(threatIter->missing.id)) {
            return threatIter->missing.id;
        }
    }

    /**
     * Check if there's any O side threats. If there is one, obviously we will
     * have to break it, otherwise we will lose this game.
     */
    if (oThreatList.size() != 0) {
        threatIter = oThreatList.begin();
        return threatIter->missing.id;
    }

    /**
     * At this point, neither X side win immediately, nor O side will win when
     * it is his turn.
     *
     * If the X side thinks like a humankind like me, he would begin consider
     * possibilities of developing new Threats from NearlyThreats
     */
    list<NearlyThreat>::iterator nearlyThreatIter;
    list<NearlyThreat> xSideNearlyThreatList = board.GetXNearlyThreatList();
    int i = rand() % 2;
    if (xSideNearlyThreatList.size() != 0) {
        nearlyThreatIter = xSideNearlyThreatList.begin();
        if (i == 0) {
            return nearlyThreatIter->missing1.id;
        }
        else {
            return nearlyThreatIter->missing2.id;
        }
    }

    /**
     * At this point, there must be no X side NearlyThreats. Thinking like
     * humankind like me, the X side player would choose one of the two actions
     * randomly:
     * 1) Put a chess that would develop as many NearlyThreats as
     *    possible
     * 2) Break one O side NearlyThreat
     */
    i = rand() % 2;
    list<NearlyThreat> oSideNearlyThreatList = board.GetONearlyThreatList();

    if (i == 0 || oSideNearlyThreatList.size() == 0) {
        /* Put a chess that will develop as many NearlyThreats as possible */
        int nearlyThreatNumber[Board::CHESS_CNT + 1];
        int max = -1;
        unsigned int j;
        for (j = 1; j <= Board::CHESS_CNT; j++) {
            if (board.Empty(j) == true) {
                nearlyThreatNumber[j] = board.TryDetectNearlyThreat(j);
            }
            else {
                nearlyThreatNumber[j] = -1;
            }
            if (max < nearlyThreatNumber[j]) {
                max = nearlyThreatNumber[j];
            }
        }

        int maxXSideNearlyThreatListcnt = 0;
        int maxXSideNearlyThreatListgrid[Board::CHESS_CNT] = {0, };
        for (j = 1; j <= Board::CHESS_CNT; j++) {
            if (max == nearlyThreatNumber[j]) {
                maxXSideNearlyThreatListgrid[maxXSideNearlyThreatListcnt] = j;
                maxXSideNearlyThreatListcnt++;
            }
        }

        int randGrid = rand() % maxXSideNearlyThreatListcnt;
        return maxXSideNearlyThreatListgrid[randGrid];
    }
    else {
        nearlyThreatIter = oSideNearlyThreatList.begin();
        int j = rand() % 2;
        if (j == 0) {
            return nearlyThreatIter->missing1.id;
        }
        else {
            return nearlyThreatIter->missing2.id;
        }
    }
}
