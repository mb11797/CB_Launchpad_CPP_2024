#include<iostream>
#include<vector>
using namespace std;

void permute(string s, int curIdx, vector<string> &ans){
	if(curIdx == s.length()){
		ans.push_back(s);
		return;
	}

	for(int i=curIdx; i<s.length(); i++){
		swap(s[curIdx], s[i]);
		permute(s, curIdx+1, ans);
	}
}


int main(){

	string s;
	cin>>s;

	vector<string> ans;
	permute(s, 0, ans);

	cout<<endl;
	for(string str: ans)
		cout<<str<<endl;
	cout<<endl;

	return 0;
}