#include<iostream>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);

	/*
	// print all subarrays starting from 0th index
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
	*/

	/*
	// sum of all subarrays starting from 0th index
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=0; j<=i; j++){
			sum = sum + arr[j];
		}
		cout<<"Sum of subarray from 0 to "<<i<<" = "<<sum<<endl;
	}
	cout<<endl;
	*/


	int ans[n];
	int sum = 0;
	for(int i=0; i<n; i++){
		sum = sum + arr[i];
		ans[i] = sum;
	}

	for(int i=0; i<n; i++){
		cout<<"Sum of subarray from 0 to "<<i<<" = "<<ans[i]<<endl;
	}
	cout<<endl;

	return 0;
}

