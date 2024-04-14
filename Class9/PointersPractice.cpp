#include<iostream>
using namespace std;

void update(int *xptr){
	*xptr = *xptr + 1;
	cout<<"Inside update: "<<*xptr<<endl;
}

void reverseArr(int *arr, int n){
	int beg = 0, en = n-1;
	while(beg < en){
		swap(arr[beg++], arr[en--]);
	}
}

int main(){
	int x = 10;

	cout<<"Inside Main: "<<x<<endl;
	update(&x);
	cout<<"Inside Main: "<<x<<endl;

	int arr[] = {1,2,3,4,5};

	for(int i=0; i<5; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	reverseArr(arr, 5);
	for(int i=0; i<5; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}