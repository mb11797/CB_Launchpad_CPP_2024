#include<iostream>
#include<vector>
using namespace std;

int findStartPos(vector<int> arr, int key){
	int beg = 0;
	int en = arr.size()-1;

	int ans = -1;
	while(beg <= en){
		int mid = (beg + en) / 2;
		if(arr[mid] > key){
			en = mid-1;
		}
		else if(arr[mid] < key){
			beg = mid+1;
		}
		else{
			ans = mid;
			en = mid-1;
		}
	}

	return ans;
}

int findEndPos(vector<int> arr, int key){
	int beg = 0;
	int en = arr.size()-1;

	int ans = -1;
	while(beg <= en){
		int mid = (beg + en) / 2;
		if(arr[mid] > key){
			en = mid-1;
		}
		else if(arr[mid] < key){
			beg = mid+1;
		}
		else{
			ans = mid;
			beg = mid+1;
		}
	}

	return ans;
}


int main(){
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}

	int key;
	cin>>key;

	cout<<"Array: "<<endl;
	for(int el: arr)
		cout<<el<<" ";
	cout<<endl;

	cout<<"Key = "<<key<<" found in range = {"<<findStartPos(arr, key)<<", "<<findEndPos(arr, key)<<"}"<<endl;
	
	return 0;
}