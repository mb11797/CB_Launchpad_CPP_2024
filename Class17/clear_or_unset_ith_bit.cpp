#include<iostream>
using namespace std;


int unset_ith_bit(int n, int i){
	int mask = 1<<i;
	n = n & (~mask);	// ~mask -> complement of mask -> toggle all bits
	return n;
}


int main(){

	int n;
	cin>>n;

	int i;
	cin>>i;

	cout<<unset_ith_bit(n, i)<<endl;

	return 0;
}

