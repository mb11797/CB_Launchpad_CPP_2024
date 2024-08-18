#include<iostream>
using namespace std;

/*
................................
.............#####..............
.............#...#..............
.......#######...#######........
.....####...#######...####......
....##...................##.....
...##.....................##....
...##.....................##....
....##...................##.....
.....##.................##......
......##...............##.......
.......###...........###........
.........#############..........
................................
...........A.P.P.L.E............
................................
*/

int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int m = 16, n = 32;		// m x n -> board

void printBoard(char board[][32]){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

void floodFill(char board[][32], int x, int y, char srcColor, char colorToFill){

	// board ki boundary ka check
	if(x < 0 || x >= m || y < 0 || y >= n){
		return;
	}


	if(board[x][y] != srcColor){
		// already visited not to visit again as well as different color cells not to visit again
		return;
	}

	board[x][y] = colorToFill;
	printBoard(board);

	for(int i=0; i<4; i++){
		int newX = x + directions[i][0];
		int newY = y + directions[i][1];

		floodFill(board, newX, newY, srcColor, colorToFill);
	}

	return;
}

int main(){

	char board[16][32];
	for(int i=0; i<16; i++){
		for(int j=0; j<32; j++){
			cin>>board[i][j];
		}
	}
	cout<<endl<<endl;
	printBoard(board);

	int x, y;
	cin>>x>>y;

	char colorToFill;
	cin>>colorToFill;

	char srcColor = board[x][y];	// if clicked on ., then srcColor = '.'

	floodFill(board, x, y, srcColor, colorToFill);
	printBoard(board);

	return 0;
}