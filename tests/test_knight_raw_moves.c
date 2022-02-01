#include <criterion/criterion.h>
#include "../src/type_alias.h"
#include "../src/chess_helpers.h"
#include "../src/bit_operations.h"
#include "../src/moves.h"

// CORNERS
Test(knight_raw_moves, Na8)
{
  U64 moves = knight_raw_moves(a8);
  U64 expected = fill_bb_with(2, b6, c7);
  cr_expect(moves == expected, "Na8 raw moves = (b6, c7)");
}

Test(knight_raw_moves, Nh8)
{
  U64 moves = knight_raw_moves(h8);
  U64 expected = fill_bb_with(2, f7, g6);
  cr_expect(moves == expected, "Nh8 raw moves = (g6, f7)");
}

Test(knight_raw_moves, Nh1)
{
  U64 moves = knight_raw_moves(h1);
  U64 expected = fill_bb_with(2, f2, g3);
  cr_expect(moves == expected, "Nh1 raw moves = (f2, g3)");
}

Test(knight_raw_moves, Na1)
{
  U64 moves = knight_raw_moves(a1);
  U64 expected = fill_bb_with(2, c2, b3);
  cr_expect(moves == expected, "Na1 raw moves = (c2, b3)");
}

// QUASI CORNERS (1): a2, a7, b8, g8, h7, h2, g1, b1
Test(knight_raw_moves, Na2)
{
  U64 moves = knight_raw_moves(a2);
  U64 expected = fill_bb_with(3, b4, c3, c1);
  cr_expect(moves == expected, "Na2 raw moves = (b4, c3, c1)");
}

Test(knight_raw_moves, Na7)
{
  U64 moves = knight_raw_moves(a7);
  U64 expected = fill_bb_with(3, b5, c6, c8);
  cr_expect(moves == expected, "Na7 raw moves = (b5, c6, c8)");
}

Test(knight_raw_moves, Nb8)
{
  U64 moves = knight_raw_moves(b8);
  U64 expected = fill_bb_with(3, a6, c6, d7);
  cr_expect(moves == expected, "Nb8 raw moves = (a6, c6, d7)");
}

Test(knight_raw_moves, Ng8)
{
  U64 moves = knight_raw_moves(g8);
  U64 expected = fill_bb_with(3, e7, f6, h6);
  cr_expect(moves == expected, "Ng8 raw moves = (e7, f6, h6)");
}

Test(knight_raw_moves, Nh7)
{
  U64 moves = knight_raw_moves(h7);
  U64 expected = fill_bb_with(3, f8, f6, g5);
  cr_expect(moves == expected, "Nh7 raw moves = (f8, f6, g5)");
}

Test(knight_raw_moves, Nh2)
{
  U64 moves = knight_raw_moves(h2);
  U64 expected = fill_bb_with(3, f1, f3, g4);
  cr_expect(moves == expected, "Nh2 raw moves = (f1, f3, g4)");
}

Test(knight_raw_moves, Ng1)
{
  U64 moves = knight_raw_moves(g1);
  U64 expected = fill_bb_with(3, e2, f3, h3);
  cr_expect(moves == expected, "Ng1 raw moves = (e2, f3, h3)");
}

Test(knight_raw_moves, Nb1)
{
  U64 moves = knight_raw_moves(b1);
  U64 expected = fill_bb_with(3, a3, c3, d2);
  cr_expect(moves == expected, "Nb1 raw moves = (a3, c3, d2)");
}
// QUASI CORNERS (2): b2, b7, g2, g7

Test(knight_raw_moves, Nb2)
{
  U64 moves = knight_raw_moves(b2);
  U64 expected = fill_bb_with(4, a4, c4, d3, d1);
  cr_expect(moves == expected, "Nb2 raw moves = (a4, c4, d3, d1)");
}

Test(knight_raw_moves, Nb7)
{
  U64 moves = knight_raw_moves(b7);
  U64 expected = fill_bb_with(4, a5, c5, d6, d8);
  cr_expect(moves == expected, "Nb7 raw moves = (a5, c5, d6, d8)");
}

Test(knight_raw_moves, Ng2)
{
  U64 moves = knight_raw_moves(g2);
  U64 expected = fill_bb_with(4, e1, e3, f4, h4);
  cr_expect(moves == expected, "Ng2 raw moves = (e1, e3, f4, h4)");
}

Test(knight_raw_moves, Ng7)
{
  U64 moves = knight_raw_moves(g7);
  U64 expected = fill_bb_with(4, e6, e8, f5, h5);
  cr_expect(moves == expected, "Ng7 raw moves = (e6, e8, f5, h5)");
}

// SIDES : d1, a4, e8, h5
Test(knight_raw_moves, Nd1)
{
  U64 moves = knight_raw_moves(d1);
  U64 expected = fill_bb_with(4, b2, c3, e3, f2);
  cr_expect(moves == expected, "Nd1 raw moves = (b2, c3, e3, f2)");
}

Test(knight_raw_moves, Na4)
{
  U64 moves = knight_raw_moves(a4);
  U64 expected = fill_bb_with(4, b2, b6, c3, c5);
  cr_expect(moves == expected, "Na4 raw moves = (b2, b6, c3, c5)");
}

Test(knight_raw_moves, Ne8)
{
  U64 moves = knight_raw_moves(e8);
  U64 expected = fill_bb_with(4, c7, d6, f6, g7);
  cr_expect(moves == expected, "Ne8 raw moves = (c7, d6, f6, g7)");
}

Test(knight_raw_moves, Nh5)
{
  U64 moves = knight_raw_moves(h5);
  U64 expected = fill_bb_with(4, g3, g7, f4, f6);
  cr_expect(moves == expected, "Nh5 raw moves = (g3, g7, f4, f6)");
}

// Finally a center board example
Test(knight_raw_moves, Ne4)
{
  U64 moves = knight_raw_moves(e4);
  U64 expected = fill_bb_with(8, d2, c3, c5, d6, f6, g5, g3, f2);
  cr_expect(moves == expected, "Ne4 raw moves = (d2, c3, c5, d6, f6, g5, g3, f2)");
}

