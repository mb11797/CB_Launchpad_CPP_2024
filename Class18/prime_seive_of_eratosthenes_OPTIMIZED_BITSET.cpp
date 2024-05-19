#include<iostream>
using namespace std;

#define ll long long

bitset<10000001> primeSeive;

void primeSeiveOfEratosthenes(){
	int n = 10000001;

	primeSeive[0] = primeSeive[1] = 0;
	// 2 -> special case -> even no being prime
	primeSeive[2] = 1;

	// make all odd nos true / 1 -> give all odd nos the chance to be prime
	for(ll i=3; i<=n; i+=2){
		primeSeive[i] = 1;
	}

	// if any primeSeive[i] => true / 1 -> i is a prime no -> So all its multiples should be made false / 0
	for(ll i=3; i<=n; i+=2){
		if(primeSeive[i] == 1){
			for(ll j=i*i; j<=n; j+=2*i){
				primeSeive[j] = 0;
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