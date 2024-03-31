#include<iostream>
using namespace std;

int main(){
	int arr[] = {22, 12, 1, 5, -3};
	int n = sizeof(arr) / sizeof(arr[0]);

	/*
	cout<<"Before Sorting: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	// Sort the arr
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}

	cout<<"After Sorting: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	*/

	// Optimized Bubble Sort:
	cout<<"Before Sorting: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	// Sort the arr
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}

	cout<<"After Sorting: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;


	return 0;
}