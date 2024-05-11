#include<iostream>
#include<vector>
using namespace std;

double multiply(double el, int n){
	double prod = 1.0;
	while(n--){
		prod *= el;
	}
	return prod;
}

double nthRootUsingBinarySearch(int m, int n){

	double beg = 1.0;
	double en = m;
	double delta = 0.000001;	// 10^-1

	// beg <= en -> 0 <= en - beg
	while(en - beg > delta){
		double mid = (beg + en) / 2.0;

		double prod = multiply(mid, n);

		if(prod < m){
			beg = mid;
		}
		else{
			en = mid;
		}
	}

	cout<<beg<<" "<<en<<endl;
	return beg;
}

int main(){

	int m;
	cin>>m;

	int n;
	cin>>n;

	// find nth root of m

	// m = 1024, n = 4 -> 4th root of 1024

	cout<<nthRootUsingBinarySearch(m, n)<<endl;

	return 0;
}