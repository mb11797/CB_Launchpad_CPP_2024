#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> arr, int curIdx, int prevIdx, vector<vector<int> > &memo){

	if(curIdx == arr.size())
		return 0;

	if(memo[curIdx][prevIdx+1] != -1){
		return memo[curIdx][prevIdx+1];
	}

	int ans;
	// Case 1: Ignore curIdx wala element
	int option1 = lis(arr, curIdx+1, prevIdx, memo);


	// Case 2: Try to use curIdx wala element
	int option2 = INT_MIN;
	if(prevIdx < 0 or (arr[curIdx] > arr[prevIdx])){
		option2 = 1 + lis(arr, curIdx+1, curIdx, memo);
	}

	ans = max(option1, option2);
	return memo[curIdx][prevIdx+1] = ans;
}

int lis(vector<int> arr){
	int n = arr.size();
	vector<vector<int> > memo(n+1, vector<int>(n+1, -1));		// dp[n+1][n+1] -> memo[n+1][n+1]

	return lis(arr, 0, -1, memo);
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout<<lis(arr)<<endl;


	return 0;
}