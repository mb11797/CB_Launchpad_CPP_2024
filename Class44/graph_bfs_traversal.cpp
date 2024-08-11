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

void bfsHelper(vector<int> graph[], int src, vector<bool> &visited){
	queue<int> q;

	q.push(src);
	visited[src] = true;

	while(!q.empty()){
		// Step-1: pop front front queue
		int frontNode = q.front();
		q.pop();

		// Step-2: print / access the popped node
		cout<<frontNode<<" ";

		// Step-3: insert its not visited neighbours in queue
		for(int nbr: graph[frontNode]){
			if(!visited[nbr]){
				q.push(nbr);
				visited[nbr] = true;
			}
		}
	}
	cout<<endl;
	return;	
}

void bfs(vector<int> graph[], int V){

	vector<bool> visited(V, false);

	int src = 0;
	bfsHelper(graph, src, visited);
}

int main(){
	int V = 6;
	vector<int> graph[V];		// graph -> adjList implementation form

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 4, 5);

	printGraph(graph, V);

	bfs(graph, V);

	return 0;
}

