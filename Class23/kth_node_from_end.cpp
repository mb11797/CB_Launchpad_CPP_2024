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

Node*findKthNodeFromEndOfLL(Node*head, int k){
	if(!head)
		return NULL;

	Node *slow = head, *fast = head;
	while(k--){
		fast = fast->next;
	}

	while(fast != NULL){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main(){

	Node*head = createLinkedListFromUser();
	printLinkedList(head);

	int k;
	cout<<"k = ";
	cin>>k;
	Node*kthNodeFromEnd = findKthNodeFromEndOfLL(head, k);
	cout<<"kth Node from end of LL: "<<kthNodeFromEnd->data<<endl;

	return 0;
}