#include<iostream>
#include<vector>
using namespace std;

int noOfTilingWays(int n, vector<int> &memo){
	static int count = 1;
	if(n == 4){
		return 2;
	}

	if(n < 4)
		return 1;

	if(memo[n] != -1)
		return memo[n];

	cout<<"Count = "<<count++<<endl;

	return memo[n] = noOfTilingWays(n-1, memo) + noOfTilingWays(n-4, memo);
}

int main(){

	// 4 x n
	// Given: n > 0 (always)
	int n;
	cin>>n;

	vector<int> memo(n+1, -1);		// for Memoization, i.e, Top Down DP

	cout<<noOfTilingWays(n, memo)<<endl;

	return 0;
}