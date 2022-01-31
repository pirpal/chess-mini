#ifndef RANKS_FILES_H
#define RANKS_FILES_H

#include <stdbool.h>

/* 
 * Boolean functions to determine bit presence in a specific rank,
 * file or set of ranks or files.
 * */

bool in_A_file(int square);
bool in_B_file(int square);
bool in_C_file(int square);
bool in_D_file(int square);
bool in_E_file(int square);
bool in_F_file(int square);
bool in_G_file(int square);
bool in_H_file(int square);
bool in_files_A_B(int square);
bool in_files_G_H(int square);

bool in_rank_1(int square);
bool in_rank_2(int square);
bool in_rank_3(int square);
bool in_rank_4(int square);
bool in_rank_5(int square);
bool in_rank_6(int square);
bool in_rank_7(int square);
bool in_rank_8(int square);
bool in_ranks_1_2(int square);
bool in_ranks_7_8(int square);


#endif // RANKS_FILES_H
