#include<iostream>
#include<queue>
using namespace std;


int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout<<"Front: "<<q.front()<<endl;
	cout<<"Size: "<<q.size()<<endl;
	cout<<(q.empty() ? "Queue khali hai" : "Queue khali nhn hai")<<endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	cout<<"Front: "<<q.front()<<endl;
	cout<<"Size: "<<q.size()<<endl;
	cout<<(q.empty() ? "Queue khali hai" : "Queue khali nhn hai")<<endl;


	return 0;
}
