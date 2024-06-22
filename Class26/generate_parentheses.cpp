#include<iostream>
#include<stack>
using namespace std;

void generateParentheses(int n, string osf, int open, int close, vector<string> &ans){
	if(open == n and close == n){
		ans.push_back(osf);
		return;
	}

	if(open < n){
		generateParentheses(n, osf+'(', open+1, close, ans);		
	}

	if(close < open){
		generateParentheses(n, osf+')', open, close+1, ans);
	}

}

int main(){

	int n;
	cin>>n;

	vector<string> ans;
	string osf = "";
	generateParentheses(n, osf, 0, 0, ans);

	for(string s: ans){
		cout<<s<<"\t";
	}
	cout<<endl;

	return 0;
}