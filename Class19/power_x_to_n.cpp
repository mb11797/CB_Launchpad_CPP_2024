#include<iostream>
using namespace std;

int pow_x_to_n(int x, int n){
	if(n == 1)
		return x;
	/*	
	int selfAns = x;
	int aageKaAns = pow_x_to_n(x, n-1);
	return selfAns * aageKaAns;
	*/
	// Short Way to Write:
	return x * pow_x_to_n(x, n-1);
}

int main(){
	int x;
	cin>>x;

	int n;
	cin>>n;

	int ans = pow_x_to_n(x, n);
	cout<<ans<<endl;

	return 0;
}