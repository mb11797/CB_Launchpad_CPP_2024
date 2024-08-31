#include<iostream>
#include<vector>
using namespace std;

int findWays(int n, int k){
	if(n == 0){
		return 1;
	}

	int ans = 0;
	for(int i=1; i<=k; i++){
		if(n-i >= 0){
			ans += findWays(n-i, k);
		}
	}

	return ans;
}


int main(){
	int n, k;
	cin>>n>>k;

	cout<<findWays(n, k)<<endl;

	return 0;
}