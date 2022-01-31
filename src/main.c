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

  printf("\n\tOccupancies\n");
  int wp_count = count_bits(W_PAWNS);
  printf("\n\tThere are %d white pawns\n", wp_count);

  printf("\n\n");
  return EXIT_SUCCESS;
}
