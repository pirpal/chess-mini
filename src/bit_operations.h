#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

/* 
 * Macros and functions prototypes for bitwise operations.
 * Some functions like square_from() do not operate on bitboards
 * but are used for these functions.
 * 
 * */

#include "type_alias.h"
#include "game_state.h"


#define get_bit(bb, sq) (bb & (1ULL << sq))

#define set_bit(bb, sq) (bb |= (1ULL << sq))

#define pop_bit(bb, sq) (get_bit(bb, sq) ? bb ^= (1ULL << sq) : 0)

#define square_from(r, f) (r * 8 + f)

#define rank_from_square(sq) (sq / 8)

#define file_from_square(sq) (sq - (sq / 8))

int count_bits(U64 bb);

U64 populate_bitboard(int *squares);

U64 white_occupancy(GameState *fbb);

U64 black_occupancy(GameState *fbb);


#endif // BIT_OPERATIONS_H
