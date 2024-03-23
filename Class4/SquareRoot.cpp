#include<iostream>
using namespace std;

int main(){

	int n;
	cin>>n;	// positive no

	int ans = 0;

	for(int i=0; i<=n; i++){
		if(i*i == n){
			ans = i;
		}
		else if(i*i < n){
			ans = i;
		}
		else{
			break;
		}	// i*i > n

	}

	cout<<ans<<endl;

	return 0;
}
