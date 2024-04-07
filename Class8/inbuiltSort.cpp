#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] < arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}



int main(){
	int n = 5;
	int arr[] = {26, 28, 19, -26, 1};

	bubbleSort(arr, n);

	// for(int el: arr){
	// 	cout<<el<<" ";
	// }
	// cout<<endl;

	// sort(arr, arr+n);

	// for(int el: arr)
	// 	cout<<el<<" ";
	// cout<<endl;

	return 0;
}