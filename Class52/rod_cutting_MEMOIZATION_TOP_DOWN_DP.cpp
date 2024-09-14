#include<iostream>
#include<vector>
using namespace std;

int maxProfit(int prices[], int len, int rodLength, vector<int> &memo){
	if(rodLength == 0)
		return 0;

	if(memo[rodLength] != -1)
		return memo[rodLength];

	int ans = INT_MIN;
	for(int cut=1; cut<=rodLength; cut++){
		int currAns = prices[cut-1] + maxProfit(prices, len, rodLength-cut, memo);
		ans = max(ans, currAns);
	}

	return memo[rodLength] = ans;
}

int main(){
	int prices[8] = {1, 5, 8, 9, 10, 17 , 17, 20};
	int n = 8;

	vector<int> memo(n+1, -1);

	cout<<maxProfit(prices, n, n, memo)<<endl;

	return 0;
}