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

void insertAtHeadInLL(Node*&head, int data){
	Node*newNode = new Node(data);
	newNode->next = head;
	head = newNode;
	return;
}

void insertAtTailInLL(Node*&head, int data){
	if(head == NULL){
		head = new Node(data);
		return;
	}

	Node*temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	// M-1
	// Node*newNode = new Node(data);
	// temp->next = newNode;

	// M-2
	temp->next = new Node(data);

	return;
}

void insertAtSomeMidPosInLL(Node*&head, int data, int pos){
	if(head == NULL){
		head = new Node(data);
		return;
	}

	Node*temp = head;
	int count = 0;
	while(count < pos-1 && temp->next != NULL){
		temp = temp->next;
		count++;
	}

	Node*newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;

	return;
}

void deleteFromHeadInLL(Node*&head){
	if(head == NULL)
		return;

	Node*temp = head;
	head = head->next;
	// For Concerned Citizens Only
	temp->next = NULL;
	delete temp;
	return;
}

void deleteFromTailInLL(Node*&head){
	if(head == NULL || head->next == NULL){
		head = NULL;
		return;
	}

	Node*temp = head;
	while(temp != NULL && temp->next != NULL && temp->next->next != NULL){
		temp = temp->next;
	}

	Node*nodeToDelete = temp->next;
	temp->next = NULL;
	delete nodeToDelete;

	return;
}

void deleteFromSomeMidPosInLL(Node*&head, int pos){
	if(head == NULL)
		return;

	Node*temp = head;
	int count = 1;
	while(count < pos - 1){
		temp = temp->next;
		if(temp->next == NULL){
			cout<<"Position is out of bounds of LinkedList Length"<<endl;
			return;
		}
		count++;
	}
	Node*nodeToDelete = temp->next;
	temp->next = temp->next->next;
	nodeToDelete->next = NULL;
	delete nodeToDelete;
	return;
}

bool searchInLL(Node*head, int key){
	// NULL -> false
	// !NULL -> true
	// Conclusion -> head == NULL is same as !head
	if(!head){
		return false;
	}

	Node*temp = head;
	while(temp){
		if(temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

bool searchInLL_Recursive(Node*head, int key){
	if(!head)
		return false;
	if(head->data == key){
		return true;
	}
	return searchInLL_Recursive(head->next, key);
}

int lengthOfLL(Node*head){
	int count = 0;
	Node*temp = head;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

int main(){

	cout<<"Creating LL: "<<endl;
	Node*head = createLinkedListFromUser();
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);

	cout<<"Insert at Head in LL: "<<endl;
	int data;
	cin>>data;
	insertAtHeadInLL(head, data);
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);

	cout<<"Insert at Tail in LL: "<<endl;
	cin>>data;
	insertAtTailInLL(head, data);
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);


	cout<<"Insert at Pos in LL: "<<endl;
	int pos;
	cout<<"Pos = ";
	cin>>pos;
	cin>>data;
	insertAtSomeMidPosInLL(head, data, pos);
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);


	cout<<"Delete from Head in LL: "<<endl;
	deleteFromHeadInLL(head);
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);


	cout<<"Delete from Tail in LL: "<<endl;
	deleteFromTailInLL(head);
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);

	cout<<"Delete from Pos in LL: "<<endl;
	cin>>pos;
	deleteFromSomeMidPosInLL(head, pos);
	cout<<"Printing LL: "<<endl;
	printLinkedList(head);

	cout<<"Search in LL: "<<endl;
	int key;
	cin>>key;
	cout<<(searchInLL(head, key) ? "Found " : "Not Found ")<<key<<endl;
	cin>>key;
	cout<<(searchInLL(head, key) ? "Found " : "Not Found ")<<key<<endl;

	cout<<"Length of LinkedList: "<<lengthOfLL(head)<<endl;

	return 0;
}