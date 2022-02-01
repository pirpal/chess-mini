#include <criterion/criterion.h>
#include "../src/type_alias.h"
#include "../src/chess_helpers.h"
#include "../src/bit_operations.h"
#include "../src/moves.h"

Test(test_straight_lines, a1)
{
  U64 moves = raw_straight_cross(a1);
  U64 expected = fill_bb_with(14, b1, c1, d1, e1, f1, g1, h1, a2, a3, a4, a5, a6, a7, a8);
  cr_expect(moves == expected, "Straight moves from a1");
}

Test(test_straight_lines, h8)
{
  U64 moves = raw_straight_cross(h8);
  U64 expected = fill_bb_with(14, a8, b8, c8, d8, e8, f8, g8, h7, h6, h5, h4, h3, h2, h1);
  cr_expect(moves == expected, "Straight moves from h8");
}

Test(test_straight_lines, e4)
{
  U64 moves = raw_straight_cross(e4);
  U64 expected = fill_bb_with(14, e8, e7, e6, e5, e3, e2, e1, a4, b4, c4, d4, f4, g4, h4);
  cr_expect(moves == expected, "Straight moves from e4");
}
