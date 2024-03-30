#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;	


	// cout<<n;

	int arr[n];		// declare an array
	for(int i=0; i<n; i++)
		cin>>arr[i];

	// cout<<arr<<endl;		// prints address of starting block
	cout<<endl;

	// for(int i=0; i<8; i++)
	// 	cout<<arr[i]<<" ";
	// cout<<endl;

	cout<<"Elements at even index: "<<endl;
	for(int i=0; i<n; i++){
		if(i%2 == 0)
			cout<<arr[i]<<" ";
	}

	cout<<endl;

	int key;
	cin>>key;

	// Search in unordered array
	for(int i=0; i<n; i++)	{
		if(arr[i] == key){
			cout<<"Found "<<key<<" at "<<i<<endl;
		}
	}

	for(int i=n-1; i>=0; i--)	{
		if(arr[i] == key){
			cout<<"Found "<<key<<" at "<<i<<endl;
		}
	}

	// Max in an array
	int maxm = arr[0];
	for(int i=1; i<n; i++)	{
		if(arr[i] > maxm){
			maxm = arr[i];
		}
	}
	cout<<"Maximum: "<<maxm<<endl;

	// Min in an array
	int minm = arr[0];
	for(int i=1; i<n; i++)	{
		if(arr[i] < minm){
			minm = arr[i];
		}
	}
	cout<<"Minimum: "<<minm<<endl;
	



	return 0;
}



