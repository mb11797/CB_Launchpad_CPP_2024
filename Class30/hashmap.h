#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T val;
	Node*next;
	Node(string key, T val){
		this->key = key;
		this->val = val;
		next = NULL;
	}

	// Destructor
	~Node(){
		if(next != NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashmap{
	Node<T>** hTable;
	int tableSize;	// current size of hash table
	int curSize;	// current size of hashmap
	float IDEAL_LOAD_FACTOR = 0.75;

	int hashFn(string key){
		int pFactor = 1;
		int idx = 0;
		for(char ch: key){
			idx = (idx + (pFactor * ch)) % tableSize;
			pFactor = (pFactor * 47) % tableSize;
		}
		return idx;
	}

	void rehash(){
		int oldTableSize = tableSize;
		tableSize = 2*tableSize + 1;	// odd tableSize has less chances of collision

		Node<T>**oldHTable = hTable;

		hTable = new Node<T>*[tableSize];
		for(int i=0; i<tableSize; i++){
			hTable[i] = NULL;
		}

		curSize = 0;

		// copy nodes from to new hTable

		for(int i=0; i<oldTableSize; i++){
			Node<T>*ithListHead = oldHTable[i];
			Node<T>*temp = ithListHead;
			while(temp != NULL){
				insert(temp->key, temp->val);
				temp = temp->next;
			}
			delete oldHTable[i];
		}

	}

public:
	Hashmap(int tSize=5){
		tableSize = tSize;
		hTable = new Node<T>*[tableSize];
		for(int i=0; i<tableSize; i++){
			hTable[i] = NULL;
		}
		curSize = 0;
	}

	void insert(string key, T val){
		int idx = hashFn(key);
		cout<<"hashFn("<<key<<"): "<<idx<<endl;

		Node<T>*head = hTable[idx];

		Node<T>* n = new Node<T>(key, val);
		// insert new Node at head
		n->next = head;
		head = n;
		hTable[idx] = head;

		curSize++;

		float loadFactor = (1.0*curSize) / (1.0*tableSize);
		// cout<<"loadFactor: "<<loadFactor<<endl;

		if(loadFactor > IDEAL_LOAD_FACTOR){
			cout<<"Rehashing..."<<endl;
			rehash();
		}
	}

	void print(){
		for(int i=0; i<tableSize; i++){
			Node<T>*temp = hTable[i];
			cout<<i<<" -> ";
			while(temp != NULL){
				cout<<"("<<temp->key<<", "<<temp->val<<") -> ";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
	}

	T* search(string key){
		int idx = hashFn(key);

		Node<T>* temp = hTable[idx];

		while(temp){
			if(temp->key == key){
				return &(temp->val);
			}
			temp = temp->next;
		}
		return NULL;
	}

	int size(){
		return curSize;
	}

	void erase(string key){
		int idx = hashFn(key);

		Node<T>*&ithListHead = hTable[idx];
		if(ithListHead->key == key){
			// M-1
			// ithListHead = ithListHead->next;
			// // M-2
			hTable[idx] = ithListHead->next;
			return;
		}

		Node<T>*temp = ithListHead;
		Node<T>*prev = NULL;
		
		while(temp != NULL){
			if(temp->key == key){
				// Delete this node
				prev->next = temp->next;
				if(temp->next)
					temp->next = NULL;
				delete temp;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		curSize--;
	}
};
