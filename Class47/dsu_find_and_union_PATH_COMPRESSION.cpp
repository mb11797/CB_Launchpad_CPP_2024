#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}
	int parentOfX = find(parent, parent[x]);
	cout<<"Path Compression: parent["<<x<<"] changed to "<<parentOfX<<endl;
	return parent[x] = parentOfX;
}

void unionByFind(vector<int> &parent, int u, int v){
	int leaderOfU = find(parent, u);		// O(n)
	cout<<"leaderOf"<<u<<"="<<leaderOfU<<endl;
	int leaderOfV = find(parent, v);		// O(n)
	cout<<"leaderOf"<<v<<"="<<leaderOfV<<endl;
	
	if(leaderOfU != leaderOfV){
		parent[leaderOfV] = leaderOfU;		// O(1)
		cout<<"leaderOf"<<v<<" changed to "<<leaderOfU<<endl;
		leaderOfU = find(parent, u);
		cout<<"leaderOf"<<u<<"="<<leaderOfU<<endl;
		leaderOfV = find(parent, v);
		cout<<"leaderOf"<<v<<"="<<leaderOfV<<endl;
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