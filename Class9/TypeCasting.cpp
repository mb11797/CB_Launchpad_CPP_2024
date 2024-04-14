#include<iostream>
using namespace std;

// int* func(){
// 	int x = 10;
// 	int *y = &x;
// 	return &y;
// }

int main(){
	char ch = 'A';

	cout<<ch<<endl;

	cout<<ch + 1<<endl;
	cout<< (char) (ch+1)<<endl;

	char newCh = ch + 1;

	cout<<newCh<<endl;



	return 0;
}