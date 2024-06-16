#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &sourceStack, stack<int> &targetStack, int n){
	for(int i=0; i<n; i++){
		targetStack.push(sourceStack.top());
		sourceStack.pop();
	}
}

void reverseStack(stack<int> &stk){
	int n = stk.size();
	stack<int> helper;
	
	for(int i=0; i<n; i++){
		int x = stk.top();
		stk.pop();

		transfer(stk, helper, n-i-1);
		stk.push(x);
		transfer(helper, stk, n-i-1);
	}
	return;
}

void printStack(stack<int> stk){
	while(!stk.empty()){
		cout<<stk.top()<<endl;
		stk.pop();
	}
	return;
}

int main(){
	int n;
	cin>>n;

	stack<int> stk;
	for(int i=1; i<=n; i++)
		stk.push(i);

	reverseStack(stk);

	cout<<"Print original reversed stk: "<<endl;
	printStack(stk);

	return 0;
}
