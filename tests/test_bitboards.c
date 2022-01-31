#include <criterion/criterion.h>
#include "../src/bitboards.h"

Test(bitboards_tests, pawns_nb)
{
  int w_pawns_nb = count_bits(W_PAWNS);
  cr_expect(w_pawns_nb == 8, "White should start with 8 pawns");
  int b_pawns_nb = count_bits(B_PAWNS);
  cr_expect(b_pawns_nb == 8, "Black should start with 8 pawns");
}

Test(bitboards_tests, rooks_nb)
{
  int w_rooks_nb = count_bits(W_ROOKS);
  cr_expect(w_rooks_nb == 2, "White should start with 2 rooks");
  int b_rooks_nb = count_bits(B_ROOKS);
  cr_expect(b_rooks_nb == 2, "Black should start with 2 rooks");
}

Test(bitboards_tests, knights_nb)
{
  int w_knights_nb = count_bits(W_KNIGHTS);
  cr_expect(w_knights_nb == 2, "White should start with 2 knights");
  int b_knights_nb = count_bits(B_KNIGHTS);
  cr_expect(b_knights_nb == 2, "Black should start with 2 knights");
}

Test(bitboards_tests, bishops_nb)
{
  int w_bishops_nb = count_bits(W_BISHOPS);
  cr_expect(w_bishops_nb == 2, "White should start with 2 bishops");
  int b_bishops_nb = count_bits(B_BISHOPS);
  cr_expect(b_bishops_nb == 2, "Black should start with 2 bishops");
}

Test(bitboards_tests, queens_nb)
{
  int w_queens_nb = count_bits(W_QUEENS);
  cr_expect(w_queens_nb == 1, "White should start with 1 queen");
  int b_queens_nb = count_bits(B_QUEENS);
  cr_expect(b_queens_nb == 1, "Black should start with 1 queen");
}

Test(bitboards_tests, kings_nb)
{
  int w_kings_nb = count_bits(W_KING);
  cr_expect(w_kings_nb == 1, "White should start with 1 king");
  int b_kings_nb = count_bits(B_KING);
  cr_expect(b_kings_nb == 1, "Black should start with 1 king");
}
