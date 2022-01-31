#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <stdbool.h>

#define U64 unsigned long long

#define get_bit(bb, sq) (bb & (1ULL << sq))

#define set_bit(bb, sq) (bb |= (1ULL << sq))

#define pop_bit(bb, sq) (get_bit(bb, sq) ? bb ^= (1ULL << sq) : 0)

#define square_from(r, f) (r * 8 + f)

typedef enum Color {WHITE, BLACK} Color;

typedef enum Piece
{
  empty, 
  wp, wN, wB, wR, wQ, wK, 
  bp, bN, bB, bR, bQ, bK
} Piece;

// These are for console printing functions:
#define PIECES ".pnbrqkPNBRQK"

#define EMPTY_SQUARE '.'
#define BIT_CHAR '@'

#define FILES "abcdefgh"

#define RANKS "87654321"


/*  LSB (Least Significant Bit), 2^0, is in "a8"
 *  in standard "white bottom" display.
 *  MSB (Most Significant Bit) ,2^63, is in "h1".
 *  
 *    0  1  2  3  4  5  6  7
 *    8  9 10 11 12 13 14 15
 *   16 17 18 19 20 21 22 23
 *   24 25 26 27 28 29 30 31
 *   32 33 34 35 36 37 38 39
 *   40 41 42 43 44 45 46 47
 *   48 49 50 51 52 53 54 55
 *   56 57 58 59 60 61 62 63
*/

#define W_PAWNS 71776119061217280ULL
#define W_ROOKS 9295429630892703744ULL
#define W_KNIGHTS 4755801206503243776ULL
#define W_BISHOPS 2594073385365405696ULL
#define W_QUEENS 576460752303423488ULL
#define W_KING 1152921504606846976ULL

#define B_PAWNS 65280ULL
#define B_ROOKS 129ULL
#define B_KNIGHTS 66ULL
#define B_BISHOPS 36ULL
#define B_QUEENS 8ULL
#define B_KING 16ULL

#define A_FILE 72340172838076673ULL
#define B_FILE 144680345676153346ULL
#define C_FILE 289360691352306692ULL
#define D_FILE 578721382704613384ULL
#define E_FILE 1157442765409226768ULL
#define F_FILE 2314885530818453536ULL
#define G_FILE 4629771061636907072ULL
#define H_FILE 9259542123273814144ULL

#define AB_FILES 217020518514230019ULL
#define GH_FILES 13889313184910721216ULL

#define RANK_1 18374686479671623680ULL
#define RANK_2 71776119061217280ULL
#define RANK_3 280375465082880ULL
#define RANK_4 1095216660480ULL
#define RANK_5 4278190080ULL
#define RANK_6 16711680ULL
#define RANK_7 65280ULL
#define RANK_8 255ULL

#define RANKS_12 18446462598732840960ULL
#define RANKS_78 65535ULL

typedef enum Square
{
  a8, b8, c8, d8, e8, f8, g8, h8,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a1, b1, c1, d1, e1, f1, g1, h1
} Square;


/* GameState
 * This structure is created/updated after each move.
 * Its purpose is to store:
 * - all current bitboards
 * - castling availability
 * - en passant square
 * - half moves clock (nb of half moves since last capture or 
 *   last pawn move)
 * - fullmove number
 * */
typedef struct GameState
{
  // bitboards:
  U64 w_pawns, w_rooks, w_knights, w_bishops, w_queens, w_king;
  U64 b_pawns, b_rooks, b_knights, b_bishops, b_queens, b_king;
  // En passant square ; by default en passant is always set and
  // recorded in game state when a pawn make a two squares first
  // move, regardless of whether or there is an opponent pawn to 
  // take en passant.
  Square en_passant; // Square | NULL
  // Active color to play in this position:
  Color color_to_play;
  bool w_castle_kingside;
  bool w_castle_queenside;
  bool b_castle_kingside;
  bool b_castle_queenside;
  unsigned int half_moves;
  unsigned int full_moves;

} GameState;

int count_bits(U64 bb);
void print_files(void);
void print_bitboard(U64 bb);
U64 populate_bitboard(int *squares);
U64 white_occupancy(GameState *fbb);
U64 black_occupancy(GameState *fbb);


#endif // BITBOARDS_H
