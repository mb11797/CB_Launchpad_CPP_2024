#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

void addEdge(unordered_set<int> graph[], int u, int v, int bidirectional=true){
	graph[u].insert(v);
	if(bidirectional)
		graph[v].insert(u);
}

void printGraph(unordered_set<int> graph[], int nVertices){
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

int bfs_sssp(unordered_set<int> graph[], int V, int src, int dest){

	queue<int> q;
	vector<int> dist(V, INT_MAX);
	vector<int> parent(V, -1);

	q.push(src);
	dist[src] = 0;
	parent[src] = src;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();

		for(int nbr: graph[frontNode]){
			if(dist[nbr] == INT_MAX){
				// nbr -> Not visited till now
				q.push(nbr);
				dist[nbr] = dist[frontNode] + 1;
				parent[nbr] = frontNode;
			}
		}
	}

	// Print Path using backtracing parent array:
	int temp = dest;
	while(temp != src){
		cout<<temp<<"<--";
		temp = parent[temp];
	}
	cout<<temp<<endl;

	/*
	// M-2: Print Path
	stack<int> stk;
	int temp = dest;
	while(temp != src){
		// cout<<temp<<"<--";
		stk.push(temp);
		temp = parent[temp];
	}
	stk.push(temp);
	// cout<<temp<<endl;

	while(!stk.empty()){
		cout<<stk.top()<<"-->";
		stk.pop();
	}
	cout<<endl;
	*/

	return dist[dest];
}


int main(){
	int V = 37;
	unordered_set<int> graph[37];		// graph -> adjList

	int board[50] = {0};		// 1-d board (just to store jump value; size = 50 on higher end)

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[17] = -13;
	board[18] = 11;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	// Populate the Graph
	for(int u=0; u<=36; u++){
		// at every cell, throw dice
		for(int dice=1; dice<=6; dice++){
			int v = u + dice + board[u+dice];
			addEdge(graph, u, v, false);
		}
	}

	printGraph(graph, V);

	int minDist = bfs_sssp(graph, V, 1, 36);
	cout<<minDist<<endl;

	return 0;
}