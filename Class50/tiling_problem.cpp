#include<iostream>
using namespace std;

int noOfTilingWays(int n){
	static int count = 1;
	if(n == 4){
		return 2;
	}

	if(n < 4)
		return 1;

	cout<<"Count = "<<count++<<endl;

	return noOfTilingWays(n-1) + noOfTilingWays(n-4);
}

int main(){

	// 4 x n
	// Given: n > 0 (always)
	int n;
	cin>>n;

	cout<<noOfTilingWays(n)<<endl;

	return 0;
}