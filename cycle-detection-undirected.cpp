// Cycle detection using DFS and BFS in Undirected Graph
// ************************************* DFS*****************************88
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

// ***************************************************** BFS ****************************************************************
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
