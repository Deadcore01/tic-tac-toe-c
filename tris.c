#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define X 3
#define Y 3

// prototipazione funzioni

int counter(int count);

void printCount(int c);

void print(char grid[X][Y]);

bool input(char *pcell, char plr);

bool victory(char grid[X][Y]);
// main, inizializzo le variabili, chiamo le funzioni
int main() {
	bool bl = false;
	bool win = false;
	char player;
	int count = 1;
	int k;
	char grid[X][Y] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '} 
	};

	
	for(int i = 1; i <= 9; i++) {
		k = 0;
		k = count % 2;
		if(k == 1) {
			player = 'X';

		}
		else if(k == 0) {
			player = 'O';
		}
		print(grid);
		bl = input(&grid[0][0], player);
		if(bl == true) {
			count = counter(count);
		}
		win = victory(grid);
		if(win == true) {
			if( k == 1) {
				printf("player 1 has won!!\n");
				print(grid);
				printf("\n");
				return 0;
			}
			else if(k == 0) {
				printf("player 2 ha won!!\n");
				print(grid);
				printf("\n");
				return 0;
			}
		}
		printCount(count);
	}
	return 0;
}

int counter(int count) {
	count++;
	return count;
}

void printCount(int c) {
	printf("Turn: %d\n", c);
}

void print(char grid[X][Y]) {
	int i, j;
	for (i = 0; i < X; i++) {
			printf("\n");
		for (j = 0; j < Y; j++) {
			printf("%c", grid[i][j]);			
		}
	}
}
bool input(char *pcell, char plr) {
	int i = 0;
	int j = 0;
	char mem[100];
	char *endptr;
	char *check;
	printf ("\ninsert coords: ");
//	scanf("%d %d", &i, &j);
	while(true){
		if (fgets(mem, sizeof(mem), stdin) == NULL) {
    			return false;
		}
		long coor1 = strtol(mem, &endptr, 10);
		check = endptr;
		long coor2 = strtol(endptr, &endptr, 10);
		if(endptr == mem || check == endptr) {
			printf("Error: coordinate non valide\ninsert coords:");
			continue;
		}
		if (!(coor1 <= 2 && coor1 >= 0 && coor2 <= 2 && coor2 >= 0)) {
		printf("\nError: coordinate non valide\n");
		continue;
		}
		i = (int)coor1;
		j = (int)coor2;
		break;
	}
/*	
 		if (!(i <= 2 && i >= 0 && j <= 2 && j >= 0)) {
		printf("\nError: coordinate non valide\n");
		return false;
	}
*/
	pcell = (pcell + (i * Y +j));
	if (*pcell != ' ') {
		printf("Error: cell already occupied\n");
		return false;
	}
	else {
		*pcell = plr;
		return true;
	}
}

// funzione per la condizione di vittoria inizio da righe o colonne, implementerò le diagonali per ultime.

bool victory(char grid[X][Y]) {
	int i, j;
	for(i = 0; i < X; i++) {
		if((grid[i][0] == 'O' || grid[i][0] == 'X') && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
			return true;
		}
	}
	for(j = 0; j < Y; j++) {
		if((grid[0][j] == 'O' || grid[0][j] == 'X') && grid [0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
			return true;
		}
	}
	if((grid[0][0] == 'O' || grid[0][0] == 'X') && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
		return true;
	}
	else if((grid[0][2] == 'O' || grid[0][2] == 'X') && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		return true;
	}
	return false;
}







/*TO DO:
 * 	ver: 1.0
 * 	- organizing if conditions
 *
 * DROPPED:
 * 	- add a grid, to make more clear the program*/
