#include<iostream>
using namespace std;

int lis(vector<int> arr, int curIdx, int prevIdx){

	if(curIdx == arr.size())
		return 0;

	int ans;
	// Case 1: Ignore curIdx wala element
	int option1 = lis(arr, curIdx+1, prevIdx);


	// Case 2: Try to use curIdx wala element
	int option2 = INT_MIN;
	if(prevIdx < 0 or (arr[curIdx] > arr[prevIdx])){
		option2 = 1 + lis(arr, curIdx+1, curIdx);
	}

	ans = max(option1, option2);
	return ans;
}

int lis(vector<int> arr){
	return lis(arr, 0, -1);
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout<<lis(arr)<<endl;


	return 0;
}