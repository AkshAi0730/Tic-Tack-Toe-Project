#include <stdio.h>
#include <stdlib.h>

int l, c, n;

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
void horizontal(int size, char table[][size], int row){
    printf(" %d  |", (row+1));
    c = 0;
    do{
        printf(" %c |", table[row][c]);
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

//selection of Game mode
int game_mode(){
    int mode;
    printf("1. User vs Computer \n");
    printf("2. User vs User \n");
    printf("3. Three Players \n");
    printf("Select Game mode: ");
    scanf("%d", &mode);
    switch (mode){
        case 1:
        printf("Entered User vs Computer mode. \n");
        break;
        case 2:
        printf("Entered User vs User mode. \n");
        break;
        case 3:
        printf("Entered Three players mode. \n");
        break;
    }
    return mode;
}

// Print the whole table
void table_print(int size, char table[size][size]){
    col_no(size); 
    n = 0;
    do {
        line(size);
        horizontal(size,table,n);
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

//Check win state for [size]  number of identical Charecter 
int win_state(int row, int col, int size, char table[size][size], char symbol) {
	int i;

	// 1. Check row
	int count = 0;
	for (i = 0; i < size; i++) {
	if (table[row][i] == symbol)
	count++;
	}
	if (count == size) return 1;

	// 2. Check column
	count = 0;
	for (i = 0; i < size; i++) {
	if (table[i][col] == symbol)
	count++;
	}
	if (count == size) return 1;

	// 3. Check main diagonal
	if (row == col) {
	count = 0;
	for (i = 0; i < size; i++) {
	if (table[i][i] == symbol)
	count++;
	}
	if (count == size) return 1;
	}

	// 4. Check anti-diagonal
	if (row + col == size - 1) {
	count = 0;
	for (i = 0; i < size; i++) {
	if (table[i][size - 1 - i] == symbol)
	count++;
	}
	if (count == size) return 1;
	}

	// No winner yet
	return 0;
}

//user get repeated input for two or three player 
void user_input(int size,int mode, char table[size][size]){
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
}


//User vs computer input
void user_vs_computer_input(){
    
}

int main(){
    //Get the size of table
    int size;
    printf("Enter Table Size (3 - 9):\n");
    scanf("%d", &size);
    l = 0;
    
    //Check if Table size is Correct
    while(size < 3 || size > 9){
        printf("Enter a Number Between 3 and 9 : ");
        scanf("%d", &size);
    }

    int mode = game_mode();
    //Check if Game mode is Correct
    while(mode < 1 || mode > 3){
        printf("Select a Valid Game mode: ");
        scanf("%d", &mode);
    }

    //initialize table with 2D array
    char table[size][size];
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            table[i][j] = ' ';
        }
    }

    // print table
    table_print(size, table);
    
    if (mode == 1){
        user_vs_computer_input();
    }
    else{
    user_input(size, mode, table);
    }
    return 0;
}
