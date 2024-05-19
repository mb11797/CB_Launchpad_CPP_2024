#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(b == 0)
		return a;

	int ans = gcd(b, a%b);
	return ans;
}

int main(){

	int a, b;
	cin>>a>>b;

	cout<<gcd(a, b)<<endl;

	return 0;
}