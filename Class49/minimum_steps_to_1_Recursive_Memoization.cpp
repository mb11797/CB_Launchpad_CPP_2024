#include<iostream>
#include<vector>
using namespace std;

int minStepsTo1(int n, vector<int> &memo){
	static int count = 1;

	cout<<"Count: "<<(count++)<<endl;

	if(n == 1){
		return 0;
	}

	if(memo[n] != -1)
		return memo[n];

	int ans = INT_MAX;
	if(n % 3 == 0)
		ans = min(ans, 1 + minStepsTo1(n/3, memo));

	if(n % 2 == 0)
		ans = min(ans, 1 + minStepsTo1(n/2, memo));

	ans = min(ans, 1 + minStepsTo1(n-1, memo));

	return memo[n] = ans;
}

int main(){
	int n;
	cin>>n;

	// Allowed Operations: n/3, n/2, n-1
	vector<int> memo(n+1, -1);

	cout<<minStepsTo1(n, memo)<<endl;


	return 0;
}