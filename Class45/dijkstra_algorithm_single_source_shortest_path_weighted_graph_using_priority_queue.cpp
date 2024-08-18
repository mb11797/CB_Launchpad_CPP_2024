#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<pair<int, int> > graph[], int u, int v, int weight, int bidirectional=true){
	graph[u].push_back(make_pair(v, weight));
	if(bidirectional)
		graph[v].push_back(make_pair(u, weight));
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

class NodeVsWt{
public:
	int node;
	int weight;
	string path;	

	NodeVsWt(int node, int weight, string path){
		this->node = node;
		this->weight = weight;
		this->path = path;
	}
};

class MyComparator{
public:
	bool operator()(NodeVsWt &a, NodeVsWt &b){
		return a.weight > b.weight;
	}
};

void singleSourceShortestPathUsingDIJKSTRA(vector<pair<int, int> > graph[], int V, int src){
	priority_queue<NodeVsWt, vector<NodeVsWt>, MyComparator> minPQ;
	vector<bool> visited(V, false);

	minPQ.push(NodeVsWt(src, 0, "" + to_string(src)));

	while(!minPQ.empty()){
		NodeVsWt topNode = minPQ.top();
		minPQ.pop();

		if(visited[topNode.node])
			continue;

		visited[topNode.node] = true;

		cout<<"Path: "<<topNode.path<<" => Weight = "<<topNode.weight<<endl;

		for(pair<int, int> nbr: graph[topNode.node]){
			if(visited[nbr.first] == false){
				int nbrNode = nbr.first;
				int edgeWt = nbr.second;
				minPQ.push(NodeVsWt(nbrNode, topNode.weight + edgeWt, topNode.path + to_string(nbrNode)));
			}
		}
	}
	return;
}

int main(){

	int V = 8;
	vector<pair<int, int> > graph[8];	// adjList of pair<node, weight>

	addEdge(graph, 0, 1, 10);
	addEdge(graph, 1, 2, 20);
	addEdge(graph, 2, 3, 10);
	addEdge(graph, 0, 3, 50);
	addEdge(graph, 3, 4, 15);
	addEdge(graph, 4, 5, 3);
	addEdge(graph, 4, 6, 1);
	addEdge(graph, 5, 6, 1);

	int src = 0;
	singleSourceShortestPathUsingDIJKSTRA(graph, V, src);

	return 0;
}