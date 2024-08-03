#include<iostream>
#include<cstudio>
using namespace std;

void printMinPQ_kLargestTillNow(priority_queue<int, vector<int>, greater<int> > minPQ){
	cout<<endl<<"K Largest ELements Till now: ";
	while(minPQ.size() > 0){
		cout<<minPQ.top()<<" ";
		minPQ.pop();
	}

	cout<<endl<<"Enter elements: "<<endl;
}

int main(){
	// Stream : 3 2 1 5 -1 7 4 -1

	cout<<"Enter k: ";
	int k;
	cin>>k;
	cout<<endl;
	cout<<"Enter elements: "<<endl;	
	int no;
	priority_queue<int, vector<int>, greater<int> > minPQ; 

	// scanf -> c
	while(scanf("%d", &no) != EOF){
		if(no == -1){
			// tell the k largest elements till now
			printMinPQ_kLargestTillNow(minPQ);
		}
		else if(minPQ.size() < k){
			minPQ.push(no);
		}
		else{
			// size == k
			if(no > minPQ.top()){
				minPQ.pop();
				minPQ.push(no);
			}
		}
	}


	return 0;
}