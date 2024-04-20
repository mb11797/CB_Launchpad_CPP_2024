#include<iostream>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);

	for(int i=0; i<n; i++){
		// i -> to select starting of current window
		for(int j=i; j<n; j++){
			// j -> to selet ending of current window

			// Print current Window

			for(int k=i; k<=j; k++){
				cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}

