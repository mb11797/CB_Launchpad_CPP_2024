#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
	// Your code goes here
	for(int i=1; i<n; i++){
		// Insert ith element from unsorted half to its correct position in sorted half
		for(int j=i-1; j>=0; j--){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
			else{
				break;
			}
		}
	}

	return;
}

int main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout<<"Before Sorting: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	insertionSort(arr, n);

	cout<<"After Sorting: ";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}