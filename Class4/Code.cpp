#include<iostream>
using namespace std;

int main(){

	// int n;
	// cin>>n;	


	// Comments: 
	// 1. // -> Single Line Comment
	// 2. /* */ -> Multi Line Comment


	/*
	// break
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if(i <= 2){
				cout<<"j = " <<j<<" | "<<"i = "<<i<<endl;
			}
			else{
				break;
			}
		}
		cout<<endl;
	}
	*/

	// continue
	// e.g, print all even nos till n
	/*
	for(int i=0; i<n; i++){
		if(i % 2 != 0)
			continue;
		cout<<i<<" ";
	}
	*/

	/*
	for(int i=0; i<n; i++){
		if(i % 2 != 0)
			continue;
		if(i == 9)
			cout<<"Reached 9"<<endl;
	}
	*/


	// Print digits of a no in reverse direction
	/*
	while(n > 0){
		cout<<n%10<<" ";
		n /= 10;
	}
	cout<<endl;
	*/

	// Inc / Dec Operators
	/*
	int a = 10;
	int b = a++;
	int c = b++ + ++a;

	cout<<a<<" "<<b<<" "<<c<<endl;
	// 12 11 22

	int d = c-- + --b;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	// 12 10 21 32 

	int e = a++ + c-- + d--;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
	// 13 10 20 31 65
	*/

	/*
	char ch;
	while(ch != '$'){
		cin>>ch;
		cout<<ch;
	}
	cout<<endl;
	*/

	/*
	char ch = 'A';					// ASCII = 65
	cout<<ch + 2<<endl;				// 67 -> Internal / Implicit
	cout<<(char)(ch + 2)<<endl;		// C -> Explicit Type Casting
	/*

	
	

	return 0;
}





