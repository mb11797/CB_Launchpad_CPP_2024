#include<iostream>
#include<vector>
using namespace std;

class Graph{
private:
	int V;
	vector<pair<int, int> > *arr;
public:
	Graph(int V){
		this->V = V;
		this->arr = new vector<pair<int, int> >[V];
	}

	void addEdge(int u, int v, bool isBidirectionalEdge, int weight){
		this->arr[u].push_back(make_pair(v, weight));
		if(isBidirectionalEdge){
			this->arr[v].push_back(make_pair(u, weight));	// {a, b} => make_pair(a, b)
		}
	}

	void print(){
		cout<<"Graph: "<<endl;
		for(int i=0; i<V; i++){
			cout<<i<<" -> ";
			for(pair<int, int> pr: arr[i]){
				cout<<"("<<pr.first<<", "<<pr.second<<"), ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

};

int main(){

	Graph g(6);
	g.addEdge(0, 1, false, 10);
	g.addEdge(0, 2, false, 20);
	g.addEdge(1, 3, true, 20);
	g.addEdge(1, 4, true, 30);
	g.addEdge(4, 5, false, 10);
	g.addEdge(2, 3, true, 10);

	g.print();

	return 0;
}