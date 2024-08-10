#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> graph[], int u, int v){
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void printGraph(vector<int> graph[], int nVertices){
	cout<<"Graph: "<<endl;
	for(int i=0; i<nVertices; i++){
		cout<<i<<" -> ";
		for(int el: graph[i]){
			cout<<el<<", ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	vector<int> graph[6];

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 4, 5);

	printGraph(graph, 6);
	
	return 0;
}