#include<iostream>
using namespace std;

int maxProfit(int prices[], int len, int rodLength){
	if(rodLength == 0)
		return 0;

	int ans = INT_MIN;
	for(int cut=1; cut<=rodLength; cut++){
		int currAns = prices[cut-1] + maxProfit(prices, len, rodLength-cut);
		ans = max(ans, currAns);
	}

	return ans;
}

int main(){
	int prices[8] = { 3 , 5, 8, 9, 10, 17 , 17, 20};
	int n = 8;

	cout<<maxProfit(prices, n, n)<<endl;

	return 0;
}