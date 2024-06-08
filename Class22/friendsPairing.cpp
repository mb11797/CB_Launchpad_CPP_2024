#include<iostream>
using namespace std;

int factorial(int n){
	if(n == 0 || n == 1)
		return 1;
	return n*factorial(n-1);
}

int nCr(int n, int r){
	return factorial(n) / (factorial(r) * factorial(n-r));
}


int pairFriends(int n){
	if(n == 1 || n == 2)
		return n;

	return pairFriends(n-1) + nCr(n-1, 1)*pairFriends(n-2);
}

int main(){
	int n;
	cin>>n;

	cout<<pairFriends(n)<<endl;
	return 0;
}