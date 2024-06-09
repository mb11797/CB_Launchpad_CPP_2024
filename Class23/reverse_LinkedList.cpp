#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	Node(int data){
		this->data = data;
		this->next = NULL;
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

void printLinkedList(Node*head){
	Node*temp = head;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
	return;
}

Node*reverseLL(Node*&head){
	Node*prev = NULL;
	Node*curr = head;
	Node*nxt;

	while(curr){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	head = prev;
	return head;
}

int main(){

	Node*head = createLinkedListFromUser();
	printLinkedList(head);

	printLinkedList(reverseLL(head));	

	return 0;
}