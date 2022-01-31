#include "type_alias.h"
#include "bitboards.h"
#include "ranks_files.h"
#include "bit_operations.h"

bool in_A_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & A_FILE) ? true : false;
}

bool in_B_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & B_FILE) ? true : false;
}

bool in_C_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & C_FILE) ? true : false;
}

bool in_D_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & D_FILE) ? true : false;
}

bool in_E_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & E_FILE) ? true : false;
}

bool in_F_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & F_FILE) ? true : false;
}

bool in_G_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & G_FILE) ? true : false;
}

bool in_H_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & H_FILE) ? true : false;
}

bool in_rank_1(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_1) ? true : false;
}

bool in_rank_2(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_2) ? true : false;
}

bool in_rank_3(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_3) ? true : false;
}

bool in_rank_4(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_4) ? true : false;
}

bool in_rank_5(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_5) ? true : false;
}

bool in_rank_6(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_6) ? true : false;
}

bool in_rank_7(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_7) ? true : false;
}

bool in_rank_8(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_8) ? true : false;
}

bool in_ranks_1_2(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANKS_12) ? true : false;
}

bool in_ranks_7_8(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANKS_78) ? true : false;

}

bool in_files_A_B(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & AB_FILES) ? true : false;
}

bool in_files_G_H(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & GH_FILES) ? true : false;
}
