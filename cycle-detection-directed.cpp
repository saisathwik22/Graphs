// cycle detection in graph using DFS
bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        
        visited[u] = true;
        inRecursion[u] = true;
        for(int &v : adj[u]) {
            
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            } else if(inRecursion[v] == true) {
                return true;
            }
            
        }
        inRecursion[u] = false;
        return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &i : edges) {
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> inRecursion(V, false);
        vector<bool> visited(V, false);
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                if(isCycleDFS(adj, i, visited, inRecursion)) {
                    return true;
                }
            }
        }
        return false;
}

// *************************************** Detect cycle in directed graph - BFS - using Kahn's Algorithm ****************************************************************
// if a graph is cyclic, topoSort is not possible.
bool isCycleDGBFS(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        for(auto &i : edges) {
                adj[i[0]].push_back(i[1]);
        }
        queue<int> q;
        vector<int> indegree(V, 0);
        for(int u = 0; u < V; u++) {
                for(int &v : adj[u]) {
                        indegree[v]++;
                }
        }
        int count = 0;
        for(int i = 0; i < V; i++) {
                if(indegree[i] == 0) {
                        q.push(i);
                        count++;
                }
        }
        while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int &v : adj[u]) {
                        indegree[v]--;
                        if(indegree[v] == 0) {
                                q.push(v);
                                count++;
                        }
                }
        }
        if(count == V) return false;
        else return true;
}
