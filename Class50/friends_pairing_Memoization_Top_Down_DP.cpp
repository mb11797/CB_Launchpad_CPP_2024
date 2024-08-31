#include<iostream>
#include<vector>
using namespace std;

#define ll long long

ll noOfFriendsPairingWays(int n, vector<ll> &memo){
	static int count = 1;
	if(n == 2){
		return 2;
	}

	if(n == 1){
		return 1;
	}

	if(memo[n] != -1)
		return memo[n];

	cout<<"Count = "<<count++<<endl;

	return memo[n] = noOfFriendsPairingWays(n-1, memo) + (n-1)*noOfFriendsPairingWays(n-2, memo);
}

int main(){

	int nFriends;
	cin>>nFriends;

	vector<ll> memo(nFriends+1, -1);	// for Memoization, i.e, Top Down DP

	cout<<noOfFriendsPairingWays(nFriends, memo)<<endl;

	return 0;
}