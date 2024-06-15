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

Node*getTailNode(Node*head){
	Node*tail = head;
	while(tail != NULL && tail->next != NULL){
		tail = tail->next;
	}
	return tail;
}

bool detectCycle(Node*head){
	Node*slow = head;
	Node*fast = head;

	while(fast != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			cout<<"slow aur fast are equal at Node = "<<slow->data<<endl;
			return true;
		}
	}
	return false;
}

Node*detectCycleStartIfCycleIsPresent(Node*head){
	Node*slow = head;
	Node*fast = head;

	while(fast != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			cout<<"slow aur fast are equal at Node = "<<slow->data<<endl;
			break;
		}
	}

	if(fast != NULL){
		// Loop toh hai
		slow = head;
		while(slow->next != fast->next){
			slow = slow->next;
			fast = fast->next;
		}
		return fast->next;
	}

	return NULL;
}

void detectAndBreakCycleIfCycleIsPresent(Node*&head){
	Node*slow = head;
	Node*fast = head;

	while(fast != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			cout<<"slow aur fast are equal at Node = "<<slow->data<<endl;
			break;
		}
	}

	if(fast != NULL){
		// Loop toh hai
		slow = head;
		while(slow->next != fast->next){
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}
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

	Node*head = createLinkedListFromUser();

	Node*tail = getTailNode(head);

	// Form Cycle in LinkedList -> Assumption is Linked List has 3+ Nodes
	tail->next = head->next->next;
	cout<<"tail: "<<tail->data<<" connected to Node: "<<head->next->next->data<<endl;


	cout<<(detectCycle(head) ? "Cycle Present hai" : "Cycle Present Nahin hai")<<endl;

	Node*cycleStart = detectCycleStartIfCycleIsPresent(head);

	if(cycleStart != NULL){
		cout<<"Cycle mil gayi at point: "<<cycleStart->data<<endl;
	}
	else{
		cout<<"Cycle nhn mili"<<endl;
	}

	detectAndBreakCycleIfCycleIsPresent(head);
	printLinkedList(head);

	return 0;
}
