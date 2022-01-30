#include <stdio.h>
#include <string.h>
#include "move_parsing.h"


bool pawn_move(char *move)
{
  bool pawn = false;
  for (int i = 0; i < 8; i++) {
    if (FILES[i] == move[0])
      return true;
  }
  return pawn;
}


bool rook_move(char *move)
{
  return (move[0] == PIECES_TYPES_STR[ROOK]);
}


bool knight_move(char *move)
{
  return (move[0] == PIECES_TYPES_STR[KNIGHT]);
}


bool bishop_move(char *move)
{
  return (move[0] == PIECES_TYPES_STR[BISHOP]);
}


bool queen_move(char *move)
{
  return (move[0] == PIECES_TYPES_STR[QUEEN]);
}


bool king_move(char *move)
{
  return (move[0] == PIECES_TYPES_STR[KING]);
}


bool checkmate_move(char *move)
{
  for (unsigned int i = 0; i < strlen(move); i++) {
    if (move[i] == CHECKMATE_CHAR)
      return true;
  }
  return false;
}


bool check_move(char *move)
{
  for (unsigned int i = 0; i < strlen(move); i++) {
    if (move[i] == CHECK_CHAR)
      return true;
  }
  return false;
}

bool capture_move(char *move)
{
  for (unsigned int i = 0; i < strlen(move); i++) {
    if (move[i] == CAPTURE_CHAR)
      return true;
  }
  return false;
}


bool promotion_move(char *move)
{
  for (unsigned int i = 0; i < strlen(move); i++) {
    if (move[i] == PROMOTION_CHAR)
      return true;
  }
  return false;
}

