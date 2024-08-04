#include<iostream>
#include<vector>
using namespace std;

class Heap{
	vector<int> v;	// private member variable
	bool minHeap;

	bool compare(int child, int parent){
		if(minHeap)
			return parent > child;		// swap required if parent > child
		else
			return parent < child;		// swap required if parent < child
	}

	void heapify(int idx){
		int lftChildIdx = 2*idx;
		int rytChildIdx = 2*idx + 1;

		int minIdx = idx;
		if(lftChildIdx < v.size() && compare(v[lftChildIdx], v[minIdx])){
			minIdx = lftChildIdx;
		}

		if(rytChildIdx < v.size() && compare(v[rytChildIdx], v[minIdx])){
			minIdx = rytChildIdx;
		}

		// 3 possibilities -> 
		// Case 1. minIdx = idx -> Do nothing -> element has reached it 
		// Case 2. minIdx = lftChildIdx -> swap(v[idx], v[minIdx]) 
		// Case 3. minIdx = rytChildIdx -> swap(v[idx], v[minIdx])

		if(minIdx != idx){
			swap(v[idx], v[minIdx]);
			heapify(minIdx);
		}
	}

public:
	Heap(bool minHeap = true){
		v = vector<int>();
		v.push_back(-1);
		this->minHeap = minHeap;
	}

	void push(int el){
		v.push_back(el);

		int curIdx = v.size()-1;
		int parentIdx = curIdx / 2;

		// upward heapify()
		while(curIdx > 1 && compare(v[curIdx], v[parentIdx])){
			swap(v[curIdx], v[parentIdx]);
			curIdx = parentIdx;
			parentIdx = curIdx / 2;
		}
	}

	void pop(){
		if(size() == 0)
			return;

		// Step-1: swap with last idx element
		swap(v[1], v[v.size()-1]);

		// Step-2: remove last
		v.pop_back();

		// Step-3: 
		heapify(1);		// downwards
	}

	int top(){
		if(size() == 0)
			return -1;
		return v[1];
	}

	int size(){
		return v.size() - 1;
	}

	bool empty(){
		return size() == 0;
	}

};

int main(){
	/*
	Heap minHeap;	// Heap minHeap(true);
	minHeap.push(5);
	minHeap.push(9);
	minHeap.push(7);
	minHeap.push(11);
	minHeap.push(12);
	minHeap.push(8);

	while(minHeap.size()){
		cout<<"Top: "<<minHeap.top()<<endl;
		cout<<"Size: "<<minHeap.size()<<endl;
		cout<<"isEmpty(): "<<(minHeap.empty() ? "Empty" : "Not Empty")<<endl;
		cout<<"Popping..."<<endl;
		minHeap.pop();
	}

	cout<<"Heap is empty now"<<endl;
	cout<<"Top: "<<minHeap.top()<<endl;
	cout<<"Size: "<<minHeap.size()<<endl;
	cout<<"isEmpty(): "<<(minHeap.empty() ? "Empty" : "Not Empty")<<endl;
	*/

	/*
	cout<<"Top: "<<minHeap.top()<<endl;
	cout<<"Size: "<<minHeap.size()<<endl;
	cout<<"isEmpty(): "<<(minHeap.empty() ? "Empty" : "Not Empty")<<endl;


	cout<<"Popping..."<<endl;
	minHeap.pop();

	cout<<"Top: "<<minHeap.top()<<endl;
	cout<<"Size: "<<minHeap.size()<<endl;
	cout<<"isEmpty(): "<<(minHeap.empty() ? "Empty" : "Not Empty")<<endl;

	cout<<"Popping..."<<endl;
	minHeap.pop();

	cout<<"Top: "<<minHeap.top()<<endl;
	cout<<"Size: "<<minHeap.size()<<endl;
	cout<<"isEmpty(): "<<(minHeap.empty() ? "Empty" : "Not Empty")<<endl;
	*/


	Heap maxHeap(false);	
	maxHeap.push(5);
	maxHeap.push(9);
	maxHeap.push(7);
	maxHeap.push(11);
	maxHeap.push(12);
	maxHeap.push(8);

	while(maxHeap.size()){
		cout<<"Top: "<<maxHeap.top()<<endl;
		cout<<"Size: "<<maxHeap.size()<<endl;
		cout<<"isEmpty(): "<<(maxHeap.empty() ? "Empty" : "Not Empty")<<endl;
		cout<<"Popping..."<<endl;
		maxHeap.pop();
	}

	cout<<"Heap is empty now"<<endl;
	cout<<"Top: "<<maxHeap.top()<<endl;
	cout<<"Size: "<<maxHeap.size()<<endl;
	cout<<"isEmpty(): "<<(maxHeap.empty() ? "Empty" : "Not Empty")<<endl;


	return 0;
}