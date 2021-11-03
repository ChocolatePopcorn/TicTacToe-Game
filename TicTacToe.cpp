#include<stdio.h>
#include<stdlib.h>

char data[4][4];

void setBoard() {
	for(int x=0;x<3;x++) {
		for(int y=0;y<3;y++) {
			data[x][y] = ' ';
		}
	}
}

void board() {
	puts("Current Board");
	puts("=============");
	puts("   | 0 | 1 | 2 | X");
	printf(" 0 | %c | %c | %c |\n", data[0][0], data[0][1], data[0][2]);
	printf(" 1 | %c | %c | %c |\n", data[1][0], data[1][1], data[1][2]);
	printf(" 2 | %c | %c | %c |\n", data[2][0], data[2][1], data[2][2]);
	puts(" Y ");
}

bool isBoardEmpty() {
	for(int x=0;x<3;x++) {
		for(int y=0;y<3;y++) {
			if(data[x][y] == ' ') return false;
		}
	}
	return true;
}

bool checkWin() {
	//atas ke bawah
	if((data[0][0] == data[1][0]) && (data[1][0] == data[2][0]) && (data[1][0] != ' ')) return true;
	else if((data[0][1] == data[1][1]) && (data[1][1] == data[2][1]) && (data[1][1] != ' ')) return true;
	else if((data[0][2] == data[1][2]) && (data[1][2] == data[2][2]) && (data[1][2] != ' ')) return true;

	//kiri ke kanan
	else if((data[0][0] == data[0][1]) && (data[0][1] == data[0][2]) && (data[0][1] != ' ')) return true;
	else if((data[1][0] == data[1][1]) && (data[1][1] == data[1][2]) && (data[1][1] != ' ')) return true;
	else if((data[2][0] == data[2][1]) && (data[2][1] == data[2][2]) && (data[2][1] != ' ')) return true;

	//diagonal atas kiri ke bawah kanan
	else if((data[0][0] == data[1][1]) && (data[1][1] == data[2][2]) && (data[1][1] != ' ')) return true;

	//diagonal dari atas kanan ke bawah kiri
	else if((data[0][2] == data[1][1]) && (data[1][1] == data[2][0]) && (data[1][1] != ' ')) return true;

	else return false;
}


int validationGame() {
	//checkwin true -> datanya ada yang sama 
	// boardempty true -> uda gabisa diisi lagi 
	if(checkWin() == false && isBoardEmpty() == false) return 0;
	else if(checkWin() == false && isBoardEmpty() == true) return -1; 
	else return 1;
}

bool valid(int x, int y) {
	if(data[y][x] != ' ') return false;
	else return true;
}

void inputData(int player, char flag) {
	board();
	
	int inpX, inpY;

	printf("current Turn : Player %d (%c)\n", player, flag);
	do {
		printf("Input Coordinate X (0-2): "); scanf("%d", &inpX);
	} while(inpX < 0 || inpX > 2);

	do {
		printf("Input Coordinate Y (0-2): "); scanf("%d", &inpY);
	} while(inpY < 0 || inpY > 2);

	if(valid(inpX, inpY) == false) {
		puts("Invalid Move");
		inputData(player, flag);
	}
	else data[inpY][inpX] = flag;
}


int main() {
    int sc = 0;
    
	do {
		setBoard();
		system("cls");
		puts("Welcome to Tic-Tac-Toe");
		puts("1. Start a new Game");
		puts("2. Exit");
		printf(">> "); scanf("%d", &sc);
		if(sc == 1) {
			system("cls");

			int game = 2;
			int lastPlayer = 0;
			do {
				int mod = game % 2;
				char xy[4] = {'X', 'O'};
				if(mod == 0) {
					inputData(mod+1, xy[0]);	
				} else if(mod == 1) {
					inputData(mod+1, xy[1]);
				}
				game++;
				lastPlayer = mod;
			} while(validationGame() == 0);

			if(validationGame() == -1) {
				puts("It's a Tie");
				board();
			} else if(validationGame() == 1) {
				puts("It's End");
				board();

				if(lastPlayer == 0) puts("player one Win (X)");
				else if(lastPlayer == 1) puts("player two Win (O)");
			}
			system("pause");
		}

    } while(sc != 2);

	puts("Thank you for playing");

    return 0;
}