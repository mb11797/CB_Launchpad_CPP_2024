// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	class Edge{
	    public:
	    int u;
	    int v;
	    int wt;
	    
	    Edge(int _u, int _v, int _wt){
	        this->u = _u;
	        this->v = _v;
	        this->wt = _wt;
	    }
	};
	
	static bool myComparator(Edge a, Edge b){
	    return a.wt < b.wt;
	}
	
	int findParent(int u, vector<int> &parent){
	    if(u == parent[u])
    	    return u;
    	return parent[u] = findParent(parent[u], parent);
	}
	
	void unionByRankOfComponents(int u, int v, vector<int> &parent, vector<int> &rank){
	    u = findParent(u, parent);
	    v = findParent(v, parent);
	    
	    if(rank[u] < rank[v]){
	        parent[u] = v;
	    }
	    else if(rank[u] > rank[v]){
	        parent[v] = u;
	    }
	    else{
	        parent[v] = u;
	        rank[u]++;
	    }
	    return;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<Edge> edges;
        for(int v=0; v<V; v++){
            for(vector<int> nbr: adj[v]){
                int curNode = v;
                int nbrNode = nbr[0];
                int wt = nbr[1];
                edges.push_back(Edge(curNode, nbrNode, wt));
            }
        }
        
        sort(edges.begin(), edges.end(), myComparator);
        
        vector<int> parent(V);
        vector<int> rank(V);
        for(int i=0; i<V; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        int cost = 0;
        vector<pair<int, int>> mst;
        
        for(auto edge: edges){
            if(findParent(edge.v, parent) != findParent(edge.u, parent)){
                cost += edge.wt;
                mst.push_back({edge.u, edge.v});
                unionByRankOfComponents(edge.u, edge.v, parent, rank);
            }
        }
        
        // for(pair<int, int> p: mst){
        //     cout<<p.first<<" - "<<p.second<<endl;
        // }
        // cout<<endl;
        
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends