#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2, int i, int j, vector<vector<int> > &memo){
	if(i == s1.length() || j == s2.length()){
		return 0;
	}

	if(memo[i][j] != -1){
		return memo[i][j];
	}

	int ans;
	if(s1[i] == s2[j]){
		ans = 1 + lcs(s1, s2, i+1, j+1, memo);
	}
	else{
		// return max(lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1));
		int option1 = lcs(s1, s2, i+1, j, memo);
		int option2 = lcs(s1, s2, i, j+1, memo);

		ans = max(option1, option2);
	}

	return memo[i][j] = ans;
}

int lcs(string s1, string s2){

	int m = s1.length();
	int n = s2.length();
	vector<vector<int> > memo(m+1, vector<int>(n+1, -1));		// memo[m+1][n+1] -> memoization or dp[] -> m+1 x n+1

	return lcs(s1, s2, 0, 0, memo);
}

int main(){
	string s1, s2;
	cin>>s1>>s2;

	cout<<lcs(s1, s2)<<endl;		// longest common subsequence
	return 0;
}