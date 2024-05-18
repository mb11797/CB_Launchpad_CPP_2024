#include<iostream>
using namespace std;


int set_ith_bit(int n, int i){
	int mask = 1<<i;
	n = n | mask;
	return n;
}


int main(){

	int n;
	cin>>n;

	int i;
	cin>>i;

	cout<<set_ith_bit(n, i)<<endl;

	return 0;
}

