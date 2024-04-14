#include<iostream>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5};

	cout<<arr<<endl;	// address of 0th bkt
	cout<<*arr<<endl;	// value stored at 0th bkt -> dereferencing 0th bkt address

	for(int i=0; i<5; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	for(int i=0; i<5; i++)
		cout<< *(arr+i)<<" ";
	cout<<endl;

	return 0;
}