#include <stdio.h>
#include "bitboards.h"

void print_files(void)
{
  printf("\t  ");
  for (int i = 0; i < 8; i++) {
    printf("%c ", FILES[i]);
  }
}

void print_bitboard(U64 bb)
{
  print_files();
  printf("\n");
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      if (!file) {
        /* if file A */
        printf("\t%c ", RANKS[rank]);
      }
      int square = square_from(rank, file);
      if (get_bit(bb, square)) {
        printf("%c ", BIT_CHAR);
      }
      else {
        printf("%c ", EMPTY_SQUARE);
      }
      if ((file + 1) % 8 == 0)
        printf("%c", RANKS[rank]);
    }
    printf("\n");
  }
  print_files();
  printf("\n\n\tbb: %llu\n", bb);
}

U64 white_occupancy(FullBitboard *fbb)
{
  U64 wo = fbb->w_pawns;
  wo &= fbb->w_rooks;
  wo &= fbb->w_knights;
  wo &= fbb->w_bishops;
  wo &= fbb->w_queens;
  wo &= fbb->w_king;
  return (wo);
}

U64 black_occupancy(FullBitboard *fbb)
{
  U64 bo = fbb->b_pawns;
  bo &= fbb->b_rooks;
  bo &= fbb->b_knights;
  bo &= fbb->b_bishops;
  bo &= fbb->b_queens;
  bo &= fbb->b_king;
  return (bo);
}

