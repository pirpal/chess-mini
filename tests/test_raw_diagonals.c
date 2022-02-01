#include <criterion/criterion.h>
#include "../src/type_alias.h"
#include "../src/chess_helpers.h"
#include "../src/bit_operations.h"
#include "../src/moves.h"

Test(test_raw_diagonals, a8)
{
  // Long diagonal a8-h1
  U64 bb = raw_diagonal_cross(a8);
  U64 expected = fill_bb_with(7, b7, c6, d5, e4, f3, g2, h1);
  cr_expect(bb == expected, "Raw diagonal from a8");
}

Test(test_raw_diagonals, a1)
{
  // Long diagonal a1-h8
  U64 bb = raw_diagonal_cross(a1);
  U64 expected = fill_bb_with(7, b2, c3, d4, e5, f6, g7, h8);
  cr_expect(bb == expected, "Raw diagonal from a1");
}

Test(test_raw_diagonals, e6)
{
  // a centered case
  U64 bb = raw_diagonal_cross(e6);
  U64 expected = fill_bb_with(11, c8, d7, f5, g4, h3, a2, b3, c4, d5, f7, g8);
  cr_expect(bb == expected, "Raw diagonal from e6");
}
