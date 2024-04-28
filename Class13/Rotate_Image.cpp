#include<iostream>
using namespace std;

void swapForTransposeMatrix(int matrix[][3], int row, int col){
	int temp = matrix[row][col];
	matrix[row][col] = matrix[col][row];
	matrix[col][row] = temp;
	return;
}

void transpose(int matrix[][3], int nRows, int nCols){
	for(int row=0; row<nRows; row++){
		for(int col=0; col<row; col++){
			swapForTransposeMatrix(matrix, row, col);
		}
	}

	cout<<"Transposed 2D Array:"<<endl;
	for(int row=0; row<nRows; row++){

		for(int col=0; col<nCols; col++){
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void mirror(int matrix[][3], int nRows, int nCols){
	for(int row=0; row<nRows; row++){
		// reverse the row, i.e, mirror the row
		for(int col=0; col<(nCols / 2); col++){
			swap(matrix[row][col], matrix[row][nCols-1-col]);
		}
	}

	cout<<"Mirror of 2D Array:"<<endl;
	for(int row=0; row<nRows; row++){

		for(int col=0; col<nCols; col++){
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void rotateImageInCWDirn(int matrix[][3], int nRows, int nCols){
	// For CW Rotation:
	// 1. Transpose
	// 2. Mirror

	
	transpose(matrix, nRows, nCols);

	mirror(matrix, nRows, nCols);

	cout<<"Mirror of Transposed 2D Array, i.e Rotate 90 CW:"<<endl;
	for(int row=0; row<nRows; row++){

		for(int col=0; col<nCols; col++){
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;	
}

int main(){
	//Square Matrix
	int matrix[3][3] = {{1,2,3,},
					 	{4,5,6},
					 	{7,8,9}};
	int nRows = 3;
	int nCols = 3;

	cout<<"2D Array:"<<endl;
	for(int row=0; row<nRows; row++){

		for(int col=0; col<nCols; col++){
			cout<<matrix[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	rotateImageInCWDirn(matrix, nRows, nCols);

	return 0;
}