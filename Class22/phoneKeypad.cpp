#include<iostream>
#include<vector>
using namespace std;

string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits, int curIdx){
	if(curIdx == digits.size()){
		vector<string> ans;
		ans.push_back("");
		return ans;
	}
	vector<string> ans;
	vector<string> aageKaAns = letterCombinations(digits, curIdx+1);

	string s = dict[digits[curIdx] - '0'];

	for(char ch: s){
		for(string aageKaComb: aageKaAns){
			ans.push_back(ch + aageKaComb);
		}
	}
	return ans;
}


int main(){
	string digits;
	cin>>digits;


	vector<string> ans = letterCombinations(digits, 0);
	for(string s: ans)
		cout<<s<<" ";
	cout<<endl;

	return 0;
}