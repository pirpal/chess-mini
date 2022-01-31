#ifndef MOVES_H
#define MOVES_H

#include <stdbool.h>
#include "bitboards.h"

bool in_A_file(int square);
bool in_B_file(int square);
bool in_C_file(int square);
bool in_D_file(int square);
bool in_E_file(int square);
bool in_F_file(int square);
bool in_G_file(int square);
bool in_H_file(int square);

bool in_rank_1(int square);
bool in_rank_2(int square);
bool in_rank_3(int square);
bool in_rank_4(int square);
bool in_rank_5(int square);
bool in_rank_6(int square);
bool in_rank_7(int square);
bool in_rank_8(int square);

bool in_ranks_1_2(int square);
bool in_ranks_7_8(int square);
bool in_files_A_B(int square);
bool in_files_G_H(int square);

int square_to_rank(int square);
int square_to_file(int square);

U64 pawn_raw_moves(int square, int color);
U64 knight_raw_moves(int square);
U64 king_raw_moves(int square);

// These functions dependon static recursive functions defined in moves.c:
U64 raw_diagonal_cross(int square);
U64 raw_straight_cross(int square);

#endif // MOVES_H
