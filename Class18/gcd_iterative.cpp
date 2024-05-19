#include<iostream>
using namespace std;

int gcd(int a, int b){
	while(b > 0){
		int newA = b;
		int newB = a%b;

		a = newA;
		b = newB;
	}
	return a;
}

int main(){

	int a, b;
	cin>>a>>b;

	cout<<gcd(a, b)<<endl;

	return 0;
}