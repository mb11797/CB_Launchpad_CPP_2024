#include<iostream>
#include<algorithm>
using namespace std;

bool myCompare(int a, int b){
	return a > b;
}

int main(){
	int n = 5;
	int arr[] = {26, 28, 19, -26, 1};


	for(int el: arr){
		cout<<el<<" ";
	}
	cout<<endl;

	sort(arr, arr+n, myCompare);

	for(int el: arr)
		cout<<el<<" ";
	cout<<endl;

	return 0;
}