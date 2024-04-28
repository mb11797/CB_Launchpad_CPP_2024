#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reverse(string &s, int beg, int en){
	while(beg < en){
		swap(s[beg++], s[en--]);
	}
}

void rotate(string &s, int k){
	int n = s.length();
	reverse(s, 0, n-k-1);
	reverse(s, n-k, n-1);
	reverse(s, 0, n-1);
	cout<<s<<endl;
}

int main(){
	// string s = "naman";
	string s = "codingblock";
	cout<<s<<endl;

	int k = 5;

	rotate(s, k);
	return 0;
}