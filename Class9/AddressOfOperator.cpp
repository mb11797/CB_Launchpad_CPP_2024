#include<iostream>
using namespace std;

int main(){
	int x = 10;
	int *y = &x;

	cout<<x<<endl;
	cout<<&x<<endl;
	cout<<y<<endl;

	float f = 1.11;
	float *fptr = &f;

	cout<<f<<endl;
	cout<<&f<<endl;
	cout<<fptr<<endl;

	return 0;
}