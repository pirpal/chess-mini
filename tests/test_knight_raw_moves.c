#include <criterion/criterion.h>
#include "../src/bitboards.h"
#include "../src/moves.h"

// CORNERS
Test(knight_raw_moves, Na8)
{
  U64 moves = knight_raw_moves(a8);
  U64 expected = 0ULL;
  set_bit(expected, b6);
  set_bit(expected, c7);
  cr_expect(moves == expected, "Na8 raw moves = (b6, c7)");
}

Test(knight_raw_moves, Nh8)
{
  U64 moves = knight_raw_moves(h8);
  U64 expected = 0ULL;
  set_bit(expected, f7);
  set_bit(expected, g6);
  cr_expect(moves == expected, "Nh8 raw moves = (g6, f7)");
}

Test(knight_raw_moves, Nh1)
{
  U64 moves = knight_raw_moves(h1);
  U64 expected = 0ULL;
  set_bit(expected, f2);
  set_bit(expected, g3);
  cr_expect(moves == expected, "Nh1 raw moves = (f2, g3)");
}

Test(knight_raw_moves, Na1)
{
  U64 moves = knight_raw_moves(a1);
  U64 expected = 0ULL;
  set_bit(expected, c2);
  set_bit(expected, b3);
  cr_expect(moves == expected, "Na1 raw moves = (c2, b3)");
}

// QUASI CORNERS (1): a2, a7, b8, g8, h7, h2, g1, b1
Test(knight_raw_moves, Na2)
{
  U64 moves = knight_raw_moves(a2);
  U64 expected = 0ULL;
  set_bit(expected, b4);
  set_bit(expected, c3);
  set_bit(expected, c1);
  cr_expect(moves == expected, "Na2 raw moves = (b4, c3, c1)");
}

Test(knight_raw_moves, Na7)
{
  U64 moves = knight_raw_moves(a7);
  U64 expected = 0ULL;
  set_bit(expected, b5);
  set_bit(expected, c6);
  set_bit(expected, c8);
  cr_expect(moves == expected, "Na7 raw moves = (b5, c6, c8)");
}

Test(knight_raw_moves, Nb8)
{
  U64 moves = knight_raw_moves(b8);
  U64 expected = 0ULL;
  set_bit(expected, a6);
  set_bit(expected, c6);
  set_bit(expected, d7);
  cr_expect(moves == expected, "Nb8 raw moves = (a6, c6, d7)");
}

Test(knight_raw_moves, Ng8)
{
  U64 moves = knight_raw_moves(g8);
  U64 expected = 0ULL;
  set_bit(expected, e7);
  set_bit(expected, f6);
  set_bit(expected, h6);
  cr_expect(moves == expected, "Ng8 raw moves = (e7, f6, h6)");
}

Test(knight_raw_moves, Nh7)
{
  U64 moves = knight_raw_moves(h7);
  U64 expected = 0ULL;
  set_bit(expected, f8);
  set_bit(expected, f6);
  set_bit(expected, g5);
  cr_expect(moves == expected, "Nh7 raw moves = (f8, f6, g5)");
}

Test(knight_raw_moves, Nh2)
{
  U64 moves = knight_raw_moves(h2);
  U64 expected = 0ULL;
  set_bit(expected, f1);
  set_bit(expected, f3);
  set_bit(expected, g4);
  cr_expect(moves == expected, "Nh2 raw moves = (f1, f3, g4)");
}

Test(knight_raw_moves, Ng1)
{
  U64 moves = knight_raw_moves(g1);
  U64 expected = 0ULL;
  set_bit(expected, e2);
  set_bit(expected, f3);
  set_bit(expected, h3);
  cr_expect(moves == expected, "Ng1 raw moves = (e2, f3, h3)");
}

Test(knight_raw_moves, Nb1)
{
  U64 moves = knight_raw_moves(b1);
  U64 expected = 0ULL;
  set_bit(expected, a3);
  set_bit(expected, c3);
  set_bit(expected, d2);
  cr_expect(moves == expected, "Nb1 raw moves = (a3, c3, d2)");
}
// QUASI CORNERS (2): b2, b7, g2, g7

Test(knight_raw_moves, Nb2)
{
  U64 moves = knight_raw_moves(b2);
  U64 expected = 0ULL;
  set_bit(expected, a4);
  set_bit(expected, c4);
  set_bit(expected, d3);
  set_bit(expected, d1);
  cr_expect(moves == expected, "Nb2 raw moves = (a4, c4, d3, d1)");
}

Test(knight_raw_moves, Nb7)
{
  U64 moves = knight_raw_moves(b7);
  U64 expected = 0ULL;
  set_bit(expected, a5);
  set_bit(expected, c5);
  set_bit(expected, d6);
  set_bit(expected, d8);
  cr_expect(moves == expected, "Nb7 raw moves = (a5, c5, d6, d8)");
}

Test(knight_raw_moves, Ng2)
{
  U64 moves = knight_raw_moves(g2);
  U64 expected = 0ULL;
  set_bit(expected, e1);
  set_bit(expected, e3);
  set_bit(expected, f4);
  set_bit(expected, h4);
  cr_expect(moves == expected, "Ng2 raw moves = (e1, e3, f4, h4)");
}

Test(knight_raw_moves, Ng7)
{
  U64 moves = knight_raw_moves(g7);
  U64 expected = 0ULL;
  set_bit(expected, e6);
  set_bit(expected, e8);
  set_bit(expected, f5);
  set_bit(expected, h5);
  cr_expect(moves == expected, "Ng7 raw moves = (e6, e8, f5, h5)");
}

// SIDES : d1, a4, e8, h5
Test(knight_raw_moves, Nd1)
{
  U64 moves = knight_raw_moves(d1);
  U64 expected = 0ULL;
  set_bit(expected, b2);
  set_bit(expected, c3);
  set_bit(expected, e3);
  set_bit(expected, f2);
  cr_expect(moves == expected, "Nd1 raw moves = (b2, c3, e3, f2)");
}

Test(knight_raw_moves, Na4)
{
  U64 moves = knight_raw_moves(a4);
  U64 expected = 0ULL;
  set_bit(expected, b2);
  set_bit(expected, b6);
  set_bit(expected, c3);
  set_bit(expected, c5);
  cr_expect(moves == expected, "Na4 raw moves = (b2, b6, c3, c5)");
}

Test(knight_raw_moves, Ne8)
{
  U64 moves = knight_raw_moves(e8);
  U64 expected = 0ULL;
  set_bit(expected, c7);
  set_bit(expected, d6);
  set_bit(expected, f6);
  set_bit(expected, g7);
  cr_expect(moves == expected, "Ne8 raw moves = (c7, d6, f6, g7)");
}

Test(knight_raw_moves, Nh5)
{
  U64 moves = knight_raw_moves(h5);
  U64 expected = 0ULL;
  set_bit(expected, g3);
  set_bit(expected, g7);
  set_bit(expected, f4);
  set_bit(expected, f6);
  cr_expect(moves == expected, "Nh5 raw moves = (g3, g7, f4, f6)");
}

// Finally a center board example
Test(knight_raw_moves, Ne4)
{
  U64 moves = knight_raw_moves(e4);
  U64 expected = 0ULL;
  set_bit(expected, d2);
  set_bit(expected, c3);
  set_bit(expected, c5);
  set_bit(expected, d6);
  set_bit(expected, f6);
  set_bit(expected, g5);
  set_bit(expected, g3);
  set_bit(expected, f2);
  cr_expect(moves == expected, "Ne4 raw moves = (d2, c3, c5, d6, f6, g5, g3, f2)");
}

