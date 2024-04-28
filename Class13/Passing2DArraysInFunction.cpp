#include<iostream>
using namespace std;

void spiralPrint(int **arr[][4], int nRows, int nCols){
	int begRow = 0;
	int begCol = 0;
	int lastRow = nRows-1;
	int lastCol = nCols-1;

	int k = 1;

	while(k <= nRows*nCols){

		// beg Row -> from l to r
		int r = begRow;
		int c = begCol;
		while(k <= nRows*nCols && c <= lastCol){
			cout<<arr[r][c]<<" ";
			c++;
			k++;
		}
		begRow++;



		// Last Col -> top to down
		r = begRow;
		c = lastCol;
		while(k <= nRows*nCols && r <= lastRow){
			cout<<arr[r][c]<<" ";
			r++;
			k++;
		}
		lastCol--;



		// Last Row -> right to left
		r = lastRow;
		c = lastCol;
		while(k <= nRows*nCols && c >= begCol){
			cout<<arr[r][c]<<" ";
			c--;
			k++;
		}
		lastRow--;


		// beg Col -> down to top
		r = lastRow;
		c = begCol;
		while(k <= nRows*nCols && r >= begRow){
			cout<<arr[r][c]<<" ";
			r--;
			k++;
		}
		begCol++;
	}
}


int main(){

	int arr[3][4] = {{1,2,3,4},
					 {4,5,6,7},
					 {8,9,10,11}};
	int nRows = 3;
	int nCols = 4;

	cout<<"2D Array:"<<endl;
	for(int row=0; row<nRows; row++){

		for(int col=0; col<nCols; col++){
			cout<<arr[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	spiralPrint(arr, nRows, nCols);

	return 0;
}