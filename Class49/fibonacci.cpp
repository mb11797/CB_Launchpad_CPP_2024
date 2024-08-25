#include<iostream>
using namespace std;

/*
int fibonacci(int n){
	if(n == 1 or n == 0)
		return n;

	// PostOrder Computation
	int lftAns = fibonacci(n-1);
	int rytAns = fibonacci(n-2);

	return lftAns + rytAns;
}
*/

int fibonacci(int n){
	static int count = 1;
	if(n == 1 or n == 0)
		return n;

	cout<<"Calculating fibonacci("<<n<<")"<<" | count = "<<(count++)<<endl;
	// PostOrder Computation
	return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	int n;
	cin>>n;

	int ans = fibonacci(n);
	cout<<ans<<endl;

	return 0;
}