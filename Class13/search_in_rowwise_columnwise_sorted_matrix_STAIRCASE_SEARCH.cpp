#include<iostream>
using namespace std;

void searchInRowColSorted(int arr[3][4], int nRows, int nCols, int key){
	int row = 0, col = nCols-1;

	while(row<nRows && col>=0){
		cout<<"Searching at "<<row<<","<<col<<endl;
		if(arr[row][col] < key){
			row++;
		}
		else if(arr[row][col] > key){
			col--;
		}
		else{
			cout<<"Found "<<key<<" at ("<<row<<", "<<col<<")"<<endl;
			return;
		}
	}
	cout<<"Not found"<<endl;
	return;
}

int main(){
	int arr[3][4] = {{1,3,5,7},
					 	{10,13,16,20},
					 	{23,26,30,29}};
	int nRows = 3;
	int nCols = 3;

	int key = 20;

	cout<<"2D Array:"<<endl;
	for(int row=0; row<nRows; row++){

		for(int col=0; col<nCols; col++){
			cout<<arr[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	searchInRowColSorted(arr, nRows, nCols, key);

	return 0;
}