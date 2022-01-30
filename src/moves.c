
#include "moves.h"
#include "bitboards.h"

bool in_A_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & A_FILE) ? true: false;
}

bool in_B_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & B_FILE) ? true: false;
}

bool in_C_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & C_FILE) ? true: false;
}

bool in_D_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & D_FILE) ? true: false;
}

bool in_E_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & E_FILE) ? true: false;
}

bool in_F_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & F_FILE) ? true: false;
}

bool in_G_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & G_FILE) ? true: false;
}

bool in_H_file(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & H_FILE) ? true: false;
}

bool in_rank_1(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_1) ? true: false;
}

bool in_rank_2(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_2) ? true: false;
}

bool in_rank_3(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_3) ? true: false;
}

bool in_rank_4(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_4) ? true: false;
}

bool in_rank_5(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_5) ? true: false;
}

bool in_rank_6(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_6) ? true: false;
}

bool in_rank_7(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_7) ? true: false;
}

bool in_rank_8(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  return (bb & RANK_8) ? true: false;
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

U64 pawn_raw_moves(int square, int color)
{
  // return 0 if pawn in rank 1 or 8
  // white pawn: rank 1 forbidden, promote on rank 8 
  // black pawn: rank 8 forbidden, promote on rank 1
  if (in_rank_1(square) || in_rank_8(square))
    return 0ULL;
  U64 bb = 0ULL;;
  set_bit(bb, square);
  U64 moves = 0ULL;
  if (!color) { // if WHITE
    if (in_rank_2(square)) { // first move
      moves |= (bb >> 8);  // 1 square move
      moves |= (bb >> 16); // 2 squares move
    }
    if (!in_A_file(square))
      moves |= (bb >> 9);
    if (!in_H_file(square))
      moves |= (bb >> 7);
  } else {      // if BLACK
    if (in_rank_7(square)) { // first move        
      moves |= (bb << 8);  // 1 square move
      moves |= (bb << 16); // 2 squares move
    }
    if (!in_A_file(square))
      moves |= (bb << 7);
    if (!in_H_file(square))
      moves |= (bb << 9);
  }
  return moves;
}

U64 knight_raw_moves(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  U64 moves = 0ULL;
  // directions :
  if (!in_ranks_1_2(square) && !in_H_file(square)) // OK
    moves |= (bb << 17); // Se
  if (!in_ranks_1_2(square) && !in_A_file(square)) // OK */
    moves |= (bb << 15); // Sw
  if (!in_rank_1(square) && !in_files_A_B(square))
    moves |= (bb << 6); // Ws
  if (!in_rank_8(square) && !in_files_A_B(square)) // OK */
    moves |= (bb >> 10); // Wn
  if (!in_ranks_7_8(square) && !in_A_file(square)) // OK
    moves |= (bb >> 17); // Nw
  if (!in_ranks_7_8(square) && !in_H_file(square)) // OK
    moves |= (bb >> 15); // Ne
  if (!in_rank_8(square) && !in_files_G_H(square)) // OK
    moves |= (bb >> 6); // En
  if (!in_rank_1(square) && !in_files_G_H(square)) // OK
    moves |= (bb << 10); // Es

  return moves;
}

