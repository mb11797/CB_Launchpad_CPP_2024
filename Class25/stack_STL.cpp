#include<iostream>
#include<stack>
using namespace std;


int main(){
	stack<int> stk;

	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);

	cout<<"Size: "<<stk.size()<<endl;
	cout<<"Top: "<<stk.top()<<endl;

	cout<<"Elements: "<<endl;
	while(!stk.empty()){
		cout<<stk.top()<<endl;
		stk.pop();
	}
	cout<<endl;

	return 0;
}
