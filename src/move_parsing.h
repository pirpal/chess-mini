#ifndef MOVES_PARSING_H
#define MOVES_PARSING_H

#include <stdbool.h>

typedef enum PieceType {
  PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} PieceType;

#define PIECES_TYPES_STR "pRNBQK"
#define PIECES_WHITE_STR "PRNBQK"
#define PIECES_BLACK_STR "prnbqk"

#define CHECK_CHAR '+'
#define CHECKMATE_CHAR '#'
#define CAPTURE_CHAR 'x'
#define PROMOTION_CHAR '='
#define RESULT_WHITE_PREFIX "1-"
#define RESULT_BLACK_PREFIX "0-"
#define RESULT_DRAW_PREFIX "1/"

#define RANKS "87654321"
#define FILES "abcdefgh"

/* typedef enum Square { */
/*   a8, b8, c8, d8, e8, f8, g8, h8, */
/*   a7, b7, c7, d7, e7, f7, g7, h7, */
/*   a6, b6, c6, d6, e6, f6, g6, h6, */
/*   a5, b5, c5, d5, e5, f5, g5, h5, */
/*   a4, b4, c4, d4, e4, f4, g4, h4, */
/*   a3, b3, c3, d3, e3, f3, g3, h3, */
/*   a2, b2, c2, d2, e2, f2, g2, h2, */
/*   a1, b1, c1, d1, e1, f1, g1, h1 */
/* } Square; */


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

