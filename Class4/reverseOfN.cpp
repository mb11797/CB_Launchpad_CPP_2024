#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;	

	int revN = 0;
	while(n > 0){
		int remainder = n % 10;
		revN = revN * 10 + remainder;
		n = n / 10;
	}
	cout<<revN<<endl;

	return 0;
}


