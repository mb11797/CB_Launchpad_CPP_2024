#include<iostream>
using namespace std;

int sumOfArr(int arr[], int beg, int en){
	if(beg == en)
		return arr[beg];

	int selfWorkAns = arr[beg];
	int aageKaAns = sumOfArr(arr, beg+1, en);
	return selfWorkAns + aageKaAns;
}




int sumOfArr(int arr[], int n){
	if(n == 0)
		return 0;

	int selfWorkAns = arr[n-1];
	int aageKaAns = sumOfArr(arr, n-1);
	return selfWorkAns + aageKaAns;
}

int sumOfArrUsingPointerConcept(int arr[], int n){
	if(n == 1)
		return arr[0];
	return arr[0] + sumOfArrUsingPointerConcept(arr+1, n-1);
}


int main(){

	int arr[5] = {8,3,6,1,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<sumOfArr(arr, 0, n-1)<<endl;
	cout<<sumOfArr(arr, n)<<endl;
	cout<<sumOfArrUsingPointerConcept(arr, n)<<endl;

	return 0;
}