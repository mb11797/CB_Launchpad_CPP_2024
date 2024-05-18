#include<iostream>
using namespace std;

int find_ith_bit_using_Mask_Optimized(int n, int i){
	int mask = 1 << i;
	if((n & mask) > 0){
		return 1;
	}
	return 0;
}

int find_ith_bit(int n, int i){
	n = n >> i;
	if((n & 1) > 0){
		return 1;
	}
	return 0;

	// // Alternative:
	// return n & 1;
}


int main(){

	int n;
	cin>>n;

	int i;
	cin>>i;

	cout<<find_ith_bit(n, i)<<endl;

	cout<<find_ith_bit_using_Mask_Optimized(n, i)<<endl;

	return 0;
}

