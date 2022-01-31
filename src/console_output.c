#include <stdio.h>
#include "console_output.h"
#include "chess_helpers.h"
#include "bit_operations.h" // get_bit(), square_from()

void print_files(void)
{
  printf("\t  ");
  for (int i = 0; i < 8; i++) {
    printf("%c ", FILES_STR[i]);
  }
}

void print_bitboard(U64 bb)
{
  print_files();
  printf("\n");
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      if (!file) { // if file A
        printf("\t%c ", RANKS_STR[rank]);
      }
      int square = square_from(rank, file);
      if (get_bit(bb, square)) {
        printf("%c ", BIT_CHAR);
      }
      else {
        printf("%c ", EMPTY_SQUARE_CHAR);
      }
      if ((file + 1) % 8 == 0)
        printf("%c", RANKS_STR[rank]);
    }
    printf("\n");
  }
  print_files();
  printf("\n\n\tbb: %llu\n", bb);
}

