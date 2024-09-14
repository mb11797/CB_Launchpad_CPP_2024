#include<iostream>
using namespace std;

int editDistance(string s1, string s2, int i, int j){
	if(i < 0)
		return j+1;
	if(j < 0)
		return i+1;

	int ans = INT_MAX;
	if(s1[i] == s2[j]){
		ans = editDistance(s1, s2, i-1, j-1);
	}
	else{
		int insert = 1 + editDistance(s1, s2, i, j-1);
		int remove = 1 + editDistance(s1, s2, i-1, j);
		int replace = 1 + editDistance(s1, s2, i-1, j-1);

		ans = min(insert, min(remove, replace));
	}

	return ans;
}

int main(){

	string s1, s2;

	cin>>s1>>s2;

	cout<<editDistance(s1, s2, s1.length()-1, s2.length()-1)<<endl;

	return 0;
}