#include<iostream>
using namespace std;

// int x; // Global

int incrementVal(int val){
	val = val + 1;
	cout<<"In incrementVal(): "<<val<<endl;
	return val;
}

int main(){

	int x = 26;
	x = x + 1;

	cout<<"Before (In main()): "<<x<<endl;
	x = incrementVal(x);
	cout<<"After (In main()): "<<x<<endl;

	return 0;
}