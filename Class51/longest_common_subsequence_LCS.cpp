#include<iostream>
using namespace std;

int lcs(string s1, string s2, int i, int j){
	if(i == s1.length() || j == s2.length()){
		return 0;
	}

	if(s1[i] == s2[j]){
		return 1 + lcs(s1, s2, i+1, j+1);
	}
	else{
		// return max(lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1));
		int option1 = lcs(s1, s2, i+1, j);
		int option2 = lcs(s1, s2, i, j+1);

		return max(option1, option2);
	}
}

int lcs(string s1, string s2){
	return lcs(s1, s2, 0, 0);
}

int main(){
	string s1, s2;
	cin>>s1>>s2;

	cout<<lcs(s1, s2)<<endl;		// longest common subsequence
	return 0;
}