#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdio.h>

/// Board allocation ///
char **allocate_board(int size);
void initialize_board(int size, char **board);
void free_board(int size, char **board);

/// Displaying the board and Logging ///
void print_board(int size, char **board);
void log_board(int size, char **board, int move_number, char player);

/// Get and Check for valid Move ///
int validate_move(int size, char **board, int row, int col);
void place_move(int size, char **board, int *row, int col, char symbol);

/// Input Functions ///
void get_user_move(int size, char **board, int *row, int *col, char player_symbol);
void get_computer_move(int size, char **board, int *row, int *col);

/// Game Flow Win or Draw ///
int check_win(int row, int col, int size, char **board, char symbol);
int check_draw(int size, char **board);

/// Game Mode ///
void play_user_vs_user(int size, char **board);
void play_user_vs_computer(int size, char **board);
void play_three_players(int size, char **board);

/// Utility ///
void clear_input_buffer(void);

#endif
