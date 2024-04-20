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
			int sum = 0;
			for(int k=i; k<=j; k++){
				sum = sum + arr[k];
			}
			cout<<"Sum of Subarray from "<<i<<" -> "<<j<<" = "<<sum<<endl;
		}
		cout<<endl;
	}

	return 0;
}

