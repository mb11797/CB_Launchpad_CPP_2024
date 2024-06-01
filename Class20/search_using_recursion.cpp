#include<iostream>
using namespace std;

bool searchInArrRec(int arr[], int n, int elmtToSearch, int curIdx){
	if(curIdx == n){
		return false;
	}

	if(arr[curIdx] == elmtToSearch){
		return true;
	}

	bool aageMilaKyaElmt = searchInArrRec(arr, n, elmtToSearch, curIdx+1);
	return aageMilaKyaElmt;
}

int findFirstOccurenceInArrRec(int arr[], int n, int elmtToSearch, int curIdx){
	if(curIdx == n){
		return -1;
	}

	if(arr[curIdx] == elmtToSearch){
		return curIdx;
	}

	int aageMilaKyaElmt = findFirstOccurenceInArrRec(arr, n, elmtToSearch, curIdx+1);
	return aageMilaKyaElmt;
}

int findLastOccurenceInArrRec_Alternate(int arr[], int n, int elmtToSearch, int curIdx){
	if(curIdx == n){
		return -1;
	}

	int aageKaAns = findLastOccurenceInArrRec_Alternate(arr, n, elmtToSearch, curIdx+1);

	if(aageKaAns > 0)
		return aageKaAns;

	if(arr[curIdx] == elmtToSearch){
		return curIdx;
	}

	return aageKaAns;
}

void findLastOccurenceInArrRec(int arr[], int n, int elmtToSearch, int curIdx, int &lastOcc){
	if(curIdx == n){
		return;
	}

	if(arr[curIdx] == elmtToSearch){
		lastOcc = curIdx;
	}

	findLastOccurenceInArrRec(arr, n, elmtToSearch, curIdx+1, lastOcc);
}


void printAllOccurences(int arr[], int n, int elmtToSearch, int curIdx){
	if(curIdx == n){
		cout<<endl;
		return;
	}

	if(arr[curIdx] == elmtToSearch){
		cout<<curIdx<<" ";
	}

	printAllOccurences(arr, n, elmtToSearch, curIdx+1);
}



int main(){

	int arr[6] = {2,4,1,3,7,8};

	int n = 6;

	int elmtToSearch = 7;




	int curIdx = 0;
	cout<<(searchInArrRec(arr, n, elmtToSearch, curIdx) ? "Mil gaya " : "Nahin Mila ")<<elmtToSearch<<endl;
 	cout<<findFirstOccurenceInArrRec(arr, n, elmtToSearch, curIdx)<<endl;

 	int lastOcc = -1;

 	int arr1[8] = {1,3,2,7,5,7,7,8};

 	findLastOccurenceInArrRec(arr1, 8, elmtToSearch, curIdx, lastOcc);
 	cout<<lastOcc<<endl;

 	printAllOccurences(arr1, 8, elmtToSearch, curIdx);

 	cout<<findLastOccurenceInArrRec_Alternate(arr1, 8, elmtToSearch, curIdx)<<endl;

	return 0;
}