#include<iostream>
using namespace std;

int minStepsTo1(int n){
	static int count = 1;

	cout<<"Count: "<<(count++)<<endl;

	if(n == 1){
		return 0;
	}

	int ans = INT_MAX;
	if(n % 3 == 0)
		ans = min(ans, 1 + minStepsTo1(n/3));

	if(n % 2 == 0)
		ans = min(ans, 1 + minStepsTo1(n/2));

	ans = min(ans, 1 + minStepsTo1(n-1));

	return ans;
}

int main(){
	int n;
	cin>>n;

	// Allowed Operations: n/3, n/2, n-1
	cout<<minStepsTo1(n)<<endl;


	return 0;
}