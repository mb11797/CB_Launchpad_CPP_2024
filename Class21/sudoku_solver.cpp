#include<iostream>
#include<vector>
using namespace std;

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
*/


bool canPlaceNo(vector<vector<int> > grid, int r, int c, int no){
	for(int k=0; k<9; k++){
		if(grid[k][c] == no){
			return false;
		}
		if(grid[r][k] == no){
			return false;
		}
	}

	int gridStartCell_x = 3 * (r / 3);
	int gridStartCell_y = 3 * (c / 3);

	for(int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			if(grid[gridStartCell_x + x][gridStartCell_y + y] == no){
				return false;
			}
		}
	}

	return true;
}

void printGrid(vector<vector<int> > grid){
	int n = grid.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}


bool solveSudoku(vector<vector<int> > &grid, int r, int c){

	if(r == 9){
		printGrid(grid);
		return true;
	}

	if(c == 9){
		return solveSudoku(grid, r+1, 0);
	}


	if(grid[r][c] != 0){
		return solveSudoku(grid, r, c+1);
	}

	for(int no=1; no<=9; no++){
		if(canPlaceNo(grid, r, c, no)){
			grid[r][c] = no;
			bool isSolvable = solveSudoku(grid, r, c+1);
			if(isSolvable)
				return true;
		}
	}
	grid[r][c] = 0;
	return false;
}

int main(){
	// vector<vector<int> > grid {
    //     {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //     {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //     {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //     {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //     {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //     {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //     {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //     {0, 0, 0, 0, 8, 0, 0, 7, 9}
    // };

    vector<vector<int> > grid;

    for(int i=0; i<9; i++){
    	vector<int> row;
	    for(int j=0; j<9; j++){
	    	int temp;
	    	cin>> temp;
	    	row.push_back(temp);
	    }    	
	    grid.push_back(row);
    }

    cout<<endl;
    cout<<"Solved Sudoku: "<<endl;
    solveSudoku(grid, 0, 0);


	return 0;
}

