#include<iostream>
using namespace std;

void findTargetSum(int arr[], int n, int targetSum){

	int beg = 0, en = n-1;
	while(beg < en){
		if(arr[beg] + arr[en] == targetSum){
			cout<<arr[beg]<<", "<<arr[en]<<endl;
			return;
		}
		else if(arr[beg] + arr[en] < targetSum){
			beg++;
		}
		else{
			en--;
		}
	}

	cout<<"No pair of elements found with targetSum = "<<targetSum<<endl;
	return;
}

int main(){
	int arr[6] = {2,7,11,15,23,31};
	int targetSum = 34;
	findTargetSum(arr, 6, targetSum);

	return 0;
}

