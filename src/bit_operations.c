#include <stdarg.h>
#include "bit_operations.h"

int count_bits(U64 bb)
{
  int count = 0;
  for (int rank = 0; rank < 8; rank ++) {
    for (int file = 0; file < 8; file++) {
      int square = square_from(rank, file);
      if (get_bit(bb, square)) {
        count += 1;
      }
    }
  }
  return count;
}

U64 fill_bb_with(int squares_nb, ...)
{
  U64 bb = 0ULL;
  va_list squares_list;
  int square;
  va_start(squares_list, squares_nb);
  for (int i = 0; i < squares_nb; i++) {
    square = va_arg(squares_list, int);
    bb |= (1ULL << square);
  }
  va_end(squares_list);
  return bb;
}

U64 white_occupancy(GameState *game_state)
{
  U64 occupancy = game_state->w_pawns;
  occupancy |= game_state->w_rooks;
  occupancy |= game_state->w_knights;
  occupancy |= game_state->w_bishops;
  occupancy |= game_state->w_queens;
  occupancy |= game_state->w_king;
  return (occupancy);
}

U64 black_occupancy(GameState *game_state)
{
  U64 occupancy = game_state->b_pawns;
  occupancy |= game_state->b_rooks;
  occupancy |= game_state->b_knights;
  occupancy |= game_state->b_bishops;
  occupancy |= game_state->b_queens;
  occupancy |= game_state->b_king;
  return (occupancy);
}

