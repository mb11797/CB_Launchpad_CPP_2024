#include<iostream>
#include<vector>
using namespace std;

#define ll long long

ll fibonacci(int n){
	vector<ll> dp(n+1, 0);

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main(){
	int n;
	cin>>n;

	cout<<fibonacci(n)<<endl;

	return 0;
}