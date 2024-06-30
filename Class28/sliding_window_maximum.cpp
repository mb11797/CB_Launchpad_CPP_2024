#include<iostream>
#include<deque>
using namespace std;

void printSlidingWindowMax(int arr[], int n, int k){

	deque<int> deq;

	/* M-1
	int i=0;
	for(; i<k; i++){
		while(!deq.empty() && arr[deq.back()] < arr[i])
			deq.pop_back();
		deq.push_back(i);
	}

	for(; i<n; i++){
		cout<<arr[deq.front()]<<" ";

		while(!deq.empty() && deq.front() <= i-k)
			deq.pop_front();


		while(!deq.empty() && arr[deq.back()] <= arr[i])
			deq.pop_back();	

		deq.push_back(i);
	}
	*/

	// M-2: Single Loop
	for(int i=0; i<n; i++){
		if(i >= k)
			cout<<arr[deq.front()]<<" ";

		if(!deq.empty() && deq.front() <= i-k)
			deq.pop_front();


		while(!deq.empty() && arr[deq.back()] <= arr[i])
			deq.pop_back();	

		deq.push_back(i);
	}

	cout<<arr[deq.front()]<<" "<<endl;
	return;
}

int main(){

	// int arr[9] = {1,2,3,1,4,5,2,3,6};
	int arr[9] = {3,2,1,1,1,1,1,2,3};
	int k = 3, n = 9;

	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	printSlidingWindowMax(arr, n, k);



	return 0;
}
