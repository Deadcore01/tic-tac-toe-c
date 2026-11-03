#include <stdio.h>
#include <stdbool.h>
#define X 3
#define Y 3

// prototipazione funzioni

int counter(int count);

void printCount(int c);

void print(char grid[X][Y]);

bool input(char *pcell, char plr);

void victory();
// main, inizializzo le variabili, chiamo le funzioni
int main() {
	bool bl = false;
	char player;
	int count = 1;
	char grid[X][Y] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '} 
	};
	for(int i = 1; i <= 9; i++) {
		
		int k = 0;
		k = count % 2;
		if(k == 1) {
			player = 'X';

		}
		else if(k == 0) {
			player = 'O';
		}
		print(grid);
		bl = input(&grid[0][0], player);
		if (bl == true) {
			count = counter(count);
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
	printf ("\ninsert coords: ");
	scanf("%d %d", &i, &j);
	if (i <= 2 && i >= 0) {
		if (j <= 2 && j >= 0) {
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
	else {
		printf("\nError: coordinate non valide\n");
		return false;
	}
	}
	else {
		printf("\nError: coordinate non valide\n");
		return false;
	}
}
