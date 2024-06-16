#include<iostream>
#include<vector>
using namespace std;

class Stack{
private:
	vector<int> vec;

public:

	Stack(){
		vec = vector<int>();
	}

	void push(int el){
		vec.push_back(el);
	}

	int pop(){
		int lastEl = vec[vec.size()-1];
		vec.pop_back();
		return lastEl;
	}

	int top(){
		return vec[vec.size()-1];
	}

	int size(){
		return vec.size();
	}

	bool empty(){
		return vec.size() == 0;
	}
};

int main(){

	Stack*stk = new Stack();
	stk->push(1);
	stk->push(2);
	stk->push(3);
	stk->push(4);
	// We will be able to use vec in main() function if vec is declared public, which is a big loop hole
	// stk->vec.push_back(5);
	// cout<<"3rd element in stack: "<<stk->vec[2]<<endl;


	cout<<"Size : "<<stk->size()<<endl;
	cout<<"Top : "<<stk->top()<<endl;

	cout<<"Elements:"<<endl;
	while(!stk->empty()){
		cout<<stk->pop()<<endl;
	}
	cout<<endl;


	return 0;
}
