#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> graph[], int u, int v, int bidirectional=true){
	graph[u].push_back(v);
	if(bidirectional)
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

void dfsHelper(vector<int> graph[], int node, vector<bool> &visited){

	cout<<node<<" ";
	visited[node] = true;

	for(int nbr: graph[node]){
		if(!visited[nbr])
			dfsHelper(graph, nbr, visited);
	}

	return;
}

void dfs(vector<int> graph[], int V){

	vector<bool> visited(V, false);

	int src = 0;
	dfsHelper(graph, src, visited);
	cout<<endl;
}

int main(){
	int vertices = 6;
	vector<int> adjList[vertices];

	addEdge(adjList, 0, 1);
	addEdge(adjList, 0, 2);
	addEdge(adjList, 2, 3);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 4, 5);

	

	printGraph(adjList, vertices);

	dfs(adjList, vertices);

	return 0;
}