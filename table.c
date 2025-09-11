#include <stdio.h>

int l, c, n;

//Create Vertical line for table
int line(int size){
	printf("   -");
	l = 0;
	do{
		printf("----");
		l++;
	}while(size > l);
	printf("--\n");
}

//Create Horizontal line for table
int horizontal(int size, int table[][size], int row){
	printf(" %d  |", (row+1));
	c = 0;
	do{
		printf(" %c |", table[row][c]);
		c++;
	}while(size > c);
	printf(" \n");
	return 0;
}

//Include  coloumn number
int col_no(int coloumn){
	int no = 1;
	printf("      ");
	do{
		printf("%d   ", no);
		no++;
	}while(coloumn >= no);
	printf(" \n");
	return 0;
}

int main(){

	//Get the size of table
	int size;
	printf("Enter Table Size (3 - 9):\n");
	scanf("%d", &size);
	l = 0;
	
	//intialize table with 2D array
	if(size >= 3 && size <= 9){
		int table[size][size];
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				table[i][j] = ' ';
			}
		}
		n = 0;
	

		//print row numbers over the table
		col_no(size);

		//Print the output table
		do {
			line(size);
			horizontal(size,table,n);
			n++;
		} while (size > n);
		l = 0;
		line(size);

	}

	//Ask for new input if input is wrong
       else{
		printf("Enter a Number between 3 and 9 \n");
		printf("\n");
		main();
	}
	return 0;
} 
