#include <criterion/criterion.h>
#include "../src/type_alias.h"
#include "../src/chess_helpers.h"
#include "../src/bit_operations.h"
#include "../src/moves.h"

Test(test_raw_diagonals, a8)
{
  // Long diagonal a8-h1
  U64 bb = raw_diagonal_cross(a8);
  U64 expected = 0ULL;
  set_bit(expected, b7);
  set_bit(expected, c6);
  set_bit(expected, d5);
  set_bit(expected, e4);
  set_bit(expected, f3);
  set_bit(expected, g2);
  set_bit(expected, h1);
  cr_expect(bb == expected, "Raw diagonal from a8");
}

Test(test_raw_diagonals, a1)
{
  // Long diagonal a1-h8
  U64 bb = raw_diagonal_cross(a1);
  U64 expected = 0ULL;
  set_bit(expected, b2);
  set_bit(expected, c3);
  set_bit(expected, d4);
  set_bit(expected, e5);
  set_bit(expected, f6);
  set_bit(expected, g7);
  set_bit(expected, h8);
  cr_expect(bb == expected, "Raw diagonal from a1");
}

Test(test_raw_diagonals, e6)
{
  // a centered case
  U64 bb = raw_diagonal_cross(e6);
  U64 expected = 0ULL;
  set_bit(expected, c8); //   a b c d e f g h
  set_bit(expected, d7); // 8 . . @ . . . @ . 8
  set_bit(expected, f5); // 7 . . . @ . @ . . 7
  set_bit(expected, g4); // 6 . . . . x . . . 6
  set_bit(expected, h3); // 5 . . . @ . @ . . 5
  set_bit(expected, a2); // 4 . . @ . . . @ . 4
  set_bit(expected, b3); // 3 . @ . . . . . @ 3 
  set_bit(expected, c4); // 2 @ . . . . . . . 2
  set_bit(expected, d5); // 1 . . . . . . . . 1
  set_bit(expected, f7); //   a b c d e f g h
  set_bit(expected, g8); // bb: 424704217196612
  cr_expect(bb == expected, "Raw diagonal from e6");
}
