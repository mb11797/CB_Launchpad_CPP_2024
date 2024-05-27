#include<iostream>
#include<cstring>
using namespace std;

string dictionary[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printGame(int n){
	// Base case
	if(n < 10){
		cout<<dictionary[n]<<" ";
		return;
	}
	// printGame(n) = printGame(n/10) + " " + dictionary[n%10]

	printGame(n/10);				// recursive call
	cout<<dictionary[n%10]<<" ";	// self work
}


int main(){
	int n;
	cin>>n;

	printGame(n);
	cout<<endl;

	return 0;
}