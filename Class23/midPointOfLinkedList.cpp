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

Node*midPointOfLL(Node*head){
	Node*slow = head;
	Node*fast = head;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main(){

	Node*head = createLinkedListFromUser();
	printLinkedList(head);

	Node*midPt = midPointOfLL(head);
	cout<<"Mid Point of LL: "<<midPt->data<<endl;

	return 0;
}