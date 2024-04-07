#include<iostream>
using namespace std;

void incrementVal(int &z){
	z = z+1;
	cout<<z<<endl;
	cout<<&z<<endl;
}

int main(){

	int x = 26;
	int &y = x;
	cout<<x<<", "<<y<<endl;
	y = y+1;

	cout<<x<<", "<<y<<endl;
	cout<<&y<<endl;
	cout<<&x<<endl;

	incrementVal(x);
	cout<<x<<", "<<y<<endl;
	incrementVal(y);
	cout<<x<<", "<<y<<endl;

	return 0;
}