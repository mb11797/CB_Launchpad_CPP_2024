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

Node*reverseLL_Recursive(Node*&head){
	if(head == NULL || head->next == NULL)
		return head;

	Node*revHead = reverseLL_Recursive(head->next);

	head->next->next = head;
	head->next = NULL;

	return revHead;
}

int main(){

	Node*head = createLinkedListFromUser();
	printLinkedList(head);

	printLinkedList(reverseLL_Recursive(head));	

	return 0;
}