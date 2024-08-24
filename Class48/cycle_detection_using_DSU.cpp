#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &parent, int x){
	if(parent[x] == x)
		return x;
	return parent[x] = find(parent, parent[x]);
}

bool unionByFind(vector<int> &parent, int u, int v){
	int leaderOfU = find(parent, u);
	int leaderOfV = find(parent, v);

	if(leaderOfU != leaderOfV){
		// merge karna hai
		parent[leaderOfV] = leaderOfU;
		return false;
	}
	else{
		return true;
	}
}

bool isCyclicGraph(vector<pair<int, int> > edges, int nVertices){

	vector<int> parent(nVertices+1);

	for(int i=0; i<=nVertices; i++){
		parent[i] = i;
	}

	for(auto edge: edges){
		if(unionByFind(parent, edge.first, edge.second)){
			return true;
		}
	}
	return false;
}

int main(){
	cout<<"Input nVertices and nEdges: "<<endl;
	int nVertices, nEdges;
	cin>>nVertices>>nEdges;

	vector<pair<int, int> > graph_edgeList;

	cout<<"Input the Edges: "<<endl;
	for(int i=0; i<nEdges; i++){
		int u, v;
		cin>>u>>v;
		graph_edgeList.push_back(make_pair(u, v));
	}

	if(isCyclicGraph(graph_edgeList, nVertices)){
		cout<<"Cycle Present hai"<<endl;
	}
	else{
		cout<<"Cycle Present nhn hai"<<endl;
	}

	return 0;
}