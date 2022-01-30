#include <criterion/criterion.h>
#include "../src/bitboards.h"
#include "../src/move_parsing.h"


Test(move_parsing_tests, pawn_move)
{
  cr_expect(pawn_move("e4") == true, "e4 is a pawn move");
}

Test(move_parsing_tests, rook_move)
{
  cr_expect(rook_move("Rad2") == true, "Rad2 is a rook move");
}


Test(move_parsing_tests, knight_move)
{
  cr_expect(knight_move("Nf3") == true, "Nf3 is a knight move");
}


Test(move_parsing_tests, bishop_move)
{
  cr_expect(bishop_move("Bxf7+") == true, "Bxf7+ is a bishop move");
}


Test(move_parsing_tests, queen_move)
{
  cr_expect(queen_move("Qa5") == true, "Qa5 is a queen move");
}


Test(move_parsing_tests, king_move)
{
  cr_expect(king_move("Kxf7") == true, "Kxf7 is a king move");
}

Test(move_parsing_tests, check_move)
{
  cr_expect(check_move("Bxf7+") == true, "Bxf7+ is a check move");
  cr_expect(check_move("Nxe5") == false, "Nxe5 is not a check move");
}

Test(move_parsing_tests, checkmate_move)
{
  cr_expect(checkmate_move("Qg4#") == true, "Qg4# is a checkmate move");
  cr_expect(checkmate_move("c5") == false, "c5 is not a checkmate move");
}

Test(move_parsing_tests, capture_move)
{
  cr_expect(capture_move("Bxf6") == true, "Bxf6 is a capture move");
  cr_expect(capture_move("Nc3") == false, "Nc3 is not a capture move");
}


Test(move_parsing_tests, promotion_move)
{
  cr_expect(promotion_move("a8=Q") == true, "a8=Q is a promotion move");
  cr_expect(promotion_move("a7") == false, "a7 is not a promotion move");
}
