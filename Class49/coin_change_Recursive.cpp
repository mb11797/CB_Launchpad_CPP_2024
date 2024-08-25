#include<iostream>
#include<vector>
using namespace std;

int minCoinsForChange(int n, vector<int> denominations){
	if(n == 0)
		return 0;

	int ans = INT_MAX;
	for(int denom: denominations){
		if(n - denom >= 0){
			ans = min(ans, 1 + minCoinsForChange(n-denom, denominations));
		}
	}

	return ans;
}

int minCoinsForChange_Memoized(int n, vector<int> denominations, vector<int> &memo){
	if(n == 0)
		return 0;

	if(memo[n] != -1)
		return memo[n];

	int ans = INT_MAX;
	for(int denom: denominations){
		if(n - denom >= 0){
			ans = min(ans, 1 + minCoinsForChange_Memoized(n-denom, denominations, memo));
		}
	}

	return memo[n] = ans;
}

int main(){

	int nDenom;
	cin>>nDenom;

	vector<int> denominations;
	for(int i=0; i<nDenom; i++){
		int temp;
		cin>>temp;
		denominations.push_back(temp);
	}

	int n;
	cin>>n;

	vector<int> memo(n+1, -1);

	cout<<minCoinsForChange_Memoized(n, denominations, memo)<<endl;

	return 0;
}