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

bool checkCycleInDirectedGraphHelper(vector<int> graph[], int node, vector<bool> &visited, vector<bool> &currentPathAncestorNodes){

	visited[node] = true;
	currentPathAncestorNodes[node] = true;

	for(int nbr: graph[node]){
		if(!visited[nbr]){
			bool nbrParCycleMili = checkCycleInDirectedGraphHelper(graph, nbr, visited, currentPathAncestorNodes);
			if(nbrParCycleMili)
				return true;
		}
		else if(currentPathAncestorNodes[nbr] == true){
			// this nbr has been visited in the current path only -> Means Cycle hai
			return true;
		}
	}

	currentPathAncestorNodes[node] = false;

	return false;
}

bool checkCycleInDirectedGraph(vector<int> graph[], int V){

	vector<bool> visited(V, false);
	vector<bool> currentPathAncestorNodes(V, false);

	return checkCycleInDirectedGraphHelper(graph, 0, visited, currentPathAncestorNodes);
}

int main(){
	int vertices = 7;
	vector<int> graph[vertices];

	addEdge(graph, 0, 1, false);
	addEdge(graph, 1, 2, false);
	addEdge(graph, 2, 3, false);	
	addEdge(graph, 3, 4, false);
	addEdge(graph, 1, 4, false);
	addEdge(graph, 4, 5, false);
	addEdge(graph, 5, 6, false);


	// cycle wali edge
	addEdge(graph, 4, 2, false);


	printGraph(graph, vertices);

	if(checkCycleInDirectedGraph(graph, vertices))
		cout<<"Cycle Mil Gaya"<<endl;
	else
		cout<<"Cycle Nahin Mila"<<endl;

	return 0;
}