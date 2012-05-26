#ifndef BOARD_H
#define BOARD_H
#include <list>
#include "Threat.h"
#include "NearlyThreat.h"

using namespace std;

class Board
{
public:
    enum WhichSideTurn {O_SIDE_TURN, X_SIDE_TURN};
public:
    Board();
    ~Board();

    void InitBoard();
    void OSideUpdateBoardState(int id);
    void XSideUpdateBoardState(int id);
    bool OSideWins(int id);
    bool XSideWins(int id);
    bool Tied();
    void Freeze(bool _freezed);
    bool Freezed();
    int XSideMove();
    const list<Threat>& GetOThreatList() const {return oSideThreatList;}
    const list<Threat>& GetXThreatList() const {return xSideThreatList;}
    const list<NearlyThreat>& GetONearlyThreatList() const
    {
        return oSideNearlyThreatList;
    }
    const list<NearlyThreat>& GetXNearlyThreatList() const
    {
        return xSideNearlyThreatList;
    }
    bool Empty (int gridId) const;
    int TryDetectNearlyThreat(int id) const;
    WhichSideTurn GetWhichSideTurn() const {return whichSideTurn;}
    void FlipWhichSideTurn()
    {
        if (whichSideTurn == O_SIDE_TURN) {
            whichSideTurn = X_SIDE_TURN;
        }
        else {
            whichSideTurn = O_SIDE_TURN;
        }
    }

private:
    void DetectNearlyThreat(int id, Chess::ChessType type,
                            list<NearlyThreat> &nearlyThreatList);
    void UpdateBoardStateImpl(int id,Chess::ChessType type,
                              list<Threat> &threat_list,
                              list<NearlyThreat> &nearlyThreatList,
                              list<Threat> &oppoSideThreatListlist,
                              list<NearlyThreat> &oppoSideNearlyThreatListlist);
public:
    static const unsigned int ROW_WIDTH = 3;
    static const unsigned int COL_HEIGHT = 3;
    static const unsigned int CHESS_CNT = 9;
private:
    bool freezed;
    WhichSideTurn whichSideTurn;        // Which side is going to play
    int oSideBoardStateBit;             // Bit-represented board state for each
    int xSideBoardStateBit;             // side, one bit for one position
    list<Threat> oSideThreatList;       // Threat conditions formed by O chesses
    list<Threat> xSideThreatList;       // Threat conditions formed by X chesses
    list<NearlyThreat> oSideNearlyThreatList;//Nearly-threats formed by O chesse
    list<NearlyThreat> xSideNearlyThreatList;//Nearly-threats formed by X chesse
};

#endif // BOARD_H
