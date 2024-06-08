#include<iostream>
using namespace std;

int countBinaryStrings(int n){
	if(n == 1)
		return 2;
	if(n == 2)
		return 3;

	return countBinaryStrings(n-1) + countBinaryStrings(n-2);
}

int main(){
	int n;
	cin>>n;

	cout<<countBinaryStrings(n)<<endl;
	return 0;
}