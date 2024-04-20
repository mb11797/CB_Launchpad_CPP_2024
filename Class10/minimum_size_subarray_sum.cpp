#include<iostream>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int target = 7;


	int minLen = INT_MAX;
	
	for(int i=0; i<n; i++){
		// i -> to select starting of current window

		for(int j=i; j<n; j++){
			// j -> to selet ending of current window

			// Print current Window
			int sum = 0;
			// curSubarray -> i to j
			// curSubarrayLen = j - i + 1
			int curSubarrayLen = j - i + 1;
			for(int k=i; k<=j; k++){
				sum = sum + arr[k];
			}

			if(sum >= target){
				if(curSubarrayLen < minLen){
					minLen = curSubarrayLen;
				}	
			}

			cout<<"Sum of Subarray from "<<i<<" -> "<<j<<" = "<<sum<<" | curSubarrayLen = "<<curSubarrayLen<<" | minLen = "<<minLen<<endl;
		}
		cout<<endl;
	}

	cout<<"Ans = "<<minLen<<endl;

	return 0;
}

