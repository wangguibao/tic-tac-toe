#ifndef CHESS_H
#define CHESS_H

struct Chess
{
    enum ChessType {CHESS_TYPE_O, CHESS_TYPE_X};
    Chess(int id_, ChessType type_): id(id_), type(type_) {}
    Chess(const Chess &rhc): id(rhc.id), type(rhc.type){}

    int id;
    ChessType type;
};

#endif // CHESS_H
