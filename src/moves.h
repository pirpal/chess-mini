#ifndef MOVES_H
#define MOVES_H

#include "type_alias.h"


U64 pawn_raw_moves(int square, int color);

U64 knight_raw_moves(int square);

U64 king_raw_moves(int square);

// These functions depend on static recursive functions defined in moves.c:
U64 raw_diagonal_cross(int square);

U64 raw_straight_cross(int square);

#endif // MOVES_H
