#include<iostream>
#include<vector>
using namespace std;

int findSqrtUsingBinarySearch(int n){
	int beg = 1, en = n/2;

	int ans = -1;
	while(beg <= en){
		int mid = (beg + en) / 2;

		if(mid < n / mid){
			ans = mid;
			beg = mid+1;
		}
		else if(mid > n / mid){
			en = mid-1;
		}
		else{
			ans = mid;
			break;
		}
	}
	return ans;
}


int main(){
	int n;
	cin>>n;

	cout<<findSqrtUsingBinarySearch(n)<<endl;
	
	return 0;
}