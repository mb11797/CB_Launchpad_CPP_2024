#include<iostream>
#include<vector>
#include<queue>
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

void singleSourceShortestPathUsingBFS(vector<int> graph[], int V, int src){

	vector<int> dist(V, INT_MAX);		// for storing distances of all nodes from src node

	queue<int> q;
	q.push(src);
	dist[src] = 0;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();

		// cout<<"Distance of node "<<frontNode<<" from "<<src<<" = "<<dist[frontNode]<<endl;

		for(int nbr: graph[frontNode]){
			if(dist[nbr] == INT_MAX){
				q.push(nbr);
				dist[nbr] = dist[frontNode] + 1;
			}
		}
	}

	for(int vtx=0; vtx<V; vtx++){
		cout<<"Distance of node "<<vtx<<" from "<<src<<" = "<<dist[vtx]<<endl;
	}
	cout<<endl;

	return;
}

int main(){

	int V = 8;
	vector<int> graph[8];	// adjList

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 6, 7);

	int src = 0;
	singleSourceShortestPathUsingBFS(graph, V, src);

	return 0;
}