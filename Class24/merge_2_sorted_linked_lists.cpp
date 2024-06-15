#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	Node(){}

	Node(int data){
		this->data = data;
		this->next = NULL;
	}

	Node(int data, Node*next){
		this->data = data;
		this->next = next;
	}
};

Node* createLinkedListFromUser(){

	int data;
	cin>>data;
	if(data == -1)
		return NULL;

	Node*head = new Node(data);			
	Node*temp = head;

	while(true){
		cin>>data;
		if(data == -1)
			break;
		temp->next = new Node(data);
		temp = temp->next;
	}
	return head;
}


Node*merge2SortedLinkedLists(Node*&a, Node*&b){
	if(a == NULL)
		return b;

	if(b == NULL)
		return b;

	Node*c;

	if(a->data < b->data){
		c = a;
		c->next = merge2SortedLinkedLists(a->next, b);
	}
	else{
		c = b;
		c->next = merge2SortedLinkedLists(a, b->next);
	}

	return c;
}

void printLinkedList(Node*head){
	Node*temp = head;
	while(temp){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
	return;
}

int main(){

	Node*a = createLinkedListFromUser();
	printLinkedList(a);
	Node*b = createLinkedListFromUser();
	printLinkedList(b);
	Node*mergedList = merge2SortedLinkedLists(a, b);
	printLinkedList(mergedList);
	return 0;
}


