#include<iostream>
#include<stack>
using namespace std;

bool isBalancedExpression(string exp){
	stack<char> stk;

	for(char ch: exp){
		if(ch == '('){
			stk.push(ch);
		}
		else if(ch == ')'){
			if(stk.empty()){
				return false;
			}
			stk.pop();
		}
	}

	return stk.empty();
}

int main(){
	string exp;
	cin>>exp;

	cout<<(isBalancedExpression(exp) ? "Balanced" : "Not Balanced")<<endl;
	return 0;
}