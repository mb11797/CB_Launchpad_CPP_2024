#include<iostream>
#include<vector>
using namespace std;

#define ll long long

ll noOfFriendsPairingWays(int n){
	static int count = 1;
	if(n == 2){
		return 2;
	}

	if(n == 1){
		return 1;
	}

	cout<<"Count = "<<count++<<endl;

	return noOfFriendsPairingWays(n-1) + (n-1)*noOfFriendsPairingWays(n-2);
}

int main(){

	int nFriends;
	cin>>nFriends;

	cout<<noOfFriendsPairingWays(nFriends)<<endl;

	return 0;
}