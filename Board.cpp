#include "Board.h"

Board::Board()
{
    InitBoard();
    //ctor
}

Board::~Board()
{
    //dtor
}

void Board::InitBoard()
{
    whichSideTurn = O_SIDE_TURN;
    Freeze(false);
    oSideBoardStateBit = 0;
    xSideBoardStateBit = 0;

    oSideThreatList.clear();
    xSideThreatList.clear();
    oSideNearlyThreatList.clear();
    xSideNearlyThreatList.clear();
}

/**
 * Checks if a board grid is empty - not occupied by neither an X nor an O
 * @param gridId is the grid id, counted from 1 to 9
 * @return true if the grid is empty
 */
bool Board::Empty(int gridId) const
{
    return ((oSideBoardStateBit & (1 << (gridId))) == 0 &&
            (xSideBoardStateBit & (1 << (gridId))) == 0);
}

/**
 * For a given empty grid, if putting a chess at this position develops one or
 * more NearlyThreats, this function counts the total number of newly formed
 * NearlyThreats, without actually putting a chess at that grid
 */
int Board::TryDetectNearlyThreat(int id) const
{
    int count = 0;
    switch (id) {
        case 1:
            if (Empty(id + 1) && Empty(id + 2)) {
                count++;
            }

            if (Empty(id + 3) && Empty(id + 6)) {
                count++;
            }

            if (Empty(id + 4) && Empty(id + 8)) {
                count++;
            }
            break;
        case 2:
            if (Empty(id - 1) && Empty(id + 1)) {
                count++;
            }
            if (Empty(id + 3) && Empty(id + 6)) {
                count++;
            }
            break;
        case 3:
            if (Empty(id - 1) && Empty(id - 2)) {
                count++;
            }

            if (Empty(id + 2) && Empty(id + 4)) {
                count++;
            }
            if (Empty(id + 3) && Empty(id + 6)) {
                count++;
            }
            break;
        case 4:
            if (Empty(id - 3) && Empty(id + 3)) {
                count++;
            }
            if (Empty(id + 1) && Empty(id + 2)) {
                count++;
            }
            break;
        case 5:
            if (Empty(id - 1) && Empty(id + 1)) {
                count++;
            }

            if (Empty(id - 3) && Empty(id + 3)) {
                count++;
            }
            if (Empty(id - 4) && Empty(id + 4)) {
                count++;
            }
            if (Empty(id - 2) && Empty(id + 2)) {
                count++;
            }
            break;
        case 6:
            if (Empty(id - 3) && Empty(id + 3)) {
                count++;
            }
            if (Empty(id - 1) && Empty(id - 2)) {
                count++;
            }
            break;
        case 7:
            if (Empty(id + 1) && Empty(id + 2)) {
                count++;
            }

            if (Empty(id - 3) && Empty(id - 6)) {
                count++;
            }
            if (Empty(id - 2) && Empty(id - 4)) {
                count++;
            }
            break;
        case 8:
            if (Empty(id - 1) && Empty(id + 1)) {
                count++;
            }
            if (Empty(id - 3) && Empty(id - 6)) {
                count++;
            }
            break;
        case 9:
            if (Empty(id - 1) && Empty(id - 2)) {
                count++;
            }

            if (Empty(id - 3) && Empty(id - 6)) {
                count++;
            }
            if (Empty(id - 4) && Empty(id - 8)) {
                count++;
            }
            break;
        default:
            break;
    }

    return count;
}

/**
 * Check if the new chess forms new NearlyThreat
 *
 * This is really dirty work as I don't see easy path to check the
 * entire 3 x 3 board
 * @param id is the grid id where a new chess is put
 * @param type is the chess type, O or X
 */

void Board::DetectNearlyThreat(int id, Chess::ChessType type,
                               list<NearlyThreat> &nearlyThreatList)
{
    switch (id) {
        case 1:
            if (Empty(id + 1) && Empty(id + 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 1, type),
                                           Chess(id + 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            if (Empty(id + 3) && Empty(id + 6)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 3, type),
                                           Chess(id + 6, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            if (Empty(id + 4) && Empty(id + 8)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 4, type),
                                           Chess(id + 8, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            break;
        case 2:
            if (Empty(id - 1) && Empty(id + 1)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 1, type),
                                           Chess(id + 1, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id + 3) && Empty(id + 6)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 3, type),
                                           Chess(id + 6, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 3:
            if (Empty(id - 1) && Empty(id - 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 1, type),
                                           Chess(id - 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            if (Empty(id + 2) && Empty(id + 4)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 2, type),
                                           Chess(id + 4, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id + 3) && Empty(id + 6)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 3, type),
                                           Chess(id + 6, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 4:
            if (Empty(id - 3) && Empty(id + 3)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 3, type),
                                           Chess(id + 3, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id + 1) && Empty(id + 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 1, type),
                                           Chess(id + 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 5:
            if (Empty(id - 1) && Empty(id + 1)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 1, type),
                                           Chess(id + 1, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            if (Empty(id - 3) && Empty(id + 3)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 3, type),
                                           Chess(id + 3, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id - 4) && Empty(id + 4)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 4, type),
                                           Chess(id + 4, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id - 2) && Empty(id + 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 2, type),
                                           Chess(id + 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 6:
            if (Empty(id - 3) && Empty(id + 3)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 3, type),
                                           Chess(id + 3, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id - 1) && Empty(id - 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 1, type),
                                           Chess(id - 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 7:
            if (Empty(id + 1) && Empty(id + 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id + 1, type),
                                           Chess(id + 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            if (Empty(id - 3) && Empty(id - 6)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 3, type),
                                           Chess(id - 6, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id - 2) && Empty(id - 4)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 2, type),
                                           Chess(id - 4, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 8:
            if (Empty(id - 1) && Empty(id + 1)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 1, type),
                                           Chess(id + 1, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id - 3) && Empty(id - 6)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 3, type),
                                           Chess(id - 6, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        case 9:
            if (Empty(id - 1) && Empty(id - 2)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 1, type),
                                           Chess(id - 2, type));
                nearlyThreatList.push_back(nearlyThreat);
            }

            if (Empty(id - 3) && Empty(id - 6)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 3, type),
                                           Chess(id - 6, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            if (Empty(id - 4) && Empty(id - 8)) {
                NearlyThreat nearlyThreat(Chess(id, type),
                                           Chess(id - 4, type),
                                           Chess(id - 8, type));
                nearlyThreatList.push_back(nearlyThreat);
            }
            break;
        default:
            break;
    }
}

void Board::UpdateBoardStateImpl(int id,
                                 Chess::ChessType type,
                                 list<Threat> &threatList,
                                 list<NearlyThreat> &nearlyThreatList,
                                 list<Threat> &oppoSideThreatListlist,
                                 list<NearlyThreat> &oppoSideNearlyThreatListlist)
{
    list<Threat>::iterator threatIter;
    list<NearlyThreat>::iterator nearlyThreatIter;
    /**
     * Check if this new chess breaks any opponent side Threats
     */
    for (threatIter = oppoSideThreatListlist.begin();
         threatIter != oppoSideThreatListlist.end(); threatIter++) {
        if (threatIter->missing.id == id) {
            threatIter = oppoSideThreatListlist.erase(threatIter);
        }
    }

    /**
     * Check if this new chess breaks any opponent side NearlyThreats
     */
    for (nearlyThreatIter = oppoSideNearlyThreatListlist.begin();
         nearlyThreatIter!=oppoSideNearlyThreatListlist.end();
         nearlyThreatIter++) {
        if (nearlyThreatIter->missing1.id == id ||
            nearlyThreatIter->missing2.id == id) {
            nearlyThreatIter =
                        oppoSideNearlyThreatListlist.erase(nearlyThreatIter);
        }
    }

    /**
     * Check NearlyThreats if the new chess develops new Threats
     */
    for (nearlyThreatIter = nearlyThreatList.begin();
         nearlyThreatIter != nearlyThreatList.end();
         nearlyThreatIter++) {
        if (nearlyThreatIter->missing1.id == id &&
            Empty(nearlyThreatIter->missing2.id)) {
            Threat threat(nearlyThreatIter->chess,
                          nearlyThreatIter->missing1,
                          nearlyThreatIter->missing2);
            threatList.push_back(threat);
            nearlyThreatIter = nearlyThreatList.erase(nearlyThreatIter);
        }
        else if (Empty(nearlyThreatIter->missing1.id) &&
                 nearlyThreatIter->missing2.id == id) {
            Threat threat(nearlyThreatIter->chess,
                          nearlyThreatIter->missing2,
                          nearlyThreatIter->missing1);
            threatList.push_back(threat);
            nearlyThreatIter = nearlyThreatList.erase(nearlyThreatIter);
        }
    }

    /**
     * Check if the new chess develops any NearlyThreats
     */
    DetectNearlyThreat(id, type, nearlyThreatList);
}

void Board::OSideUpdateBoardState(int id)
{
    oSideBoardStateBit |= (1 << id);
    UpdateBoardStateImpl(id, Chess::CHESS_TYPE_O,
                         oSideThreatList, oSideNearlyThreatList,
                         xSideThreatList, xSideNearlyThreatList);
}

void Board::XSideUpdateBoardState(int id)
{
    xSideBoardStateBit |= (1 << id);
    UpdateBoardStateImpl(id, Chess::CHESS_TYPE_X,
                         xSideThreatList, xSideNearlyThreatList,
                         oSideThreatList, oSideNearlyThreatList);
}

bool Board::OSideWins(int id)
{
    if (oSideThreatList.size() != 0) {
        for (list<Threat>::iterator iter = oSideThreatList.begin();
             iter != oSideThreatList.end();
             iter++) {
            if (iter->missing.id == id) {
                return true;
            }
        }
    }

    return false;
}

bool Board::Tied()
{
    int x = oSideBoardStateBit | xSideBoardStateBit;

    for (unsigned int i = 1; i <= CHESS_CNT; i++) {
        if ((x & (1 << i)) == 0) {
            return false;
        }
    }

    return true;
}
bool Board::XSideWins(int id)
{
    if (xSideThreatList.size() != 0) {
        for (list<Threat>::iterator iter = xSideThreatList.begin();
             iter != oSideThreatList.end();
             iter++) {
            if (iter->missing.id == id) {
                return true;
            }
        }
    }

    return false;
}

void Board::Freeze(bool _freezed)
{
    freezed = _freezed;
}

bool Board::Freezed()
{
    return freezed;
}
