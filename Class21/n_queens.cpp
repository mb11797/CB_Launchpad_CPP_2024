#include<iostream>
#include<vector>
using namespace std;

bool isConfigPossible(vector<vector<char> > board, int i, int j){
	int n = board.size();

	// vertical check
	for(int row=0; row<i; row++){
		if(board[row][j] == 'Q')
			return false;
	}

	// left diagonal
	for(int row=i-1, col=j-1; row>=0 && col>=0; row--, col--){
		if(board[row][col] == 'Q')
			return false;
	}

	// right diagonal
	for(int row=i-1, col=j+1; row>=0 && col<n; row--, col++){
		if(board[row][col] == 'Q')
			return false;
	}

	return true;
}

void printBoard(vector<vector<char> > board){
	int n = board.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}

void nQueens(vector<vector<char> > board, int i, int &count){
	int n = board.size();
	if(i == n){
		printBoard(board);
		count++;
		return;
	}

	
	for(int col=0; col<n; col++){
		if(isConfigPossible(board, i, col)){
			board[i][col] = 'Q';
			nQueens(board, i+1, count);
			board[i][col] = '.';	// Backtracking
		}
	}
	return;
}

int main(){

	int n;
	cin>>n;

	vector<vector<char> > board(n, vector<char>(n, '.'));

	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			board[i][j] = '.';
		}
	}
	*/

	cout<<"Chess Board:"<<endl;
	printBoard(board);

	int count = 0;
	nQueens(board, 0, count);
	cout<<endl<<endl;
	cout<<"Total: "<<count<<endl;

	return 0;
}