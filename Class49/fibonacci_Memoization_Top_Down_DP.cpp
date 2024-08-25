#include<iostream>
#include<vector>
using namespace std;

#define ll long long

ll fibonacci(int n, vector<ll> &memo){
	static int count = 1;
	if(n == 1 or n == 0)
		return n;

	if(memo[n] != -1)
		return memo[n];

	cout<<"Calculating fibonacci("<<n<<")"<<" | count = "<<(count++)<<endl;
	// PostOrder Computation
	return memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
}

int main(){
	int n;
	cin>>n;

	// int arr[n];
	// memset(arr, -1, sizeof arr);

	vector<ll> memo(n+1, -1);		// dp[n+1] -> memoization
	ll ans = fibonacci(n, memo);
	cout<<ans<<endl;

	return 0;
}