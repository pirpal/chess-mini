#include <criterion/criterion.h>
#include "../src/bitboards.h"
#include "../src/moves.h"

Test(test_straight_lines, a1)
{
  U64 moves = raw_straight_cross(a1);
  U64 expected = 0ULL;
  set_bit(expected, b1);
  set_bit(expected, c1);
  set_bit(expected, d1);
  set_bit(expected, e1);
  set_bit(expected, f1);
  set_bit(expected, g1);
  set_bit(expected, h1);
  set_bit(expected, a2);
  set_bit(expected, a3);
  set_bit(expected, a4);
  set_bit(expected, a5);
  set_bit(expected, a6);
  set_bit(expected, a7);
  set_bit(expected, a8);
  cr_expect(moves == expected, "Straight moves from a1");
}

Test(test_straight_lines, h8)
{
  U64 moves = raw_straight_cross(h8);
  U64 expected = 0ULL;
  set_bit(expected, a8);
  set_bit(expected, b8);
  set_bit(expected, c8);
  set_bit(expected, d8);
  set_bit(expected, e8);
  set_bit(expected, f8);
  set_bit(expected, g8);
  set_bit(expected, h7);
  set_bit(expected, h6);
  set_bit(expected, h5);
  set_bit(expected, h4);
  set_bit(expected, h3);
  set_bit(expected, h2);
  set_bit(expected, h1);
  cr_expect(moves == expected, "Straight moves from h8");
}

Test(test_straight_lines, e4)
{
  U64 moves = raw_straight_cross(e4);
  U64 expected = 0ULL;
  set_bit(expected, e8);
  set_bit(expected, e7); //   a b c d e f g h 
  set_bit(expected, e6); // 8 . . . . @ . . . 8
  set_bit(expected, e5); // 7 . . . . @ . . . 7
  set_bit(expected, e3); // 6 . . . . @ . . . 6
  set_bit(expected, e2); // 5 . . . . @ . . . 5
  set_bit(expected, e1); // 4 @ @ @ @ . @ @ @ 4
  set_bit(expected, a4); // 3 . . . . @ . . . 3
  set_bit(expected, b4); // 2 . . . . @ . . . 2
  set_bit(expected, c4); // 1 . . . . @ . . . 1
  set_bit(expected, d4); //   a b c d e f g h
  set_bit(expected, f4);
  set_bit(expected, g4);
  set_bit(expected, h4);
  cr_expect(moves == expected, "Straight moves from e4");
}
