#include<iostream>
#include<stack>
using namespace std;

bool balancedExpression(string s){

	int n = s.length();
	stack<char> stk;

	for(int i=0; i<n; i++){
		if(s[i] == '('){
			stk.push(s[i]);
		}
		else if(s[i] == ')'){
			if(stk.empty()){
				return false;
			}
			stk.pop();
		}
	}

	return stk.empty();
}

int main(){
	string expression;
	cin>>expression;

	cout<<(balancedExpression(expression) ? "Balanced Hai" : "Balanced nhn hai")<<endl;

	return 0;
}