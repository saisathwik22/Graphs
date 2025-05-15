// ********************************************** C++ ***********************************************************************************8
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

// ****************************************************** JAVA ************************************************************************
// DFS Approach
class Solution {
    public boolean isCycleDFS(List<List<Integer>> adj, int u, boolean[] visited, boolean[] inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        for(int v : adj.get(u)) {
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            } else if(inRecursion[v]) {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
        }
        boolean[] visited = new boolean[V];
        boolean[] inRecursion = new boolean[V];
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(isCycleDFS(adj, i, visited, inRecursion)) {
                    return true;
                }
            }
        }
        return false;
    }
}

// BFS approach - kahns algo
class Solution {
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
        }
        int[] indegree = new int[V];
        for(int u = 0; u < V; u++) {
            for(int v : adj.get(u)) {
                indegree[v]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        int count = 0;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                count++;
                q.add(i);
            }
        }
        while(!q.isEmpty()) {
            int u = q.poll();
            for(int v : adj.get(u)) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.add(v);
                    count++;
                }
            }
        }
        return count != V;
    }
}
