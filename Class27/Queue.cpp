#include<iostream>
using namespace std;

template<typename T>
class Queue{
private:
	T*arr;
	int curSize;
	int maxSize;
	int front;
	int rear;

public:
	Queue(int maxSize = 4){
		this->curSize = 0;
		this->maxSize = maxSize;
		this->arr = new T(maxSize);
		this->front = 0;
		this->rear = maxSize - 1;
	}

	void push(T elmt){
		if(this->curSize >= this->maxSize){
			cout<<"Queue is already full. "<<elmt<<" not inserted"<<endl;
			return;
		}

		this->rear = (this->rear + 1) % this->maxSize;
		arr[this->rear] = elmt;
		this->curSize++;
		return;
	}

	T pop(){
		if(this->curSize <= 0){
			cout<<"Queue is already empty"<<endl;
			return NULL;
		}

		T poppedElmt = this->arr[this->front];
		this->front = (this->front + 1) % this->maxSize;
		this->curSize--;
		return poppedElmt;
	}

	T getFront(){
		if(this->curSize <= 0){
			cout<<"Queue is already empty"<<endl;
			return NULL;
		}

		return this->arr[this->front];
	}

	int size(){
		return this->curSize;
	}

	bool isEmpty(){
		return this->curSize == 0;
	}

	bool isFull(){
		return this->curSize == this->maxSize;
	}
};


int main(){

	Queue<int> q(6);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout<<"Front: "<<q.getFront()<<endl;
	cout<<"Size: "<<q.size()<<endl;
	cout<<q.pop()<<" is popped"<<endl;
	cout<<q.pop()<<" is popped"<<endl;

	cout<<"Front: "<<q.getFront()<<endl;
	cout<<(q.isEmpty() ? "Queue khali hai" : "Queue khali nhn hai")<<endl;
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(10);

	cout<<(q.isFull() ? "Queue bhar gayi hai" : "Queue me space hai")<<endl;


	return 0;
}
