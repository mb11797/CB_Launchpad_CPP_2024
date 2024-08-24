#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

string src;

void addEdge(unordered_map<string, vector<pair<string, int> > > &graph, string u, string v, int wt, bool isBidirectional=true){
	graph[u].push_back(make_pair(v, wt));
	if(isBidirectional)
		graph[v].push_back(make_pair(u, wt));
}


void printGraph(unordered_map<string, vector<pair<string, int> > > &graph){
	cout<<"Graph: "<<endl;
	for(pair<string, vector<pair<string, int> > > pr: graph){
		cout<<pr.first<<" -> ";
		for(pair<string, int> nbr: pr.second){
			cout<<"("<<nbr.first<<", "<<nbr.second<<"), ";
		}
		cout<<endl;
	}
	cout<<endl;
}




class PrimsTrio{
public:
	string vtx;
	string refVtx;	// referringVertex
	int wt;			// cost

	PrimsTrio(string vtx, string refVtx, int wt){
		this->vtx = vtx;
		this->refVtx = refVtx;
		this->wt = wt;
	}
};

class MyComparator{
public:
	bool operator()(PrimsTrio &a, PrimsTrio &b){
		return a.wt > b.wt;
	}
};

void print_MST_using_Prims_Algo(unordered_map<string, vector<pair<string, int> > > &graph){

	priority_queue<PrimsTrio, vector<PrimsTrio>, MyComparator> minPQ;
	unordered_set<string> visited;

	minPQ.push(PrimsTrio(src, "-1", 0));
	int mstCost = 0;
	while(minPQ.size() > 0){
		PrimsTrio topp = minPQ.top();
		minPQ.pop();

		if(visited.find(topp.vtx) != visited.end()){
			continue;
		}

		if(topp.refVtx != "-1"){
			cout<<topp.vtx<<" visited via "<<topp.refVtx<<" with cost = "<<topp.wt<<endl;
			mstCost += topp.wt;
		}

		visited.insert(topp.vtx);

		for(auto nbr: graph[topp.vtx]){
			// nbr -> pair<string, int> nbr;
			if(visited.find(nbr.first) != visited.end()){
				continue;
			}

			minPQ.push(PrimsTrio(nbr.first, topp.vtx, nbr.second));
		}
	}

	cout<<"Cost of MST: "<<mstCost<<endl;
	return;
}

int main(){
	unordered_map<string, vector<pair<string, int> > > graph;		// adjList -> cityU -> (cityV, wt1), (cityW, wt2)

	addEdge(graph,"Agra","Delhi",10);
    addEdge(graph,"Agra","Lucknow",5);
    addEdge(graph,"Delhi","Hyderabad",30);
    addEdge(graph,"Delhi","Goa",20);
    addEdge(graph,"Lucknow","Goa",30);
    addEdge(graph,"Pune","Lucknow",20);
    addEdge(graph,"Pune","Hyderabad",15);
    addEdge(graph,"Pune","Goa",5);

    printGraph(graph);

    src = "Agra";

    cout<<"Minimum Spanning Tree: "<<endl;
    print_MST_using_Prims_Algo(graph);
    
	return 0;
}