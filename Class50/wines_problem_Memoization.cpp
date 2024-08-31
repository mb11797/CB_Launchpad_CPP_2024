#include<iostream>
#include<vector>
using namespace std;

int maxProfitAfterSellingWines(vector<int> winesCost, int beg, int en, int year, vector<vector<int> > &memo){
	static int count = 1;
	if(beg > en){
		return 0;
	}

	if(memo[beg][en] != -1)
		return memo[beg][en];

	cout<<"Count = "<<count++<<endl;

	// Case 1: sell beg wali wine
	int ans1 = winesCost[beg] * year + maxProfitAfterSellingWines(winesCost, beg+1, en, year+1, memo);

	// Case 2: sell en wali wine
	int ans2 = winesCost[en] * year + maxProfitAfterSellingWines(winesCost, beg, en-1, year+1, memo);

	return memo[beg][en] = max(ans1, ans2);
}

int main(){
	int n;
	cin>>n;

	vector<int> wineBottlesCost(n);
	for(int i=0; i<n; i++){
		cin>>wineBottlesCost[i];
	}

	vector<vector<int> > memo(n, vector<int>(n, -1));
	
	cout<<maxProfitAfterSellingWines(wineBottlesCost, 0, n-1, 1, memo)<<endl;

	return 0;
}