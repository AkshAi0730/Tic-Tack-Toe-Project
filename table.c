#include <stdio.h>

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

//user get repeated input for two or three player 
void user_input(int size,int mode, char table[size][size]){
    char player1 = 'X'; char player2 = 'O'; char symbol; char player3 = 'Z';
    int col; int row;
    int turn = 0;
    
    //switch player turn for get input
    do {
        switch (turn % mode){
            //get input for user 1
            case 1:{
                printf("Enter row and coloumn player %c (N N): ", player2);
                scanf("%d %d", &row, &col);
                symbol = player2;
                break;}
            //get input for user 2
            case 0:{
                printf("Enter row and coloumn player %c (N N): ", player1);
                scanf("%d %d", &row, &col);
                symbol = player1;
                break;}
            case 2:{
                printf("Enter row and coloumn player %c (N N): ", player3);
                scanf("%d %d", &row, &col);
                symbol = player3;
                break;}
            }
            turn++;
    
        // place symbol in table
        if(row >=1 && row <= size && col >=1 && col <= size) {
            if (table[row-1][col-1] == ' ') {
                table[row-1][col-1] = symbol;  // update board
            } else {
                turn--;
                printf("Cell already taken!\n");
            }
        } else {
            turn--;
            printf("Invalid position!\n");
        }
            table_print(size, table);
    }while (turn < size*size);
}

//User vs computer input
void user_vs_computer_input(){
    
}

void main(){
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
}
