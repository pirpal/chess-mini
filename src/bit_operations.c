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

U64 populate_bitboard(int *squares)
{
  // FIXME only first square is set when it's dont
  // with this function. Tested outside of the function,
  // the for loops behaves correctly.
  U64 bb = 0ULL;
  for (unsigned int i = 0; i < (sizeof(squares) / sizeof(int)); i++)
  {
    bb |= (1ULL << squares[i]);
  }
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

