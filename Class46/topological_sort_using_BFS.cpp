#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
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

vector<string> topologicalSortUsingBFS(unordered_map<string, vector<string> > graph, int V){
	vector<string> topoSort;

	queue<string> q;
	// unordered_map<string, bool> visitedMap;		// Not Needed
	unordered_map<string, int> indegreeMap;

	// Step 1: Calculated indegree of every node
	for(auto pr: graph){
		string node = pr.first;
		vector<string> nbrs = pr.second;

		if(indegreeMap.find(node) == indegreeMap.end()){
			indegreeMap[node] = 0;
		}

		//visitedMap[node] = false;
		for(string nbr: nbrs){
			if(indegreeMap.find(nbr) == indegreeMap.end()){
				indegreeMap[nbr] = 0;
			}
			indegreeMap[nbr]++;
			//visitedMap[nbr] = false;
		}
	}


	// Step 2: Push all indegree = 0 nodes in queue
	for(pair<string, int> pr: indegreeMap)
		if(pr.second == 0)
			q.push(pr.first);

	// Step 3: Perform BFS
	while(!q.empty()){
		string frontNode = q.front();
		q.pop();

		topoSort.push_back(frontNode);

		// Iterate on neighbour and decrement their respective indegree(s)
		for(string nbr: graph[frontNode]){
			indegreeMap[nbr]--;
			if(indegreeMap[nbr] == 0)
				q.push(nbr);
		}
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

	vector<string> topoSort = topologicalSortUsingBFS(graph, vertices);

	cout<<"Topological Sort"<<endl;
	for(string node: topoSort)
		cout<<node<<" -> ";
	cout<<endl;


	return 0;
}