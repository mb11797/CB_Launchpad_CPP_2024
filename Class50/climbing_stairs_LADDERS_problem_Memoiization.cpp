#include<iostream>
#include<vector>
using namespace std;

int findWays(int n, int k, vector<int> &memo){
	if(n == 0){
		return 1;
	}

	if(memo[n] != -1)
		return memo[n];

	int ans = 0;
	for(int i=1; i<=k; i++){
		if(n-i >= 0){
			ans += findWays(n-i, k, memo);
		}
	}

	return memo[n] = ans;
}


int main(){
	int n, k;
	cin>>n>>k;

	vector<int> memo(n+1, -1);

	cout<<findWays(n, k, memo)<<endl;

	return 0;
}