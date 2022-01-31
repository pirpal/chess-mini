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


  printf("\n\tTrying rec function:\n");
  U64 cross_f3 = raw_straight_cross(e4);
  printf("\n\tRaw cross from f3:\n");
  print_bitboard(cross_f3);

  printf("\n\n");
  return EXIT_SUCCESS;
}
