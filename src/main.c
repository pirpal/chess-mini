#include <stdlib.h>
#include <stdio.h>
#include "bitboards.h"
#include "bit_operations.h"
#include "console_output.h"
#include "moves.h"
#include "move_parsing.h"


int main(void)
{
  printf("\n\t+-------------------------+");
  printf("\n\t|    Mini Chess Engine    |");
  printf("\n\t+-------------------------+\n\n");

  printf("\n\tTest fill_bb_with\n");
  U64 bb = fill_bb_with(8, a1, b2, c3, d4, e5, f6, g7, h8);
  print_bitboard(bb);


  printf("\n\n");
  return EXIT_SUCCESS;
}
