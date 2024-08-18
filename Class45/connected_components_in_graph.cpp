class Solution {
public:

    void dfs(vector<vector<int>> graph, int node, vector<bool> &visited){
        visited[node] = true;
        for(int nbr: graph[node]){
            if(!visited[nbr]){
                dfs(graph, nbr, visited);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(vector<int> edge: edges){
            // edge => u -> v
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int components = 0;
        for(int vtx=0; vtx<n; vtx++){
            if(!visited[vtx]){
                dfs(graph, vtx, visited);
                components++;
            }
        }

        return components;
    }
};