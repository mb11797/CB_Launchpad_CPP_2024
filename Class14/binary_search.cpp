#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int key){
	int beg = 0;
	int en = arr.size()-1;

	while(beg <= en){
		int mid = (beg + en) / 2;
		if(arr[mid] > key){
			en = mid-1;
		}
		else if(arr[mid] < key){
			beg = mid+1;
		}
		else{
			return mid + 1;
		}
	}

	return -1;
}


int main(){
	int sortedArr[6] = {1,3,18,23,27,39};
	vector<int> arr(sortedArr, sortedArr+6);
	int key = 27;

	cout<<"Array: "<<endl;
	for(int el: arr)
		cout<<el<<" ";
	cout<<endl;

	cout<<"Key = "<<key<<" found at position = "<<binarySearch(arr, key)<<endl;
	
	return 0;
}