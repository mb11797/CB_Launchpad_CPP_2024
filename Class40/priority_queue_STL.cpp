#include<iostream>
#include<queue>
using namespace std;

int main(){
	priority_queue<int> maxPQ;

	maxPQ.push(8);
	maxPQ.push(12);
	maxPQ.push(14);
	maxPQ.push(9);
	maxPQ.push(1);

	cout<<"Max Priority QueueO Order of Elements: ";
	while(!maxPQ.empty()){
		cout<<maxPQ.top()<<" ";
		maxPQ.pop();
	}
	cout<<endl;


	priority_queue<int, vector<int>, greater<int> > minPQ;

	minPQ.push(8);
	minPQ.push(12);
	minPQ.push(14);
	minPQ.push(9);
	minPQ.push(1);

	cout<<"Min Priority QueueO Order of Elements: ";
	while(minPQ.size() > 0){
		cout<<minPQ.top()<<" ";
		minPQ.pop();
	}
	cout<<endl;

	return 0;
}