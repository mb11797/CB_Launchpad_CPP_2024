#include<iostream>
#include<stack>
using namespace std;

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


	stack<int> helper1;
	while(!stk.empty()){
		helper1.push(stk.top());
		stk.pop();
	}

	stack<int> helper2;
	while(!helper1.empty()){
		helper2.push(helper1.top());
		helper1.pop();
	}

	while(!helper2.empty()){
		stk.push(helper2.top());
		helper2.pop();
	}

	cout<<"Print original reversed stk: "<<endl;
	printStack(stk);

	return 0;
}
