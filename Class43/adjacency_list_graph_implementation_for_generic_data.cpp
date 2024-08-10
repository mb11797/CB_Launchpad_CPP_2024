#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

template<typename T>
class Graph{
private:
	int V;
	unordered_map<T, vector<T> > graph;

public:

	Graph(int V){
		this->V = V;
		graph = unordered_map<T, vector<T> >();
	}

	void addEdge(T u, T v, bool isBidirectional = true){
		graph[u].push_back(v);
		if(isBidirectional){
			graph[v].push_back(u);
		}
	}

	void print(){
		// Print the map
		cout<<"Graph: "<<endl;
		for(pair<T, vector<T> > pr: graph){
			cout<<pr.first<<" -> ";
			vector<T> nbrsList = pr.second;
			for(T nbr: nbrsList){
				cout<<nbr<<", ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

};

int main(){

	Graph<string> graph(9);

	graph.addEdge("Kartik", "Ritik");
	graph.addEdge("Kartik", "Vansh");
	graph.addEdge("Anshum", "Vansh");
	graph.addEdge("Vedant", "Yajnesh");
	graph.addEdge("Yajnesh", "Manika");
	graph.addEdge("Manika", "Radhika");
	graph.addEdge("Manika", "Khushi");
	graph.addEdge("Bhuvan", "Khushi");

	graph.print();

	return 0;
}