#include<iostream>
#include<vector>
using namespace std;

int searchRotatedSortedArr(int arr[], int n, int key){

	int beg = 0;
	int en = n-1;

	while(beg <= en){
		int mid = (beg + en) / 2;

		if(arr[mid] == key){
			return mid;
		}
		// Find out mid lies on which part??? 
		else if(arr[0] < arr[mid]){
			// mid lies on First part -> beg to mid always sorted -> search key from beg to mid
			if(arr[beg] <= key && key <= arr[mid]){
				en = mid-1;
			}
			else{
				beg = mid+1;
			}
		}
		else{
			// mid lies on second part -> mid to end always sorted -> search key from mid to en
			if(arr[mid] <= key && key <= arr[en]){
				beg = mid+1;
			}
			else{
				en = mid-1;
			}
		}
	}
	return -1;
}

int main(){

	int n;
	cin>>n;
	int arr[n];

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	int key;
	cin>>key;

	cout<<searchRotatedSortedArr(arr, n, key)<<endl;

	return 0;
}