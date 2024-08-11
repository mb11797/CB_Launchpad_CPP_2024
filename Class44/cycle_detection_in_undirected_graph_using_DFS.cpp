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

bool checkCycleUsingDFSHelper(vector<int> graph[], int node, int parentNode, vector<bool> &visited){

	visited[node] = true;

	for(int nbr: graph[node]){
		if(!visited[nbr]){
			checkCycleUsingDFSHelper(graph, nbr, node, visited);
		}
		else if(nbr != parentNode){
			// nbr -> visited hai and nbr != parentNode
			return true;
		}
	}

	return false;
}

bool checkCycleUsingDFS(vector<int> graph[], int V){

	vector<bool> visited(V, false);

	for(int vtx=0; vtx<V; vtx++){
		if(!visited[vtx]){
			if(checkCycleUsingDFSHelper(graph, vtx, -1, visited))
				return true;
		}
	}
}

int main(){
	int vertices = 8;
	vector<int> adjList[vertices];

	addEdge(adjList, 0, 1);
	// addEdge(adjList, 0, 2);
	addEdge(adjList, 2, 3);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 4, 5);
	addEdge(adjList, 6, 7);

	printGraph(adjList, vertices);

	if(checkCycleUsingDFS(adjList, vertices))
		cout<<"Cycle Mil Gaya"<<endl;
	else
		cout<<"Cycle Nahin Mila"<<endl;

	return 0;
}