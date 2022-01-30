#include <stdlib.h>
#include <stdio.h>
#include "bitboards.h"
#include "moves.h"
#include "move_parsing.h"


int main(void)
{
  printf("\n\t+-------------------------+");
  printf("\n\t|    Mini Chess Engine    |");
  printf("\n\t+-------------------------+\n\n");

  printf("\n\n\tKnight a4 raw moves:\n");
  U64 bb = knight_raw_moves(h4);
  print_bitboard(bb);

  printf("\n\n");
  return EXIT_SUCCESS;
}
