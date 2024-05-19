#include<iostream>
using namespace std;

#define ll long long

bool primeSeive[10000001];

void primeSeiveOfEratosthenes(){	
	int n = 10000001;
	memset(primeSeive, false, sizeof(primeSeive));

	// 2 -> special case -> even no being prime
	primeSeive[2] = true;

	// make all odd nos true -> give all odd nos the chance to be prime
	for(int i=3; i<=n; i+=2){
		primeSeive[i] = true;
	}

	// if any primeSeive[i] => true -> i is a prime no -> So all its multiples should be made false
	for(int i=3; i<=n; i+=2){
		if(primeSeive[i] == true){
			for(int j=2*i; j<=n; j+=i){
				primeSeive[j] = false;
			}
		}
	}

	return;
}

int main(){

	primeSeiveOfEratosthenes();

	int beg, en;
	cin>>beg>>en;

	for(int i=beg; i<=en; i++){
		if(primeSeive[i])
			cout<<i<<", ";
	}
	cout<<endl;

	return 0;
}