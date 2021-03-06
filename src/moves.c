#include "type_alias.h"
#include "bit_operations.h"
#include "ranks_files.h"
#include "moves.h"


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

static U64 diagonal_nw_rec(U64 bb, int square)
{
  if (in_A_file(square) || (in_rank_8(square)) || square < 0) {
    return bb;
  }
  square -= 9;
  bb |= (bb >> 9);
  return diagonal_nw_rec(bb, square);
}

static U64 diagonal_ne_rec(U64 bb, int square)
{
  if (in_H_file(square) || (in_rank_8(square)) || square < 0) {
    return bb;
  }
  square -= 7;
  bb |= (bb >> 7);
  return diagonal_ne_rec(bb, square);
}

static U64 diagonal_sw_rec(U64 bb, int square)
{
  if (in_A_file(square) || (in_rank_1(square)) || square > 63) {
    return bb;
  }
  square += 7;
  bb |= (bb << 7);
  return diagonal_sw_rec(bb, square);
}

static U64 diagonal_se_rec(U64 bb, int square)
{
  if (in_H_file(square) || (in_rank_1(square)) || square > 63) {
    return bb;
  }
  square += 9;
  bb |= (bb << 9);
  return diagonal_se_rec(bb, square);
}

U64 raw_diagonal_cross(int square)
{
  U64 piece_bb = 0ULL;
  set_bit(piece_bb, square);
  U64 nw = diagonal_nw_rec(piece_bb, square);
  U64 ne = diagonal_ne_rec(piece_bb, square);
  U64 sw = diagonal_sw_rec(piece_bb, square);
  U64 se = diagonal_se_rec(piece_bb, square);
  U64 moves = nw | ne | sw | se;
  pop_bit(moves, square); // remove piece bit
  return moves;
}

static U64 straight_north_rec(U64 bb, int square)
{
  if (in_rank_8(square) || square < 0) {
    return bb;
  }
  square -= 8;
  bb |= (bb >> 8);
  return straight_north_rec(bb, square);
}

static U64 straight_south_rec(U64 bb, int square)
{
  if (in_rank_1(square) || square > 63) {
    return bb;
  }
  square += 8;
  bb |= (bb << 8);
  return straight_south_rec(bb, square);
}

static U64 straight_west_rec(U64 bb, int square)
{
  if (in_A_file(square) || square < 0) {
    return bb;
  }
  square -= 1;
  bb |= (bb >> 1);
  return straight_west_rec(bb, square);
}

static U64 straight_east_rec(U64 bb, int square)
{
  if (in_H_file(square) || square > 63) {
    return bb;
  }
  square += 1;
  bb |= (bb << 1);
  return straight_east_rec(bb, square);
}

U64 raw_straight_cross(int square)
{
  U64 bb = 0ULL;
  set_bit(bb, square);
  U64 n = straight_north_rec(bb, square);
  U64 s = straight_south_rec(bb, square);
  U64 w = straight_west_rec(bb, square);
  U64 e = straight_east_rec(bb, square);
  U64 moves = n | w | s | e;
  pop_bit(moves, square); // remove piece bit
  return moves;
}

