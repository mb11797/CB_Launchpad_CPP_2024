#include<iostream>
#include<string>
using namespace std;

string getSubseq(string s, int n){
	int i=0;
	string subseq = ""; 
	while(n > 0){
		if((n & 1) > 0){
			subseq = subseq + s[i];
		}
		n = n >> 1;
		i++;
	}
	return subseq;
}

void subsequences(string s){
	int n = s.length();
	// 2^n = pow(2, n) = 1<<n
	for(int i=0; i < (1<<n); i++){
		cout<<getSubseq(s, i)<<endl;
	}
	return;
}

int main(){
	string s;
	cin>>s;

	subsequences(s);

	return 0;
}