#include<iostream>
using namespace std;

int factorial(int n){
	if(n == 1)
		return 1;

	int selfWork = n;
	int aageKaAns = factorial(n-1);
	return selfWork * aageKaAns;
}

int main(){

	int n;
	cin>>n;

	int ans = factorial(n);
	cout<<ans<<endl;

	return 0;
}