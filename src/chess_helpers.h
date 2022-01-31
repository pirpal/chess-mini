#ifndef CHESS_HELPERS_H
#define CHESS_HELPERS_H


// ------------------------------------------------------------------
// Console output strings
// ------------------------------------------------------------------
#define PIECES_WHITE_STR "PRNBQK"
#define PIECES_BLACK_STR "prnbqk"
#define FILES_STR "abcdefgh"
#define RANKS_STR "87654321"
#define EMPTY_SQUARE_CHAR '.'
#define BIT_CHAR '@'


// ------------------------------------------------------------------
// Moves parsing strings
// ------------------------------------------------------------------

// Piece type string for move_parsing functions
// Pawn is not present since a pawn is always designated
// with its destination square, rank or file.
#define PIECES_TYPES_STR "RNBQK"
typedef enum PieceType {
  ROOK, KNIGHT, BISHOP, QUEEN, KING
} PieceType;

#define CHECK_CHAR '+'
#define CHECKMATE_CHAR '#'
#define CAPTURE_CHAR 'x'
#define PROMOTION_CHAR '='
#define RESULT_WHITE_STR "1-0"
#define RESULT_BLACK_STR "0-1"
#define RESULT_DRAW_STR "1/2-1/2"


// ------------------------------------------------------------------
// Enums and structs
// ------------------------------------------------------------------
typedef enum Color {WHITE, BLACK} Color;

typedef enum Piece
{
  empty, 
  wp, wN, wB, wR, wQ, wK, 
  bp, bN, bB, bR, bQ, bK
} Piece;

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


#endif // CHESS_HELPERS_H

