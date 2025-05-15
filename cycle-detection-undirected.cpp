// Cycle detection using DFS and BFS in Undirected Graph
// ************************************************* C++ **************************************
// DFS
bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    
    visited[u] = true;

    
    for (int v : adj[u])
    {
        
        if (!visited[v])
        {
            if (isCycleUtil(v, adj, visited, u))
                return true;
        }
        
        else if (v != parent)
            return true;
    }

    return false;
}
bool isCycle(int V, vector<vector<int>> &edges)
{
    
    vector<vector<int>> adj(V);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {
            if (isCycleDFS(u, adj, visited, -1))
                return true;
        }
    }

    return false;
}

//BFS 
bool isCycleBFS(vector<vector<int>>& adj, int u, vector<bool>& visited) 
{
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;
        while(!q.empty()) 
        {
            pair<int, int> P = q.front();
            q.pop();
            int node = P.first;
            int parent = P.second;
            for(auto &v : adj[node]) 
            {
                if(visited[v] == false) 
                {
                    visited[v] = true;
                    q.push({v, node});
                } 
                else if(v != parent) 
                {
                    return true;
                }
            }
        }
        return false;
}
bool isCycle(int V, vector<vector<int>>& edges) 
{
        // Code here
        vector<vector<int>> adj(V);
        for(auto &i : edges) 
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++) 
        {
            if(!visited[i]) 
            {
                if(isCycleBFS(adj, i, visited)) 
                {
                    return true;
                }
            }
        }
        return false;
}

// ************************************************ JAVA ************************************************************
// DFS Aproach
class Solution {
    public boolean isCycleDFS(int u, List<List<Integer>> adj, boolean[] visited, int parent) {
        visited[u] = true;
        for(int v : adj.get(u)) {
            if(!visited[v]) {
                if(isCycleDFS(v, adj, visited, u)) return true;
            } else if(v != parent) {
                return true;
            }
        }
        return false;
    }
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        boolean[] visited = new boolean[V];
        for(int u = 0; u < V; u++) {
            if(!visited[u]) {
                if(isCycleDFS(u, adj, visited, -1)) return true;
            }
        }
        return false;
    }
}
// BFS Approach
class Solution {
    public boolean isCycleBFS(List<List<Integer>> adj, int u, boolean[] visited) {
        Queue<int[]>q = new LinkedList<>();
        q.add(new int[]{u , -1});
        visited[u] = true;
        while(!q.isEmpty()) {
            int[] pair = q.poll();
            int node = pair[0];
            int parent = pair[1];
            for(int v : adj.get(node)) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.add(new int[]{v, node});
                } else if(v != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        boolean[] visited = new boolean[V];
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(isCycleBFS(adj, i, visited)) return true;
            }
        }
        return false;
    }
}
