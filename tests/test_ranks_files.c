#include <criterion/criterion.h>
#include "../src/moves.h"
#include "../src/bitboards.h"

Test(test_ranks_files, ranks)
{
  cr_expect(in_rank_1(a1) == true, "a1 should be in rank 1");
  cr_expect(in_rank_1(d2) == false, "d2 should not be in rank 1");

  cr_expect(in_rank_2(b2) == true, "b2 should be in rank 2");
  cr_expect(in_rank_2(c7) == false, "c7 should not be in rank 2");

  cr_expect(in_rank_3(c3) == true, "c3 should be in rank 1");
  cr_expect(in_rank_3(f8) == false, "f8 should not be in rank 1");

  cr_expect(in_rank_4(d4) == true, "d4 should be in rank 3");
  cr_expect(in_rank_4(b5) == false, "b5 should not be in rank 3");

  cr_expect(in_rank_5(e5) == true, "e5 should be in rank 4");
  cr_expect(in_rank_5(g8) == false, "g8 should not be in rank 4");

  cr_expect(in_rank_6(f6) == true, "f6 should be in rank 5");
  cr_expect(in_rank_6(e1) == false, "e1 should not be in rank 5");

  cr_expect(in_rank_7(g7) == true, "g7 should be in rank 6");
  cr_expect(in_rank_7(g6) == false, "g6 should not be in rank 6");

  cr_expect(in_rank_8(h8) == true, "h8 should be in rank 7");
  cr_expect(in_rank_8(a7) == false, "a7 should not be in rank 7");
}


Test(test_ranks_files, files)
{
  cr_expect(in_A_file(a1) == true, "a1 should be in A file");
  cr_expect(in_A_file(d2) == false, "d2 should not be in A file");

  cr_expect(in_B_file(b2) == true, "b2 should be in B file");
  cr_expect(in_B_file(c7) == false, "c7 should not be in B file");

  cr_expect(in_C_file(c3) == true, "c3 should be in C file");
  cr_expect(in_C_file(f8) == false, "f8 should not be in C file");

  cr_expect(in_D_file(d4) == true, "d4 should be in D file");
  cr_expect(in_D_file(b5) == false, "b5 should not be in D file");

  cr_expect(in_E_file(e5) == true, "e5 should be in E file");
  cr_expect(in_E_file(g8) == false, "g8 should not be in E file");

  cr_expect(in_F_file(f6) == true, "f6 should be in F file");
  cr_expect(in_F_file(e1) == false, "e1 should not be in F file");

  cr_expect(in_G_file(g7) == true, "g7 should be in G file");
  cr_expect(in_G_file(a6) == false, "a6 should not be in G file");

  cr_expect(in_H_file(h8) == true, "h8 should be in H file");
  cr_expect(in_H_file(a7) == false, "a7 should not be in H file");
}
