#include<iostream>
using namespace std;

int main(){

	// int arr[] = {0, 2, 1, 0, 0, 1};
	int arr[] = {2, 0, 1};	
	// int n = 6;
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<<"Before Sorting: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int beg = 0, mid = 0, en = n-1;

	while(mid <= en){
		if(arr[mid] == 0){
			swap(arr[mid], arr[beg]);
			beg++;
			mid++;
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else{
			swap(arr[mid], arr[en]);
			en--;
		}
	}

	cout<<"After Sorting: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}