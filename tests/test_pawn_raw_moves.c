#include <criterion/criterion.h>
#include "../src/type_alias.h"
#include "../src/chess_helpers.h"
#include "../src/bit_operations.h"
#include "../src/moves.h"

Test(pawn_raw_moves, wp_e4)
{
  U64 pawn_moves = pawn_raw_moves(e4, WHITE);
  U64 expected = 0ULL;
  set_bit(expected, d5);
  set_bit(expected, f5);
  cr_expect(pawn_moves == expected, "White pawn e4 raw moves = (d5, f5)");
}

Test(pawn_raw_moves, wp_e2)
{
  U64 moves = pawn_raw_moves(e2, WHITE);
  U64 expected = 0ULL;
  set_bit(expected, e3);
  set_bit(expected, e4);
  set_bit(expected, d3);
  set_bit(expected, f3);
  cr_expect(moves == expected, "White pawn e2 raw moves = (e3, e4, d3, f3)");
}

Test(pawn_raw_moves, wp_e1)
{
  U64 moves = pawn_raw_moves(e1, WHITE);
  cr_expect(moves == 0, "White pawn e1 (forbidden) raw moves = 0");
}

Test(pawn_raw_moves, wp_e8)
{
  U64 moves = pawn_raw_moves(e8, WHITE);
  cr_expect(moves == 0, "White pawn e8 (promotion) raw moves = 0");
}

Test(pawn_raw_moves, bp_e8)
{
  U64 moves = pawn_raw_moves(e8, BLACK);
  cr_expect(moves == 0, "Black pawn e8 (forbidden) raw moves = 0");
}

Test(pawn_raw_moves, bp_e1)
{
  U64 moves = pawn_raw_moves(e1, BLACK);
  cr_expect(moves == 0, "Black pawn e1 (promotion) raw moves = 0");
}

Test(pawn_raw_moves, wp_a2)
{
  U64 moves = pawn_raw_moves(a2, WHITE);
  U64 expected = 0ULL;
  set_bit(expected, a3);
  set_bit(expected, a4);
  set_bit(expected, b3);
  cr_expect(moves == expected, "White pawn a2 raw moves = (a3, a4, b3)");
}

Test(pawn_raw_moves, wp_h2)
{
  U64 moves = pawn_raw_moves(h2, WHITE);
  U64 expected = 0ULL;
  set_bit(expected, h3);
  set_bit(expected, h4);
  set_bit(expected, g3);
  cr_expect(moves == expected, "White pawn h2 raw moves = (h3, h4, g3)");
}

Test(pawn_raw_moves, bp_a7)
{
  U64 moves = pawn_raw_moves(a7, BLACK);
  U64 expected = 0ULL;
  set_bit(expected, a6);
  set_bit(expected, a5);
  set_bit(expected, b6);
  cr_expect(moves == expected, "Black pawn a7 raw moves = (a6, a5, b6)");
}

Test(pawn_raw_moves, bp_h7)
{
  U64 moves = pawn_raw_moves(h7, BLACK);
  U64 expected = 0ULL;
  set_bit(expected, h6);
  set_bit(expected, h5);
  set_bit(expected, g6);
  cr_expect(moves == expected, "Black pawn h7 raw moves = (h6, h5, g6)");
}

Test(pawn_raw_moves, bp_d7)
{
  U64 moves = pawn_raw_moves(d7, BLACK);
  U64 expected = 0ULL;
  set_bit(expected, d6);
  set_bit(expected, d5);
  set_bit(expected, c6);
  set_bit(expected, e6);
  cr_expect(moves == expected, "Black e7 pawn moves = (d6, d5, c6, e6)");
}

Test(pawn_raw_moves, bp_e5)
{
  U64 moves = pawn_raw_moves(e5, BLACK);
  U64 expected = 0ULL;
  set_bit(expected, d4);
  set_bit(expected, f4);
  cr_expect(moves == expected, "Black e5 pawn moves = (d4, f4)");
}
