#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "tic_tac_toe.h"

static int l, c, n;

/* Memory allocation for Array */
char **allocate_board(int size){
	char **board = malloc(size * sizeof(char*));
	if (!board) {
		fprintf(stderr , "Memory allocation failed \n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < size ; ++i){
		board[i] = malloc(size *sizeof(char));
		if (!board[i]){
			fprintf(stderr, "Memory allocation failed \n");
			exit(EXIT_FAILURE);
		}
	}
	return board;
}

/* Initalizing Board */
void initialize_board(int size, char **board){
	for(int i = 0; i < size ; ++i)
		for (int j = 0; j < size ; ++j)
			board[i][j] = ' ';
}

/* Free up the memory */
void free_board(int size, char **board){
	if(!board)
		return;
	for (int i = 0; i < size; ++i) free(board[i]);
	free(board);
}

//Create Vertical line for table
void line(int size){
    printf("   -");
    l = 0;
    do{
        printf("----");
        l++;
    }while(size > l);
    printf("--\n");
}

//Create Horizontal line for table
void horizontal(int size, char **board, int row){
    printf(" %d  |", (row+1));
    c = 0;
    do{
        printf(" %c |", board[row][c]);
        c++;
    }while(size > c);
    printf(" \n");
}

//Include column number
void col_no(int coloumn){
    printf("\n");
    int no = 1;
    printf("      ");
    do{
        printf("%d   ", no);
        no++;
    }while(coloumn >= no);
    printf(" \n");
}

// Print the whole board
void print_board(int size, char **board){
    col_no(size); 
    n = 0;
    do {
        line(size);
        horizontal(size,board,n);
        n++;
    } while (size > n);
    l = 0;
    line(size);
}
////////// Win State only if 3 in row game will be ended///////////////
/*
//checking for winning posibilities with row
int check_win_row(int row, int col,int size, char table[size][size],char symbol,int player){
    int j = 0; int win = 0;

    //check left boarder
    if(row >= 2)
    {row = row-2, j = 5;}
    else if(row >= 1)
    {row = row - 1, j =4;}
    else
    {row =row, j = 3;}

    //check right border
    if(row + 2 >= size){
        j = j;}
    else if(row + 1 >= size){
        j = j-1;}
    else{
        j = j-2;}

    int i = 0;
    //check win condition of row
    do {
            if((table[row][col] == symbol)&& (table[row+1][col] == symbol) && (table[row+2][col] == symbol))
	    {printf("PLayer %d with %c won the game \n",player,symbol);
		    win = 1;
		    return win;}
    row++, i++;
    }while(i < j);
    return win;
}

//checking for winning posibilities with column
int check_win_col(int row, int col,int size, char table[size][size],char symbol,int player){
    int j = 0; int win = 0;

    //check top border
    if(col >= 2)
    {col = col-2, j = 5;}
    else if(col >= 1)
    {col = col - 1, j =4;}
    else
    {col =col, j = 3;}

    //check bottom border
    if(col + 2 >= size){
        j = j;}
    else if(col + 1 >= size){
        j = j-1;}
    else{
        j = j-2;}

    int i = 0;
    //check win condition of column
    do {
            if((table[row][col] == symbol) && (table[row][col+1] == symbol) && (table[row][col+2] == symbol))
	    {printf("player %d with %c won the game",player,symbol);
		    win = 1;
		    return win;}
    col++ ; i++;
    } while(i < j);
    return win;
}

 checking for winning posibilities with diagonal like 1 1 , 2 2 , 3 3 
int check_win_diagonal_1(int row, int col,int size, char table[size][size],char symbol,int player){
    int  j = 0; int win = 0;

    //check top and right border
    if(row >= 2 && col >= 2)
    {row = row-2,col = col-2, j = 5;}
    else if(row >= 1 && col >= 1)
    {row = row - 1,col = col -1, j =4;}
    else
    {col = col, row = row, j = 3;}

    //check bottom and left border
    if((row + 2 >= size) && (col + 2 >= size))
        j = j;
    else if((row + 1 >= size) && (col + 1 >= size))
        j = j-1;
    else
        j = j-2;

    int i = 0;
    //check win condition of diagonal_1
    do{
    if((table[row][col] == symbol) && (table[row+1][col+1] == symbol) && (table[row+2][col+2] == symbol))
    	{printf("player %d with %c won the game.\n", player, symbol);
	win = 1;
	return win;}
    row++; col++ ; i++;
    } while(i < j);
    return win;
}

checking for winning posibilities with diaoganal like 1 3, 2 2 , 3 1 
int check_win_diagonal_2(int row, int col,int size, char table[size][size],char symbol,int player){
    int j = 0; int win = 0;

    //check top and right border
    if(row >= 2 && col >= 2)
    {row = row-2,col = col+2, j = 5;}
    else if(row >= 1 && col >= 1)
    {row = row - 1,col = col+1, j = 3;}
    else
    {row = row, col = col, j = 1;}

    //check bottom and left border
    if((row + 2 >= size) && (col + 2 >= size))
        j = j;
    else if((row + 1 >= size) && (col + 1 >= size))
        j = j-1;
    else
        j = j-2;

    int i = 0;
    //check win condition of diagonal_2
    do {
            if((table[row][col] == symbol) && (table[row+1][col-1] ==symbol) && (table [row+2][col-2] == symbol))
	    {printf("player %d with %c won the game",player,symbol);
		    win = 1;
		    return win;}
    row++, col-- , i++;
    } while(i < j);
    return win;
}

//checking for winner of the game combined row , column , dioganal_1 , dioganal_2
int win_state(int row, int col, int size,  char table[size][size],char symbol,int num){
    return check_win_diagonal_1(row, col, size, table, symbol, num) || 
	    check_win_diagonal_2(row, col, size, table, symbol, num) || 
	    check_win_row(row, col, size, table, symbol, num) || 
	    check_win_col(row, col, size, table, symbol, num);
}
*/

/* Logging */
void clear_input_buffer(void){
	int ch;
	while ((ch= getchar()) != '\n' && ch != EOF){}
}

int validate_move(int size, char **board, int row, int col){
	if (row < 0 || row >= size || col < 0 || col >= size) return 0;
	if (board[row][col] != ' ') return 0;
	return 1;
}

void place_move_at(int size, char **board, int row, int col, char symbol){
	(void)size;
	board[row][col] = symbol;
}


//Check win state for [size]  number of identical Charecter 
int check_win(int row, int col, int size, char **board, char symbol) {
	int i;

	// 1. Check row
	int count = 0;
	for (i = 0; i < size; i++) {
	if (board[row][i] == symbol)
	count++;
	}
	if (count == size) return 1;

	// 2. Check column
	count = 0;
	for (i = 0; i < size; i++) {
	if (board[i][col] == symbol)
	count++;
	}
	if (count == size) return 1;

	// 3. Check main diagonal
	if (row == col) {
	count = 0;
	for (i = 0; i < size; i++) {
	if (board[i][i] == symbol)
	count++;
	}
	if (count == size) return 1;
	}

	// 4. Check anti-diagonal
	if (row + col == size - 1) {
	count = 0;
	for (i = 0; i < size; i++) {
	if (board[i][size - 1 - i] == symbol)
	count++;
	}
	if (count == size) return 1;
	}

	// No winner yet
	return 0;
}

int check_draw(int size, char **board){
	for(int r = 0; r < size; ++r)
		for(int c = 0; c < size; ++c)
			if(board[r][c] == ' ') return 0;
	return 1;
}

// ----- logging ----- //
void log_board(int size, char **board, int move_number, char player){
	FILE *f = fopen("game_log.txt", "a");
	if (!f) return;
	fprintf(f, "\nMove %d by player %c:\n", move_number, player);

	// Print column headers
	fprintf(f, "    ");
	for (int col = 1; col <= size; ++col)
		fprintf(f, " %d  ", col);
	fprintf(f, "\n");

	// Print each row
	for (int r = 0; r < size; ++r){
		fprintf(f, "   -");
		for (int k = 0; k < size; ++k)
			 fprintf(f, "----");
		fprintf(f, "--\n");

		fprintf(f, " %d  |", r+1);
		for (int c = 0; c < size; ++c){
			fprintf(f, " %c |", board[r][c]);
		}
			fprintf(f, "\n");
		}

	// Bottom line
	fprintf(f, "   -");
	for (int k = 0; k < size; ++k) fprintf(f, "----");
		fprintf(f, "--\n");

	fclose(f);
}



/*user get repeated input for two or three player 
void get_user_input(int size,int mode, char table[size][size]){
    char player1 = 'X'; char player2 = 'O'; char symbol; char player3 = 'Z';int turn = 0;
    int col; int row; int done = 0;

    //switch player turn for get input
    do {
        switch (turn % mode){
            //get input for user 1
            case 1:{
                printf("Enter row and column player %c (N N): ", player2);
                scanf("%d %d", &row, &col);
                symbol = player2;
                break;}
            //get input for user 2
            case 0:{
                printf("Enter row and column player %c (N N): ", player1);
                scanf("%d %d", &row, &col);
                symbol = player1;
                break;}
            case 2:{
                printf("Enter row and column player %c (N N): ", player3);
                scanf("%d %d", &row, &col);
                symbol = player3;
                break;}
            }
            int num = (turn % mode) + 1;
            turn++;
	    row = row-1 ; col = col-1;

        // place symbol in table
        if(row >=0 && row < size && col >=0 && col < size) {
            if (table[row][col] == ' ') {
                table[row][col] = symbol;  // update board
            } else {
                turn--;
                printf("Cell already taken!\n");
            }
        } else {
            turn--;
           printf("Invalid position!\n");
        }
	
	//checking win state
	done = win_state(row, col, size, table, symbol);
	if (done == 1){
	printf("Player %d with %c Wins! \n", num, symbol);
	break;
	}
	//print updated table
        table_print(size, table);

	if(done == 1){
		printf("Game Over! Player %d wins. \n", num);
		break;}
    }while (turn < size*size);
}*/

// get user input //
void get_user_move(int size, char **board, int *row, int *col, char player_symbol){
	int r, c;
	while (1){
		printf("Player %c - Enter row and column (N N): ", player_symbol);
		if (scanf("%d %d", &r, &c) !=2){
			printf("Invalid input. Please enter two integers.\n");
			clear_input_buffer();
			continue;
		}
		clear_input_buffer();
		r--; c--; //convert move starts from 0 to size
		if (!validate_move(size, board, r, c)){
			 printf("Invalid move or cell already taken. Try again.\n");
			continue;
		}
		*row = r; *col = c;
		return;
	}
}

// get computer inputs //
void get_computer_move(int size, char **board, int *row, int *col){
	int total = 0;
	int maxcells = size * size;
	int *list = malloc(maxcells * 2 * sizeof(int)); /* store r,c pairs */
	if (!list) exit(EXIT_FAILURE);
	for (int r = 0; r < size; ++r){
		for(int c = 0; c < size; ++c){
			if(board[r][c] == ' '){
				list[2 * total] = r;
				list[2 * total + 1] = c;
				++total;
			}
		}
	}
	
	if (total == 0){
	free(list);
	*row = -1; *col = -1;
	return;
	}

	int pick = rand() % total;
	*row = list[2 * pick];
	*col = list[2 * pick + 1];
	free(list);
}



/* ---------- Game modes ---------- */

// player vs player //
void play_user_vs_user(int size, char **board){
	char players[2] = {'X','O'};
	int current = 0; /* 0 -> X, 1 -> O */
	int move_number = 0;
	int r, c;
	while (1){
		print_board(size, board);
		get_user_move(size, board, &r, &c, players[current]);
		place_move_at(size, board, r, c, players[current]);
		move_number++;
		log_board(size, board, move_number, players[current]);
		if (check_win(r, c, size, board, players[current])){
			print_board(size, board);
			printf("Player %c wins after move %d!\n", players[current], move_number);
			return;
		}
		if (check_draw(size, board)){
			print_board(size, board);
			printf("Game is a draw after %d moves.\n", move_number);
			 return;
		}
	current = 1 - current;
	}
}

// player vs computer  //
void play_user_vs_computer(int size, char **board){
	char user = 'X', comp = 'O';
	int current = 0; /* 0 -> user, 1 -> comp */
	int move_number = 0;
	int r, c;
	while (1){
		print_board(size, board);
		if (current == 0){
			get_user_move(size, board, &r, &c, user);
		} else {
			printf("Computer (%c) is making a move...\n", comp);
			get_computer_move(size, board, &r, &c);
		}
		place_move_at(size, board, r, c, current == 0 ? user : comp);
		move_number++;
		log_board(size, board, move_number, current == 0 ? user : comp);
		if (check_win(r, c, size, board, current == 0 ? user : comp)){
			print_board(size, board);
			printf("%s wins after move %d!\n", current == 0 ? "Player X" : "Computer O", move_number);
		return;
		}
		if (check_draw(size, board)){
		print_board(size, board);
		printf("Game is a draw after %d moves.\n", move_number);
		return;
		}
	current = 1 - current;
	}
}


void play_three_players(int size, char **board){
	char symbols[3] = {'X','O','Z'};
	int roles[3] = {0, 0, 0}; /* 0=human,1=computer */
	int move_number = 0;

/* Ask user role configuration for players 2 and 3 (player 1 is human) */
	printf("Configure players for three-player mode:\n");
	for (int p = 1; p < 3; ++p){
		int sel = -1;
		do {
			printf("Player %d (%c): 0 = human, 1 = computer (default 0): ", p+1, symbols[p]);
			if (scanf("%d", &sel) != 1) { clear_input_buffer(); sel = -1; continue; }
			clear_input_buffer();
			if (sel != 0 && sel != 1) { sel = -1; }
		} while (sel == -1);
	roles[p] = sel;
	}
	roles[0] = 0; /* Player 1 is human always */

	int current = 0;
	while (1){
		print_board(size, board);
		int r = -1, c = -1;
		if (roles[current] == 0){
			get_user_move(size, board, &r, &c, symbols[current]);
		} else {
			printf("Computer player %c is making a move...\n", symbols[current]);
			get_computer_move(size, board, &r, &c);
        	}
		place_move_at(size, board, r, c, symbols[current]);
		move_number++;
		log_board(size, board, move_number, symbols[current]);
		if (check_win(r, c, size, board, symbols[current])){
			print_board(size, board);
			printf("Player %c wins after move %d!\n", symbols[current], move_number);
			return;
		}
		if (check_draw(size, board)){
			print_board(size, board);
			printf("Game is a draw after %d moves.\n", move_number);
			return;
		}
		current = (current + 1) % 3;
	}
}

/* game-mode selection */
int game_mode(){
	int mode;
	printf("\nSelect game mode:\n");
	printf("1. User vs Computer\n");
	printf("2. User vs User\n");
	printf("3. Three Players\n");
	do {
		printf("Select Game mode (1-3): ");
		if (scanf("%d", &mode) != 1) { clear_input_buffer(); mode = -1; continue; }
		clear_input_buffer();
	} while (mode < 1 || mode > 3);
	return mode;
}

// ----- The Game begins ----- //
int main(){
	//Get the size of table
	int size;
	printf("Enter Table Size (3 - 9):\n");
	scanf("%d", &size);
    
    //Check if Board size is Correct
	while(size < 3 || size > 9){
		clear_input_buffer();
		printf("Enter a Number Between 3 and 9 : ");
		scanf("%d", &size);
	}
	clear_input_buffer();
	
	srand((unsigned)time(NULL));

	char **board = allocate_board(size);
	initialize_board(size, board);

	/* clear previous log file so logs start fresh */
	FILE *f = fopen("game_log.txt", "w");
	if (f) {
		fprintf(f, "Tic-Tac-Toe game log (board size: %d)\n", size);
		fclose(f);
	}

	int mode = game_mode();
	//Check if Game mode is Correct
	if (mode == 1){
		play_user_vs_computer(size, board);
	}else if (mode == 2){
		play_user_vs_user(size, board);
	}else {
		play_three_players(size, board);
	}

	free_board(size, board);
	printf("Game finished. See game_log.txt for full move log.\n");
    return 0;
}

