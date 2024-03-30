#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;	

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	// 0s, 1s and 2s
	int nZeroes = 0, nOnes = 0, nTwos = 0;
	for(int i=0; i<n; i++){
		if(arr[i] == 0){
			nZeroes++;
		}
		else if(arr[i] == 1){
			nOnes++;
		}
		else{
			nTwos++;
		}
	}

	cout<<nZeroes<<" "<<endl;
	cout<<nOnes<<" "<<endl;
	cout<<nTwos<<" "<<endl;	

	int i=0;
	while(nZeroes > 0){
		arr[i] = 0;
		i++;
		nZeroes--;
	}
	
	while(nOnes > 0){
		arr[i] = 1;
		i++;
		nOnes--;
	}

	while(nTwos > 0){
		arr[i] = 2;
		i++;
		nTwos--;
	}
	
	// Print an array
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;


	return 0;
}


