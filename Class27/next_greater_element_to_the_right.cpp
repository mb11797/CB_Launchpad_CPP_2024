#include<iostream>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr){
	int n = arr.size();
	vector<int> nge(n);

	stack<int> stk;		// for pending_work

	for(int i=0; i<n; i++){
		while(!stk.empty() && arr[stk.top()] < arr[i]){
			nge[stk.top()] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}

	while(!stk.empty()){
		nge[stk.top()] = -1;
		stk.pop();
	}

	return nge;
}


int main(){

	vector<int> arr;
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

	vector<int> nge = nextGreaterElement(arr);

	return 0;
}