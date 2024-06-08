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

void printLinkedList(Node*head){
	Node*temp = head;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

int main(){

	Node*head = new Node(1);

	Node*n;
	n = new Node(2);

	n->data = 5;

	head->next = n;

	Node*n1 = new Node(3);
	n->next = n1;
	Node*n2 = new Node(4);
	n1->next = n2;


	// head -> 1 -> 5 -> 3 -> 4 -> NULL

	cout<<head->data<<endl;
	cout<<head->next->data<<endl;
	cout<<head->next->next->data<<endl;

	printLinkedList(head);
	printLinkedList(n1);

	return 0;
}