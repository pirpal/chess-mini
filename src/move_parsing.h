#ifndef MOVES_PARSING_H
#define MOVES_PARSING_H

#include <stdbool.h>


bool pawn_move(char *move);

bool rook_move(char *move);

bool knight_move(char *move);

bool bishop_move(char *move);

bool queen_move(char *move);

bool king_move(char *move);

bool checkmate_move(char *move);

bool check_move(char *move);

bool capture_move(char *move);

bool promotion_move(char *move);


#endif // MOVES_PARSING_H

