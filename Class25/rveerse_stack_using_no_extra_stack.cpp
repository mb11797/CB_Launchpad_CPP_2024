#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &stk, int el){
	if(stk.empty()){
		stk.push(el);
		return;
	}

	int x = stk.top();
	stk.pop();

	insertAtBottom(stk, el);

	stk.push(x);
}

void reverseStack(stack<int> &stk){
	if(stk.empty())
		return;

	int x = stk.top();
	stk.pop();

	reverseStack(stk);
	insertAtBottom(stk, x);

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
