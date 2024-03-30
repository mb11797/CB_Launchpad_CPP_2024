#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;	

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	// logic:
	int beg = 0, en = n-1;
	bool kyaPalindromHai = true;
	while(beg <= en){
		if(arr[beg] == arr[en]){
			beg++;
			en--;
		}
		else{
			kyaPalindromHai = false;
			cout<<"Not a palindrome"<<endl;
			break;
		}
	}

	if(kyaPalindromHai){
		cout<<"Palindrome"<<endl;
	}


	return 0;
}


