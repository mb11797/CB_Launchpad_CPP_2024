#include<iostream>
using namespace std;

int find_rightmost_set_bit(int n){
	int i = 0;
	while(n > 0){
		if((n & 1) > 0){
			return i;
		}
		i++;
		n = n >> 1;
	}
	return -1;
}



void print_unique_nos(int arr[], int n){
	int xorOfAll = 0;
	for(int i=0; i<n; i++)
		xorOfAll ^= arr[i];

	int rmsb_idx = find_rightmost_set_bit(xorOfAll);

	int grpA = 0;
	int grpB = 0;

	for(int i=0; i<n; i++){

		int mask = 1 << rmsb_idx;

		if((arr[i] & mask) > 0){
			grpA = grpA ^ arr[i];
		}
		else{
			grpB = grpB ^ arr[i];
		}
	}
	cout<<grpA<<" "<<grpB<<endl;
	return;
}

int main(){
	// all nos thrice except 1 unique no

	int n = 7;
	int arr[7] = {1,3,5,3,7,1};

	print_unique_nos(arr, n);

	return 0;
}





