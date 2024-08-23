#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &parent, int x){
	if(parent[x] == x)
		return x;
	return find(parent, parent[x]);
}

void unionByFind(vector<int> &parent, int u, int v){
	int leaderOfU = find(parent, u);		// O(n)
	cout<<"leaderOf"<<u<<"="<<leaderOfU<<endl;
	int leaderOfV = find(parent, v);		// O(n)
	cout<<"leaderOf"<<v<<"="<<leaderOfV<<endl;
	
	if(leaderOfU != leaderOfV){
		parent[leaderOfV] = leaderOfU;		// O(1)
		cout<<"leaderOf"<<v<<" changed to "<<leaderOfU<<endl;
		cout<<"leaderOf"<<u<<"="<<find(parent, u)<<endl;
		cout<<"leaderOf"<<v<<"="<<find(parent, v)<<endl;
	}
	return;
}

int main(){
	vector<vector<int> > edges;
	int nEdges, nVertices;
	cout<<"Input nVertices and nEdges: "<<endl;
	cin>>nVertices>>nEdges;

	vector<int> parent(nVertices+1);

	for(int i=0; i<=nVertices; i++){
		parent[i] = i;
	}

	cout<<"Input the Edges: "<<endl;
	for(int i=0; i<nEdges; i++){
		int u, v;
		cin>>u>>v;
		unionByFind(parent, u, v);		// O(1)
	}	

	cout<<"LeaderOf1: "<<find(parent, 1)<<endl;
	cout<<"LeaderOf4: "<<find(parent, 4)<<endl;

	return 0;
}