#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

void addEdge(unordered_map<string, vector<string> > &graph, string u, string v, bool bidirectional=false){
	// Edge => u -> v

	graph[u].push_back(v);
	if(bidirectional)
		graph[v].push_back(u);		// for undirected graph
}

void printGraph(unordered_map<string, vector<string> > graph){
	cout<<"Graph:"<<endl;
	for(pair<string, vector<string> > pr: graph){
		string node = pr.first;
		vector<string> nbrs = pr.second;

		cout<<node<<" -> ";
		for(auto nbr: nbrs){
			cout<<nbr<<", ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void printIndegreeMap(unordered_map<string, int> indegreeMap){
	cout<<"Indegree Map:"<<endl;
	for(auto pr: indegreeMap){
		cout<<pr.first<<" : "<<pr.second<<endl;
	}
	cout<<endl;
}

void printVisitedMap(unordered_map<string, bool> visitedMap){
	cout<<"Visited Map:"<<endl;
	for(auto pr: visitedMap){
		cout<<pr.first<<" : "<<pr.second<<endl;
	}
	cout<<endl;
}

void topologicalSortUsingDFSHelper(unordered_map<string, vector<string> > graph, string node, stack<string> &topoSortStk, unordered_map<string, bool> &visitedMap){

	visitedMap[node] = true;

	for(string nbr: graph[node]){
		if(!visitedMap[nbr])
			topologicalSortUsingDFSHelper(graph, nbr, topoSortStk, visitedMap);
	}

	topoSortStk.push(node);
	return;
}

vector<string> topologicalSortUsingDFS(unordered_map<string, vector<string> > graph, int V){
	stack<string> topoSortStk;

	unordered_map<string, bool> visitedMap;

	for(auto pr: graph){
		string node = pr.first;
		vector<string> nbrs = pr.second;

		visitedMap[node] = false;
		for(string nbr: nbrs){
			visitedMap[nbr] = false;
		}
	}

	for(auto pr: graph){
		if(visitedMap[pr.first] == false)
			topologicalSortUsingDFSHelper(graph, pr.first, topoSortStk, visitedMap);
	}

	vector<string> topoSort;

	while(!topoSortStk.empty()){
		topoSort.push_back(topoSortStk.top());
		topoSortStk.pop();
	}

	return topoSort;
}



int main(){
	//vector<string> graph_adjList[7];		// Not useful
	//vector<vector<int>> graph_adjList;	// Not useful
	//vector<vector<string>> graph_adjList;	// Not useful

	unordered_map<string, vector<string> > graph;		// graph -> graph_adjList => directed graph for topoSort

	int vertices = 8;

	addEdge(graph, "Java", "WebApp");
	addEdge(graph, "Python", "WebApp");
	addEdge(graph, "JS", "WebApp");
	addEdge(graph, "HTML", "CSS");
	addEdge(graph, "CSS", "JS");
	addEdge(graph, "DSA", "Python");
	addEdge(graph, "DSA", "Java");
	addEdge(graph, "DSA", "JS");
	addEdge(graph, "DSA", "HTML");
	addEdge(graph, "English", "DSA");
	addEdge(graph, "English", "HTML");

	printGraph(graph);

	vector<string> topoSort = topologicalSortUsingDFS(graph, vertices);

	cout<<"Topological Sort"<<endl;
	for(string node: topoSort)
		cout<<node<<" -> ";
	cout<<endl;


	return 0;
}