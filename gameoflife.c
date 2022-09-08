#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrix_size = 50;
void draw(int matrix[matrix_size][matrix_size]);
void nextGen(int matrix[matrix_size][matrix_size], int next_matrix[matrix_size][matrix_size]);
void flip(int matrix[matrix_size][matrix_size],int next_matrix[matrix_size][matrix_size]);
int neighbors(int matrix[matrix_size][matrix_size],int i,int j);


int main(){

   	int matrix[matrix_size][matrix_size];
	int next_matrix[matrix_size][matrix_size];

	time_t t;
   

   	srand((unsigned) time(&t));

   	for(int i = 0; i < matrix_size; i++) {
      	for(int j = 0; j < matrix_size; j++) {
        	next_matrix[i][j] = 0;  
		}
	}
   	for(int i = 0; i < matrix_size; i++) {
      		for(int j = 0; j < matrix_size; j++) {
			matrix[i][j] = 0;
			// om du vill ha ett flygskäpp så använd if satserna men om du vill ha ett randomized start shit så kommentera bort if satserna och ta bort kommentaren från rad framför
        		//matrix[i][j] = rand() % 2; 

			if(i == 4 && j == 4){
				matrix[i][j] = 1;
			}
			if(i == 5 && j == 5){
				matrix[i][j] = 1;
			}
			if(i == 6 && j == 5){
				matrix[i][j] = 1;
			}
			if(i == 6 && j == 4){
				matrix[i][j] = 1;
			}
			if(i == 6 && j == 3){
				matrix[i][j] = 1;
			}
		}
	}


   	draw(matrix);
   	int input;
   	int run = 1;

	while(run == 1){
   		scanf("%d",&input);
   		if (input == 1){
			printf("\n");

			nextGen(matrix,next_matrix);
			flip(matrix,next_matrix);
			draw(matrix);
   		} else{
			run = 0;
		}
	}


   	return 0;
}
void flip(int matrix[matrix_size][matrix_size],int next_matrix[matrix_size][matrix_size]){
	for(int i = 0; i < matrix_size; i++) {
      		for(int j = 0; j < matrix_size; j++) {
        		matrix[i][j] = next_matrix[i][j];
      		}
   	}
}
void draw(int matrix[matrix_size][matrix_size]){
   		for(int i = 0; i < matrix_size; i++) {
      		for(int j = 0; j < matrix_size; j++) {
        		printf("%d ", matrix[i][j]);
         			if(j == matrix_size - 1){
            			printf("\n");
         			}
      		}
   	}
}
void nextGen(int matrix[matrix_size][matrix_size], int next_matrix[matrix_size][matrix_size]){
	for(int i = 1; i < matrix_size - 1; i++) {
      		for(int j = 1; j < matrix_size - 1; j++) {
        		if (matrix[i][j] == 0){
					if(neighbors(matrix,i,j) == 3){
						next_matrix[i][j] = 1;
					}else{
						next_matrix[i][j] = 0;
					}
				}else{
					if (neighbors(matrix,i, j) == 2 || neighbors(matrix,i, j) == 3) {
                    next_matrix[i][j] = 1;
                } else {
                    next_matrix[i][j] = 0;
				}
			}
		}
	}
}
int neighbors(int matrix[matrix_size][matrix_size],int i,int j){
	int neighbors = 0;
    if (matrix[i - 1][j - 1] == 1) {
        neighbors++;
    }
    if (matrix[i - 1][j] == 1) {
        neighbors++;
    }
    if (matrix[i - 1][j + 1] == 1) {
        neighbors++;
    }
    if (matrix[i][j - 1] == 1) {
        neighbors++;
    }
    if (matrix[i][j + 1] == 1) {
        neighbors++;
    }
    if (matrix[i + 1][j - 1] == 1) {
        neighbors++;
    }
    if (matrix[i + 1][j] == 1) {
        neighbors++;
    }
    if (matrix[i + 1][j + 1] == 1) {
        neighbors++;
    }
	return neighbors;
}
