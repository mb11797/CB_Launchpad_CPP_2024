#include<iostream>
using namespace std;

int main(){
	// int nRows; 
	// int nCols;
	// cin>>nRows>>nCols;	

	// int arr[nRows][nCols];		// Declaration

	// for(int i=0; i<nRows; i++){
	// 	for(int j=0; j<nCols; j++){
	// 		cin>>arr[i][j];
	// 	}
	// }

	int arr[2][3] = {{1,2,3},
					 {4,5,6}};
	int nRows = 2;
	int nCols = 3;

	cout<<"2D Array:"<<endl;
	for(int i=0; i<nRows; i++){

		for(int j=0; j<nCols; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}