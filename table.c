#include <stdio.h>

int l, c, n;

int line(int size){
	printf("   -");
	l = 0;
	do{
		printf("----");
		l++;
	}while(size > l);
	printf("--\n");
}
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

int main(){
	int size;
	printf("Enter Table Size (3 - 9):\n");
	scanf("%d", &size);
	l = 0;

	if(size >= 3 && size <= 9){
		int table[size][size];
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				table[i][j] = ' ';
			}
		}
		n = 0;
	
		do {
			line(size);
			horizontal(size,table,n);
			n++;
		} while (size > n);
		l = 0;
		line(size);
	} else{
		printf("Enter a Number between 3 and 9 \n");
		printf("\n");
		main();
	}
	return 0;
} 
