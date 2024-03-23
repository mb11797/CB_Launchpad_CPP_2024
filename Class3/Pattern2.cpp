#include<iostream>
using namespace std;


int main(){
	// Read n
	int n;
	cin>>n;


	int i=1;
	while(i <= n){
		int j=n-(i-1);
		while(j >= 1){
			cout<<"* ";
			j--;
		}
		cout<<"\n";
		i++;
	}

	return 0;
}
