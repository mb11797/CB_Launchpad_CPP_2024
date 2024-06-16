#include<iostream>
#include<vector>
using namespace std;

template<typename T, typename V>
class Stack{
private:
	vector<T> vec;
	vector<V> arr;		// Not getting used right now, just for Demo

public:
	void push(T el){
		vec.push_back(el);
	}

	T pop(){
		T lastEl = vec[vec.size()-1];
		vec.pop_back();
		return lastEl;
	}

	T top(){
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

	Stack<char, int> stk;
	stk.push('a');
	stk.push('b');
	stk.push('c');
	stk.push('d');

	cout<<"Size : "<<stk.size()<<endl;
	cout<<"Top : "<<stk.top()<<endl;

	cout<<"Elements:"<<endl;
	while(!stk.empty()){
		cout<<stk.pop()<<endl;
	}
	cout<<endl;


	return 0;
}
