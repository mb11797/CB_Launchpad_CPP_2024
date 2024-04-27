#include<iostream>
using namespace std;

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

	// Wave Print
	for(int col=0; col<nCols; col++){
		if(col % 2 == 0){
			for(int row=0; row<nRows; row++){
				cout<<arr[row][col]<<" ";
			}
		}
		else{
			for(int row=nRows-1; row >= 0; row--){
				cout<<arr[row][col]<<" ";
			}
		}
	}
	cout<<endl;


	return 0;
}