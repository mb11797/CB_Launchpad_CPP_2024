#include<iostream>
#include<vector>
using namespace std;

int editDistance(string &s1, string &s2, int i, int j, vector<vector<int> > &memo){
	if(i < 0)
		return j+1;
	if(j < 0)
		return i+1;

	if(memo[i][j] != -1){
		return memo[i][j];
	}

	int ans = INT_MAX;
	if(s1[i] == s2[j]){
		ans = editDistance(s1, s2, i-1, j-1, memo);
	}
	else{
		int insert = 1 + editDistance(s1, s2, i, j-1, memo);
		int remove = 1 + editDistance(s1, s2, i-1, j, memo);
		int replace = 1 + editDistance(s1, s2, i-1, j-1, memo);

		ans = min(insert, min(remove, replace));
	}

	return memo[i][j] = ans;
}

int main(){

	string s1, s2;

	cin>>s1>>s2;

	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int> > memo(n1, vector<int>(n2, -1));

	cout<<editDistance(s1, s2, n1-1, n2-1, memo)<<endl;

	return 0;
}