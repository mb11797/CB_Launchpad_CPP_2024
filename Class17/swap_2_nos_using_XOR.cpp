#include<iostream>
using namespace std;

void swapUsingXOR(int &a, int &b){
	cout<<"Inside function(): "<<a<<" "<<b<<endl;

	a = a^b;
	b = a^b;
	a = a^b;

	cout<<"Inside function(): "<<a<<" "<<b<<endl;
}

int main(){
	int a, b;
	cin>>a>>b;

	cout<<a<<" "<<b<<endl;

	swapUsingXOR(a, b);

	cout<<a<<" "<<b<<endl;
	return 0;
}

