#include<iostream>
using namespace std;

int main(){
	int x = 10;
	
	int *y;		// Declaration
	y = &x;		// initialization

	cout<<x<<endl;
	// cout<<y<<endl;	
	// cout<<&x<<endl;
	// cout<<&y<<endl;

	cout<< *y <<endl;

	*y = *y + 1;
	cout<< *y <<endl;
	cout<<x<<endl;
	// cout<<y<<endl;	
	// cout<<&x<<endl;
	// cout<<&y<<endl;

	float f = 1.11;
	float *fptr1 = &f;		// * to declare fptr1 as a pointer variable
	float *fptr, f1;
	fptr = &f;

	cout<<fptr1<<endl;
	cout<<fptr<<endl;
	cout<< *fptr <<endl;	// * -> behaving as dereference operator

	float f2 = 2.13;
	*fptr = f2;

	cout<<f<<endl;

	fptr = &f2;

	cout<<f<<endl;
	cout<<fptr<<endl;
	cout<< *fptr <<endl;

	return 0;
}