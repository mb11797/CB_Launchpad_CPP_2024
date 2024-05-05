#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int key, bool searchForStartPos){
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
			if(searchForStartPos)
				en = mid-1;
			else
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

	cout<<"Key = "<<key<<" found in range = {"<<binarySearch(arr, key, true)<<", "<<binarySearch(arr, key, false)<<"}"<<endl;
	
	return 0;
}