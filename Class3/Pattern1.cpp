#include<iostream>
using namespace std;


int main(){
	// Read n
	int n;
	cin>>n;


	int i=1;
	
	while(i<=n){
		int j=1; 
		while(j<=i){
			cout<<"*\t";
			j++;
		}
		cout<<endl;
		i = i+1;
	}

	return 0;
}
