#include<iostream>
#include<vector>
using namespace std;

class Graph{
private:
	int V;
	vector<int> *arr;
public:
	Graph(int V){
		this->V = V;
		this->arr = new vector<int>[V];
	}

	void addEdge(int u, int v, bool isBidirectionalEdge){
		this->arr[u].push_back(v);
		if(isBidirectionalEdge){
			this->arr[v].push_back(u);
		}
	}

	void print(){
		cout<<"Graph: "<<endl;
		for(int i=0; i<V; i++){
			cout<<i<<" -> ";
			for(int el: arr[i]){
				cout<<el<<", ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

};

int main(){

	Graph g(6);
	g.addEdge(0, 1, false);
	g.addEdge(0, 2, false);
	g.addEdge(1, 3, true);
	g.addEdge(1, 4, true);
	g.addEdge(4, 5, false);
	g.addEdge(2, 3, true);

	g.print();

	return 0;
}