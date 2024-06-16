#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	T data;
	Node<T>*next;
	Node(T data){
		this->data = data;
		this->next = NULL;
	}
};

template<typename T>
class Stack{
private:
	Node<T>*head = NULL;
	int count = 0;
public:

	void push(T el){
		Node<T>*newNode = new Node<T>(el);
		newNode->next = head;
		head = newNode;
		count++;
	}

	T top(){
		if(head == NULL){
			return NULL;
		}
		return head->data;
	}

	T pop(){
		if(head == NULL){
			return NULL;
		}

		T lastEl = head->data;
		head = head->next;
		count--;
		return lastEl;
	}

	int size(){
		return count;
	}

	bool empty(){
		return count == 0;
	}

};

int main(){
	Stack<char> stk;
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
