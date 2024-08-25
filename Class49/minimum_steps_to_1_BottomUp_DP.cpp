#include<iostream>
#include<vector>
using namespace std;

int minStepsTo1(int n){

	vector<int> dp(n+1);

	dp[1] = 0;

	for(int i=2; i<=n; i++){
		dp[i] = 1 + dp[i-1];
		if(i % 3 == 0)
			dp[i] = min(dp[i], 1 + dp[i/3]);
		if(i % 2 == 0)
			dp[i] = min(dp[i], 1 + dp[i/2]);
	}

	return dp[n];
}

int main(){
	int n;
	cin>>n;

	// Allowed Operations: n/3, n/2, n-1
	cout<<minStepsTo1(n)<<endl;


	return 0;
}