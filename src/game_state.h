#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdbool.h>
#include "type_alias.h"
#include "chess_helpers.h"
#include "bit_operations.h"

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
  // move, regardless of whether or not there is an opponent pawn
  // to take en passant.
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


#endif // GAME_STATE_H

